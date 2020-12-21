#include<bits/stdc++.h>
using namespace std;

long long power2(int n) {
    long long ans = 1;
    while(n) {
        ans *= 2;
        n--;
        ans %= 1000000007;
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    cout<<power2(n);
    return 0;
}