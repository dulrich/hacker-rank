#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
int lonelyinteger(int a_size, int* a) {
    int lonely = 0;
    int counts[101];
    memset(counts, 0, 101 * sizeof(int));
    
    int i;
    for(i = 0; i < 101; i++) {
        // printf("setting %d\n", a[i]);
        printf("%d: %d..", i, counts[i]);
    }
    for(i = 0; i < a_size; i++) {
        // printf("setting %d\n", a[i]);
        counts[a[i]]++;
    }
    
    for(i = 0; i < 101; i++) {
        // printf("%d..", i);
        if (counts[i] % 2) {
            lonely = i;
            break;
        }
    }
    
    return lonely;
}
int main() {
    int res;
    
    int _a_size, _a_i;
    scanf("%d", &_a_size);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) {
        int _a_item;
        scanf("%d", &_a_item);
        
        _a[_a_i] = _a_item;
    }
    
    res = lonelyinteger(_a_size, _a);
    printf("%d", res);
    
    return 0;
}
