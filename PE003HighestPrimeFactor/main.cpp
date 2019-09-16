#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "input.hpp"

#define wl(n) while(n--)
#define min(a,b) a < b ? a : b
#define max(a,b) a < b ? b : a
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

class Solution {
public:
    static unsigned long solve(unsigned long N) {
        auto res = N;

        while(!(res & 1) && res > 1) {
            res /= 2;
        }

        if(res == 1) {
            return 2;
        }

        unsigned long i = 3;
        printf("%lf\n", sqrt(res));
        for(; i <= sqrt(res) ; i += 2) {
            //printf("i: %d\n", i);
            while(!(res % i)) {
                res /= i;
            }
        }
        printf("out i: %d\n", i);

        if(res > 2) {
            return res;
        }
        return i - 2;
    }

};

static inline void fastscan_long(unsigned long& number) {
    //variable to indicate sign of input number
    bool negative = false;
    int c;

    number = 0;

    // extract current character from buffer
    c = getchar_unlocked();

    if (c=='-')
        {
            // number is negative
            negative = true;

            // extract the next character from the buffer
            c = getchar_unlocked();
        }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
};


int main()
{
    int t;
    fastscan(t);

    wl(t)
    {
        unsigned long n=0;
        fastscan_long(n);
        printf("n: %lu\n", n);
        auto res = Solution::solve(n);

        printf("%ld\n", res);
    }

    return 0;
}
