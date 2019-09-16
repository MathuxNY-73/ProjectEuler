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

unsigned long solve_subtle(int N) {
    long res_s = 0;
    long s_res = 0;

    s_res = (long)N * ((long)N + 1L) / 2L;
    res_s = (s_res * (2L * (long)N + 1L)) / 3L;

    unsigned long res = labs(powl(s_res, 2) - res_s);

    return res;
}

unsigned long solve(int N) {
    unsigned long res_s = 0;
    unsigned long s_res = 0;

    for(int i = 1; i <= N; ++i) {
        res_s += (unsigned long)pow(i, 2);
        s_res += i;
    }

    unsigned long res = fabsl(powl(s_res, 2) - res_s);

    return res;
}


int main()
{
    int t;
    fastscan(&t);

    wl(t) {
        int n=0;
        fastscan(&n);
        unsigned long res = solve_subtle(n);

        printf("%lu\n", res);
    }
    return 0;
}
