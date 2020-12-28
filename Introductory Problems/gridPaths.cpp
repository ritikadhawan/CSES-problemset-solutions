#include<bits/stdc++.h>
using namespace std;

long long noOfPaths(string pathDes, vector<vector<bool>>&visited, int i, int j, int currP) {
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

    visited[i][j] = true;
    long long paths = 0;
    if(pathDes[currP] == '?') {
        paths += noOfPaths(pathDes, visited, i+1, j, currP+1);
        paths += noOfPaths(pathDes, visited, i-1, j, currP+1);
        paths += noOfPaths(pathDes, visited, i, j-1, currP+1);
        paths += noOfPaths(pathDes, visited, i, j+1, currP+1);
    } else {
        switch(pathDes[currP]) {
            case 'D':
                paths += noOfPaths(pathDes, visited, i+1, j, currP+1);
            break;
            case 'U':
                paths += noOfPaths(pathDes, visited, i-1, j, currP+1);
            break;
            case 'L':
                paths += noOfPaths(pathDes, visited, i, j-1, currP+1);
            break;
            case 'R':
                paths += noOfPaths(pathDes, visited, i, j+1, currP+1);
            break;
        }
    }
    visited[i][j] = false;
    return paths;
}
int main() {
    string pathDes;
    cin>>pathDes;
    vector<vector<bool>> visited(7, vector<bool>(7, false));
    cout<<noOfPaths(pathDes, visited, 0, 0, 0);
    return 0;
}