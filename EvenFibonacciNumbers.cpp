#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned long long tmp,prev1=1, prev2=0;
    unsigned long long sum =0;
    unsigned long int T,N;
    cin>>T;
    for (int i=0; i<T;i++) {
        cin>>N;
        sum =0; prev1=1; prev2=0;
        while(prev1 < N) {
            tmp = prev1;
            prev1 += prev2;
            prev2 = tmp;
            if(prev1 %2 == 0 && prev1 <=N ) {
                sum += prev1;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
