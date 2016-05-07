#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int do_cycles(int n) {
    int h = 0;
    
    for(int i = 0; i <= n; i++) {
        h = (i % 2) == 1 ? h * 2 : h + 1;
		printf("%d\n", h);
    }
    
    return h;
}

int main(){
    int t;
    int* out;
    cin >> t;
    
    out = (int*)malloc(sizeof(out) * t);
    
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        out[a0] = do_cycles(n);
    }
    
    for(int a0 = 0; a0 < t; a0++){
        printf("%d\n", out[a0]);
    }
    
    free(out);
    
    return 0;
}
