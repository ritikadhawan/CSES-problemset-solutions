#include<bits/stdc++.h>
using namespace std;

vector<long long> pairSum(vector<pair<long long, int>>&input, int start, int x) {
    vector<long long> ans;
    int i=start, j=input.size()-1;
    while(i < j) {
        long long sum = input[i].first + input[j].first;
        if(sum == x) {
            ans.push_back(input[i].second);
            ans.push_back(input[j].second);
            return ans;
        } else if(sum < x) {
            i++;
        } else {
            j--;
        }
    }
    return ans;
}
vector<long long> tripletSum(vector<pair<long long, int>>&input, int start, int x) {
    vector<long long> ans;
    for(int i=start; i<input.size(); i++) {
        vector<long long> pairs = pairSum(input, i+1, x-input[i].first);
        if(pairs.size()) {
            ans = pairs;
            ans.push_back(input[i].second);
            return ans;
        }
    }
    return ans;
}

void fourSum(vector<pair<long long, int>>&input, int x) {

    for(int i=0; i<input.size(); i++) {
        vector<long long> triplets = tripletSum(input, i+1, x-input[i].first);
        if(triplets.size()) {
            triplets.push_back(input[i].second);
            sort(triplets.begin(), triplets.end());
            cout<<triplets[0] + 1<<" "<<triplets[1]+1<<" "<<triplets[2]+1<<" "<<triplets[3]+1;
            return;
        }
    }
    cout<<"IMPOSSIBLE";
}
int main() {
    long long n, x;
    cin>>n>>x;
    vector<pair<long long, int>> input;
    for(int i=0; i<n; i++) {
        long long val;
        cin>>val;
        if(val <= x) {
            input.push_back(make_pair(val, i));
        } 
    }

    sort(input.begin(), input.end());
    fourSum(input, x);

    return 0;
}