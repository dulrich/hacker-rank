#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    
    unsigned int *ints;
    ints = (unsigned int*)malloc(sizeof(ints) * t);
    
    for(int i = 0; i < t; i++) {
        cin >> ints[i];
    }
    
    for(int i = 0; i < t; i++) {
        printf("%u\n", ~ints[i]);
    }
    
    free(ints);
    
    return 0;
}
