#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin>>n>>q;
    vector<long long> input(n);
    for(int i=0; i<n; i++) {
        cin>>input[i];
    }

    vector<long long> sum(n+1, 0);
    long long currSum = 0;
    for(int i=1; i<=n; i++) {
        currSum += input[i-1];
        sum[i] = currSum;
    }

    while(q--) {
        int a, b;
        cin>>a>>b;
        cout<<sum[b] - sum[a-1]<<endl;
    }
    return 0;
}