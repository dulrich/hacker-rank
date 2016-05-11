#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define DIGITS 1000000

typedef unsigned char bignum[DIGITS];

void add(bignum *a, bignum *b, bignum *dest) {
	unsigned char carry = 0;
	
	for(int i = 0; i < DIGITS; i++) {
		(*dest)[i] = (*a)[i] + (*b)[i] + carry;;
		carry = (*dest)[i] / 10;
		(*dest)[i] = (*dest)[i] % 10;
	}
}

int mult(bignum *a, bignum *b, bignum *dest) {
	unsigned char carry = 0;
	int first_a = 0;
	int first_b = 0;
	for(int i = DIGITS - 1; i >0; i--) {
		if (first_a == 0 && (*a)[i] != 0) first_a = i;
		if (first_b == 0 && (*b)[i] != 0) first_b = i;
	}
	
	int i, j;
	for(i = 0; i <= first_a; i++) {
		for(j = 0; j <= first_b; j++) {
			if (i + j >= DIGITS) {
				return 1;
			}
			
			(*dest)[i + j] = (*dest)[i + j] + (*a)[i] * (*b)[j] + carry;;
			carry = (*dest)[i + j] / 10;
			(*dest)[i + j] = (*dest)[i + j] % 10;
		}
		if (i + j + 1 >= DIGITS) {
			return 1;
		}
		(*dest)[i + j] = (*dest)[i + j + 1] + carry;
		carry = 0;
	}
	
	return 0;
}

void print_bignum(bignum *n) {
	bool start = false;
	int pos = 0;
	char s[DIGITS + 1];
	memset(s, 0, DIGITS + 1);
	
	for(int i = DIGITS - 1; i >= 0; i--) {
		if (((*n)[i] != 0) || (i == 0)) start = true;
		
		if (start) {
			s[pos] = '0' + (*n)[i];
			pos++;
		}
	}
	
	printf("%s", s);
}

void set(bignum *a, bignum *dest) {
	for(int i = 0; i < DIGITS; i++) {
		(*dest)[i] = (*a)[i];
	}
}

void zero(bignum *n) {
	for(int i = 0; i < DIGITS; i++) {
		(*n)[i] = 0;
	}
}

void uint_to_bignum(bignum * a, unsigned int n) {
	int i = 0;
	
	do {
		(*a)[i] = (n % 10);
		i++;
	} while ((n = n / 10) > 0);
}


int main() {
	unsigned int a, b, n;
	cin >> a;
	cin >> b;
	cin >> n;

	bignum tn0, tn1, tn2, tmp;
	
	zero(&tn0);
	zero(&tn1);
	zero(&tn2);
	
	uint_to_bignum(&tn1, a);
	uint_to_bignum(&tn2, b);

	for(int i = 0; i < n - 2; i++) {
		set(&tn1, &tn0);
		set(&tn2, &tn1);
		
		zero(&tmp);
		if (mult(&tn1, &tn1, &tmp)) {
			printf("overflow\n");
			return 1;
		}
		
		zero(&tn2);
		add(&tmp, &tn0, &tn2);
	}
	
	print_bignum(&tn2);
	printf("\n");
	
	return 0;
}