#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin>>n>>x;
    vector<pair<long long, int>> input(n);
   
    for(int i=0; i<n; i++) {
        cin>>input[i].first;
        input[i].second = i;
    }
    sort(input.begin(), input.end());

    int i=0, j=n-1;
    bool solPossible = false;
    while(i < j) {
        long long sum = input[i].first + input[j].first;
        if(sum == x) {
            solPossible = true;
            break;
        } else if(sum < x) {
            i++;
        } else {
            j--;
        }
    }

    if(solPossible) {
        cout<<input[i].second+1<<" "<<input[j].second+1;
    } else {
        cout<<"IMPOSSIBLE";
    }
    return 0;
}