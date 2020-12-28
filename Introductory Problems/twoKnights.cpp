#include<bits/stdc++.h>
using namespace std;

long long nC2(long long n) {
    long long ans = (n*(n-1))/2;
    return ans;
}
int main() {
    long long n;
    cin>>n;
    vector<long long> values(4, 0);
    values[2] = 6;
    values[3] = 28;
    for(int i=1; i <= 3 && i <= n; i++) {
        cout<<values[i]<<endl;
    }
    for(long long i=4; i<=n; i++) {
        long long subt = (10 + (4*(i-4))) * (i-2);
        subt += (4 + (2*(i-4)));
        long long ans = nC2(i*i);
        ans -= subt;
        cout<<ans<<endl;
    }
    return 0;
}