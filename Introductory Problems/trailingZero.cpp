#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;
    long long noOfZeros = 0;
    long long denominator = 5;
    while(denominator <= n) {
        noOfZeros += (n / denominator);
        denominator *= 5;
    }
    cout<<noOfZeros;
    return 0;
}