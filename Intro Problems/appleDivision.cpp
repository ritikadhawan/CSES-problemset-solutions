#include<bits/stdc++.h>
using namespace std;

long long minDifference(int curr, vector<long long>&apples, long long grp1, long long grp2) {
    if(curr == apples.size()) {
        return abs(grp1 - grp2);
    }

    //put in grp1
    long long ans1 = minDifference(curr+1, apples, grp1+apples[curr], grp2);

    //put in grp2
    long long ans2 = minDifference(curr+1, apples, grp1, grp2+apples[curr]);

    return min(ans1, ans2);
}
int main() {
    int n;
    cin>>n;
    vector<long long> p(n);
    for(int i=0; i<n; i++) {
        cin>>p[i];
    }

    cout<<minDifference(0, p, 0, 0);
    return 0;
}