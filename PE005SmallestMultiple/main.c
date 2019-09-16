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

int extended_gcd(int a, int b, int* u, int* v) {

    if (b == 0) {
        *u = 0;
        *v = 1;
        return a;
    }

    int u1, v1;
    int r = extended_gcd(b, a % b, &u1, &v1);

    *u = v1 - (a / b) * u1;
    *v = u1;

    return r;
}

int solve(int N) {
    int res = 1;

    for(int i = 2; i <= N; ++i) {
        int u, v;
        res = (abs(i * res) / extended_gcd(res, i, &u, &v));
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
        int res = solve(n);
        printf("%d\n", res);
    }
    return 0;
}
