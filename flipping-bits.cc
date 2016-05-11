#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int t;
	cin >> t;

	unsigned int tmp;

	for(int i = 0; i < t; i++) {
		cin >> tmp;
		printf("%u\n", ~tmp);
	}

	return 0;
}
