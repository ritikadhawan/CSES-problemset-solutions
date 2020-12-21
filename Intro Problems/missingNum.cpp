#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    unordered_set<int> values;
    for(int i=0; i<n-1; i++) {
        int input;
        cin>>input;
        values.insert(input);
    }

    for(int i=1; i<=n; i++) {
        if(values.count(i) == 0) {
            cout<<i;
            break;
        }
    }
    return 0;
}