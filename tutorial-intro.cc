#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, v;
    cin >> v;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int c;
        
        cin >> c;
        
        if (c == v) {
            printf("%d\n", i);
            break;
        }
    }
    
    return 0;
}
