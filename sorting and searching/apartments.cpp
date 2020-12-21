#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, k;
    cin>>n>>m>>k;
    vector<long long> a(n);
    vector<long long> b(m);

    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    for(int i=0; i<m; i++) {
        cin>>b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i=0, j=0;
    int count = 0;
    while(i < n && j < m) {
        //find apartment for ith person 
        auto lb = lower_bound(b.begin() + j, b.end(), a[i]-k);
        if(lb == b.end()) {
            break;
        }
        if(*lb > a[i] + k) {
            i++;
        } else {
            count++;
            i++;
            j = lb - b.begin() + 1;
        }
    }
    cout<<count;
    return 0;
}