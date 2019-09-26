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

unsigned long extended_gcd(unsigned long a, unsigned long b, int* u, int* v) {

    if (b == 0) {
        *u = 0;
        *v = 1;
        return a;
    }

    int u1, v1;
    unsigned long r = extended_gcd(b, ldiv(a, b).rem, &u1, &v1);

    *u = v1 - (a / b) * u1;
    *v = u1;

    return r;
}

unsigned long solve(int N) {
    unsigned long res = 1;

    for(int i = 2; i <= N; ++i) {
        int u, v;
        //printf("pgcd: %ld\n",  extended_gcd(res, i, &u, &v));
        res = (i * res / extended_gcd(res, i, &u, &v));
        //printf("res: %ld\n", res);
    }

    return res;
}


int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n=0;
        fastscan(&n);
        unsigned long res = solve(n);
        printf("%ld\n", res);
    }
    return 0;
}
