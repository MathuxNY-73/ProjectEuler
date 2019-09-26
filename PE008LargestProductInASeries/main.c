#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#include "input.h"

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)
#define min(a,b) a<=b?a:b
#define SIZE 13

short WINDOW[SIZE];

int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n=0, k = 0;
        fastscan(&n);
        fastscan(&k);

        memset(WINDOW, 0, sizeof(short) * SIZE);

        unsigned long product = 1UL, max_prod = 0UL;
        int h = 0;
        bool w_filled = false;
        for(int i = 0, c = getchar_unlocked() ; (c > 47 && c < 58) && i < n ; ++i, c = getchar_unlocked()) {
            short d = c - 48;
            //printf("%d",d);
            if(d == 0) {
                h = 0;
                w_filled = false;
                product = 1UL;
                memset(WINDOW, 0, sizeof(short) * SIZE);
            }
            else {
                if(w_filled && WINDOW[h] != 0) {
                    product /= (unsigned long)WINDOW[h];
                }
                WINDOW[h++] = d;
                //for(int j = 0 ; j < k ; ++j) {
                //    printf("%d ", WINDOW[j]);
                //}
                //printf("product: %d, c: %d\n", product, d);
                if(h == k) {
                    h = 0;
                    w_filled = true;
                }
                product *= (unsigned long)d;
                //printf(" = %d\n", product);
                max_prod = w_filled && product > max_prod ? product : max_prod;
            }
        }
        //printf("\n");
        printf("%ld\n", max_prod);
    }
    return 0;
}
