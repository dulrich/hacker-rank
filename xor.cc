#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int xor_subarrays(int *a, int l) {
    int out = 0;
    
    int i, j, k;
    for(i = 0; i < l; i++) {
        for(j = 0; j < l - i; j++) {
            for(k = 0; i + k < l - j; k++) {
                out = out ^ a[i + k];
            }
        }
    }

    return out;
}

int main() {
    int t;
    cin >> t;
    
    int *a, i, j, l;
    for(i = 0; i < t; i++) {
        cin >> l;
        a = (int*)malloc(sizeof(a) * l);
        
        for(j = 0; j < l; j++) {
            cin >> a[j];
        }
        
        printf("%d\n", xor_subarrays(a, l));
        
        free(a);
    }
    
    return 0;
}
