#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
	int* out;
	
	out = (int*)malloc(sizeof(out) * t);
	
    for(int a0 = 0; a0 < t; a0++){
        int c, i, n;
        int divcount = 0;
        cin >> n;
        
        c = n;
        do {
            i = c % 10;
            
            if ((i != 0) &&(n % i) == 0) {
				printf("%d %d\n", i, c);
                divcount++;
            }
            
            c = c / 10;
        } while (c > 0);
        
        out[a0] = divcount;
    }
	
	for(int a0 = 0; a0 < t; a0++) {
		printf("%d\n", out[a0]);
	}
	
	free(out);
	
    return 0;
}
