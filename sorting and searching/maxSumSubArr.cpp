#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long long> input(n);
    for(int i=0; i<n; i++) {
        cin>>input[i];
    }

    long long maxSum = LONG_MIN, currSum = 0;
    for(int i=0; i<n; i++) {
        currSum += input[i];
        maxSum = max(currSum, maxSum);

        if(currSum < 0) {
            currSum = 0;
        }
    }
    cout<<maxSum;
    return 0;
}