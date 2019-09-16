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

#define wl(n) while(n--)
#define min(a,b) a < b ? a : b
#define max(a,b) a < b ? b : a
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

static const auto ____ = []() {
                             ios::sync_with_stdio(false);
                             cin.tie(nullptr);
                             cout.tie(nullptr);
                             return nullptr;

                         }();

bool is_palindrome(long num) {
    std::string numString, numStringReverse;
    numString = std::to_string(num);
    std::string::iterator it = numString.begin();
    std::string::reverse_iterator itReverse = numString.rbegin();
    while(it != numString.end()) {
        if(*it != *itReverse)
            return false;
        it++;
        itReverse++;
    }
    return true;
}

int main() {
    unsigned long N, max = 0, result = 0;
    int T, count = 0;
    unsigned long *palTab = new unsigned long [1000000 - 101101 + 1];

    for(int i = 999 ; i >= 100 ; i--){
        for(int j = i ; j >= 100 ; j--) {
            if((unsigned long)i*j > 1000000)
                continue;
            else if (is_palindrome(i*j)) {
                palTab[count] = i*j;
                count++;
            }
        }
    }

    cin>>T;
    for(int u = 0; u<T ; u++) {
        cin>>N;
        unsigned long max = 0;
        for(int i = 0 ; i < count ; i++) {
            if(palTab[i] < N && palTab[i] > max) {
                max = palTab[i];
            }
        }
        cout << max << endl;
    }

    delete[] palTab;
    return 0;
}
