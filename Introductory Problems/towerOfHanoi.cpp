#include<bits/stdc++.h>
using namespace std;

int towerOfHanoi(int n, int origin, int temp, int dest, vector<pair<int, int>>&path) {
    if(n == 0) {
        return 0;
    }
    //move n-1 sticks from origin to temp stick using dest
    int moves = towerOfHanoi(n-1, origin, dest, temp, path);

    //move 1 stick from origin to dest
    moves++;
    path.push_back(make_pair(origin, dest));

    //move n-1 sticks from temp to dest
    moves += towerOfHanoi(n-1, temp, origin, dest, path);

    return moves;
}
int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> path;
    int moves = towerOfHanoi(n, 1, 2, 3, path);
    cout<<moves<<endl;
    for(auto p: path) {
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}