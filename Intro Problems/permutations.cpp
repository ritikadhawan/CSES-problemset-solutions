#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    if(n == 2 || n == 3) {
        cout<<"NO SOLUTION"<<endl;
    } else {
        int evenVal = n/2 + 1;
        int oddVal = 1;
        for(int i=0; i<n; i++) {
            if(i % 2 == 0) {
                cout<<evenVal++<<" ";
            } else {
                cout<<oddVal++<<" ";
            }
        }
    }
    return 0;
}