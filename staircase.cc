#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    char* out;
    cin >> n;
    
	out = (char*)malloc(sizeof(out) * (n + 1));
	out[n] = '\0';
	
	for(int i = 0; i < n; i++) {
		out[i] = ' ';
	}
	
    for(int i = n - 1; i >=0; i--) {
        out[i] = '#';
        printf("%s\n", out);
    }
    
	free(out);
	
    return 0;
}
