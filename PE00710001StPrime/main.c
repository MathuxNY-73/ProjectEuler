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

bool isPrime(unsigned long n) {
    if(!(n & 1)) {
        return false;
    }
    else if(n % 3 == 0) {
        return false;
    }
    int step = 4;
    unsigned long root = sqrtl(n) + 1;
    for(unsigned long i = 5 ; i < root ; step = 6 - step, i += step) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

unsigned long solve(int N) {
    int count = 2;
    unsigned long i;
    if(N < 2) {
        return 2;
    }
    else if (N == 2) {
        return 3;
    }

    for(i = 5 ; count < N ; ++i) {
        if(isPrime(i)) {
            ++count;
        }
    }

    return i - 1;
}


int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n=0;
        fastscan(&n);
        unsigned long res = solve(n);

        printf("%lu\n", res);
    }
    return 0;
}
