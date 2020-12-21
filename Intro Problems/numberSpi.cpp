#include<bits/stdc++.h>
using namespace std;
long long sumOfOdd(long long n) {
    return n*n;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        long long x, y;
        cin>>x>>y;
        long long ans = 0;
        if(x > y) {
            ans += sumOfOdd(x-1);
            if(x%2 == 0) {
                ans += (2*x - y);
            } else {
                ans += y;
            }
        } else {
            ans += sumOfOdd(y-1);
            if(y%2 == 0) {
                ans += x;
            } else {
                ans += (2*y - x);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}