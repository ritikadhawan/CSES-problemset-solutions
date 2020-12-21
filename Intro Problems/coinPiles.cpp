#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        long long a, b;
        cin>>a>>b;
        float div = (a != 0 && b != 0) ? max((float)a/b, (float)b/a) : 0;
        if((a+b)%3 == 0 && a!=0 && b!=0 && div >= 1 && div <= 2) {
            cout<<"YES"<<endl;
        } else {
            if(a == 0 && b == 0) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
}