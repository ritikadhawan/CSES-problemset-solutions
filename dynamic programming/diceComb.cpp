#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=6 && j<=i; j++) {
            dp[i] += dp[i-j];
            dp[i] %= 1000000007;
        }
    }

    cout<<dp[n]%1000000007;
    return 0;
}