#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool compare(pair<int, int>&num1, pair<int, int>&num2) {
    if(num1.second == num2.second) {
        return num1.first < num2.first;
    }
    return num1.second < num2.second;
}
int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> intervals(n);

    for(int i = 0; i < n; i++) {
        cin>>intervals[i].first>>intervals[i].second;
    }
    sort(intervals.begin(), intervals.end(), compare);

    int count = 0, lastEndTime = 0;
    for(int i = 0; i < n; i++) {
        if(intervals[i].first >= lastEndTime) {
            count++;
            lastEndTime = intervals[i].second;
        }
    }

    cout<<count;
    return 0;
}