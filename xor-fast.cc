#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    
    int i, j, n;
    int out, tmp;
    for(i = 0; i < t; i++) {
        cin >> n;
        out = 0;

        if (n % 2 == 0) {
            printf("0\n");
            continue;
        }
        
        for(j = 0; j < n; j++) {
            cin >> tmp;
            
            if (j % 2 == 0) {
                out = out ^ tmp;
            }
        }
        
        printf("%d\n", out);
    }
    
    return 0;
}
