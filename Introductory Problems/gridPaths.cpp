#include<bits/stdc++.h>
using namespace std;

long long noOfPaths(string pathDes, vector<vector<bool>>&visited, int i, int j, int currP, vector<vector<vector<long long>>>&storage) {
    if(i < 0 || i >= 7) {
        return 0;
    } 
    if(j < 0 || j >= 7) {
        return 0;
    }

    if(visited[i][j]) {
        return 0;
    }

    if(i == 6 && j == 0 && currP == pathDes.size()) {
        //destination
        return 1;
    }
    if(currP == pathDes.size()) {
        return 0;
    }
    if(i == 6 && j == 0) {
        return 0;
    }
    // cout<<i<<" "<<j<<" "<<currP<<" "<<storage[i][j][currP]<<endl;
    if(storage[i][j][currP] != -1) {
        // cout<<i<<" "<<j<<" "<<currP<<endl;
        return storage[i][j][currP];
    }
    visited[i][j] = true;
    long long paths = 0;
    if(pathDes[currP] == '?') {
        paths += noOfPaths(pathDes, visited, i+1, j, currP+1, storage);
        paths += noOfPaths(pathDes, visited, i-1, j, currP+1, storage);
        paths += noOfPaths(pathDes, visited, i, j-1, currP+1, storage);
        paths += noOfPaths(pathDes, visited, i, j+1, currP+1, storage);
    } else {
        switch(pathDes[currP]) {
            case 'D':
                paths += noOfPaths(pathDes, visited, i+1, j, currP+1, storage);
            break;
            case 'U':
                paths += noOfPaths(pathDes, visited, i-1, j, currP+1, storage);
            break;
            case 'L':
                paths += noOfPaths(pathDes, visited, i, j-1, currP+1, storage);
            break;
            case 'R':
                paths += noOfPaths(pathDes, visited, i, j+1, currP+1, storage);
            break;
        }
    }
    visited[i][j] = false;
    storage[i][j][currP] = paths;
    // cout<<i<<" "<<j<<" "<<currP<<" "<<storage[i][j][currP]<<endl;
    return paths;
}
int main() {
    string pathDes;
    cin>>pathDes;

    vector<vector<vector<long long>>> storage(8, vector<vector<long long>>(8, vector<long long>(50, -1)));
    vector<vector<bool>> visited(8, vector<bool>(8, false));

    cout<<noOfPaths(pathDes, visited, 0, 0, 0, storage);
    return 0;
}
