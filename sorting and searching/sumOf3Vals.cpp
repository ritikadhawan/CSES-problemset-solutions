#include<bits/stdc++.h>
using namespace std;

#define ll long long

pair<int, int> pairSum(vector<pair<ll, int>>&input, int s, int n, ll x) {
    int i = s, j = n-1;
    while(i < j) {
        if(input[i].first + input[j].first == x) {
            return {input[i].second, input[j].second};
        } else if(input[i].first + input[j].first > x) {
            j--;
        } else {
            i++;
        }
    }
    return {-1, -1};
}
int main() {
    int n;
    ll x;
    cin>>n>>x;

    vector<pair<ll, int>> input(n);
    for(int i = 0; i < n; i++) {
        cin>>input[i].first;
        input[i].second = i + 1;
    }

    sort(input.begin(), input.end());
    for(int i = 0; i < n; i++) {
        if(input[i].first <= x) {
            pair<int, int> p = pairSum(input, i+1, n, x - input[i].first);
            if(p.first != -1 && p.second != -1) {
                cout<<input[i].second<<" "<<p.first<<" "<<p.second<<endl;
                return 0;
            }
        }

    }
    cout<<"IMPOSSIBLE";
    return 0;
}