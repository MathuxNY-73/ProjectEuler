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

// Limit was found using the following formula n*(log(n) + log(log(n))) + 3 = 1395658
// 2*(1395658/6) + 31 >> 5 = 14540
int SIEVE[14540];

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

unsigned long solve_sieve(int n) {
    if(n < 2) {
        return 2;
    }
    else if (n == 2){
        return 3;
    }
    else if (n == 3) {
        return 5;
    }
    else {
        int i = 0, count = 2;
        for(i = 0 ; count < n ; ++i) {
            count += __builtin_popcount(~SIEVE[i]);
        }
        --i;
        int mask = ~SIEVE[i];
        int p;
        for(p = 31; count >= n; --p) {
            count -= (mask >> p) & 1;
        }
        return 3*(p+(i<<5))+7+(p&1);
    }
}

void compute_primes() {
    memset(SIEVE, 0, sizeof(SIEVE));

    int root = 2*(1182/6) - 1;
    int limit = 2*(1395658/6);

    for(int i = 0 ; i < root ; ++i) {
        if((SIEVE[i >> 5] & (1 << (i&31))) == 0) {
            int start = 0, s1 = 0, s2 = 0;
            if(i & 1) {
                start = i * (3*i + 8) + 4;
                s1 = 4 * i + 5;
                s2 = 2 * i + 3;
            }
            else {
                start = i * (3 * i + 10) + 7;
                s1 = 2 * i + 3;
                s2 = 4 * i + 7;
            }

            for(int j = start ; j < limit ; j += s2) {
                SIEVE[j >> 5] |= (1 << (j&31));
                j += s1;
                if(j >= limit) {
                    break;
                }
                SIEVE[j >> 5] |= (1 << (j&31));
            }
        }
    }
}


int main()
{
    compute_primes();
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
