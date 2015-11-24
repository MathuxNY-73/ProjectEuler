#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned long int sum_f(unsigned long int m) {
    return m*(m+1)/2;
}

int main() {
    long int T,N;
    cin>>T;
    for(int i=0;i<T;i++) {
        cin>>N;
        --N;
        unsigned long int sum = (3*sum_f(N/3) + 5*sum_f(N/5) -15*sum_f(N/15));
        cout<<sum<<"\n";
    }
    return 0;
}
