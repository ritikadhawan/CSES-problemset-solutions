#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin>>n>>x;

    vector<long long> p(n);
    for(int i=0; i<n; i++) {
        cin>>p[i];
    }

    sort(p.begin(), p.end());
    long long count = 0;
    int i=0, j=n-1;

    while(i < j) {
        if(p[i] + p[j] <= x) {
            i++; j--;
            count++;
        } else {
            j--;
            count++;
        }
    }
    count += (i == j) ? 1 : 0;
    cout<<count;
    return 0;
}