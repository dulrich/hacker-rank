#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void print_arr(vector <int> ar) {
    for(int i = 0; i < ar.size(); i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

void insertionSort(vector <int>  ar) {
    int e, l, shift;
    l = ar.size();
    e = ar[l - 1];
    shift = 0;

    if (l < 2) return;
    
    for(int i = l - 2; i >= 0; i--) {
        if (ar[i] > e) {
            ar[i + 1] = ar[i];
			print_arr(ar);
			if (i == 0) {
				ar[i] = e;
				print_arr(ar);
			}
			shift = 1;
        }
        else if (shift) {
            ar[i + 1] = e;
            print_arr(ar);
            shift = 0;
        }
		else {
			shift = 0;
		}
    }
}
int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

    insertionSort(_ar);
    return 0;
}
