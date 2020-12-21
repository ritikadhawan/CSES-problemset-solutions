#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    cin>>n;
    
    long long count = 0;
    vector<long long> input(n);
    for(int i=0; i<n; i++) {
        cin>>input[i]; 
    }

    sort(input.begin(), input.end());

    long long currNo = input[0];
    auto currStart = input.begin();
    auto lb = lower_bound(input.begin(), input.end(), currNo);
    while(lb != input.end()) {
        currNo = *lb;
        lb = lower_bound(lb, input.end(), currNo+1);
        count++;
    }
    cout<<count;
    return 0;
}