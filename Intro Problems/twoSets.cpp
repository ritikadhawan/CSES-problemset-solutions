#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> part1, part2;
    long long sum1 = 0, sum2 = 0;
    for(int i=n; i>=1; i--) {
        if(sum1 < sum2) {
            sum1 += i;
            part1.push_back(i);
        } else {
            sum2 += i;
            part2.push_back(i);
        }
    }
    if(sum1 == sum2) {
        cout<<"YES\n";
        cout<<part1.size()<<endl;
        for(int i=part1.size()-1; i>=0; i--) {
            cout<<part1[i]<<" ";
        }
        cout<<"\n"<<part2.size()<<endl;
        for(int i=part2.size()-1; i>=0; i--) {
            cout<<part2[i]<<" ";
        }
    } else {
        cout<<"NO";
    }
    return 0;
}