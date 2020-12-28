#include<bits/stdc++.h>
using namespace std;

long long placeQueens(int curr, vector<vector<bool>>&blocked, vector<bool>&leftDiagonal, vector<bool>&rightDiagonal, vector<bool>&column) {
    if(curr == 8) {
        //all queens placed
        return 1;
    }

    //place queen in curr row
    long long ways = 0;
    for(int j=0; j<8; j++) {
        int ld = curr+j;
        int rd = abs(curr-j-7);
        if(!blocked[curr][j] && !column[j] && !rightDiagonal[rd] && !leftDiagonal[ld]) {
            vector<bool> newCol = column;
            vector<bool> newRightD = rightDiagonal;
            vector<bool> newLeftD = leftDiagonal;

            newCol[j] = true;
            newRightD[rd] = true;
            newLeftD[ld] = true;

            ways += placeQueens(curr+1, blocked, newLeftD, newRightD, newCol);
        }
    }
    return ways;
}
int main() {
    vector<vector<bool>> blocked(8, vector<bool>(8, false));

    for(int i=0; i<8; i++) {
        string row;
        cin>>row;
        for(int j=0; j<8; j++) {
            if(row[j] == '*') {
                blocked[i][j] = true;
            }
        }
    }

    vector<bool> leftDiagonal(15, false);
    vector<bool> rightDiagonal(15, false);
    vector<bool> column(8, false);
    
    cout<<placeQueens(0, blocked, leftDiagonal, rightDiagonal, column);
    return 0;
}