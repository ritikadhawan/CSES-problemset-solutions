#include<bits/stdc++.h>
using namespace std;
class Directions {
    public:
    bool up, down, left, right;
};
Directions possibleDirections(string&pathDes, vector<vector<bool>>&visited, int i, int j, int currP) {
    Directions ans;
    if(pathDes[currP] == '?') {
        ans.up = i - 1 >= 0 && !visited[i - 1][j];
        ans.down = i + 1 < 7 && !visited[i + 1][j];
        ans.left = j - 1 >= 0 && !visited[i][j - 1];
        ans.right = j + 1 < 7 && !visited[i][j + 1]; 
    } else {
        ans.up = pathDes[currP] == 'U' && i - 1 >= 0 && !visited[i - 1][j];
        ans.down = pathDes[currP] == 'D' && i + 1 < 7 && !visited[i + 1][j]; 
        ans.left = pathDes[currP] == 'L' && j - 1 >= 0 && !visited[i][j - 1];
        ans.right = pathDes[currP] == 'R' && j + 1 < 7 && !visited[i][j + 1];
    }
    return ans;
}
long long noOfPaths(string&pathDes, vector<vector<bool>>&visited, int i, int j, int currP) {
    if(i == 6 && j == 0) {
        return (currP == pathDes.length()) ? 1 : 0;
    }
 
    //pruning the search here as we need to visit each cell atleast once and if we need to choose between left and right OR up and down we can stop
    Directions d = possibleDirections(pathDes, visited, i, j, currP);
    if(pathDes[currP] == '?' && ((!d.up && !d.down && d.left && d.right) || (d.up && d.down && !d.left && !d.right))) {
        return 0;
    }
 
    visited[i][j] = true;
    long long ans = 0;
 
    ans += d.up ? noOfPaths(pathDes, visited, i - 1, j, currP + 1) : 0;
    ans += d.down ? noOfPaths(pathDes, visited, i + 1, j, currP + 1) : 0;
    ans += d.left ? noOfPaths(pathDes, visited, i, j - 1, currP + 1) : 0;
    ans += d.right ? noOfPaths(pathDes, visited, i, j + 1, currP + 1) : 0;
    
    visited[i][j] = false;
    return ans;
}
int main() {
    string pathDes;
    cin>>pathDes;
 
    vector<vector<bool>> visited(7, vector<bool>(7, false));
 
    cout<<noOfPaths(pathDes, visited, 0, 0, 0);
    return 0;
}