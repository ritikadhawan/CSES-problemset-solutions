#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long long> input(n);
    for(int i=0; i<n; i++) {
        cin>>input[i];
    }
    sort(input.begin(), input.end());
    long long mid = input[n/2];
    long long val = 0;
    for(int i=0; i<n; i++) {
        val += abs(input[i] - mid);
    }
    cout<<val;
    return 0;

}