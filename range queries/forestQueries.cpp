#include<bits/stdc++.h>
using namespace std;

void buildSegments(vector<vector<int>>&input, int row, vector<vector<int>>&segments, int s, int e, int i) {
    if(s == e) {
        segments[row][i] = input[row][s];
        return;
    }

    int mid = (s+e)/2;
    buildSegments(input, row, segments, s, mid, 2*i);
    buildSegments(input, row, segments, mid+1, e, 2*i+1);

    segments[row][i] = segments[row][2*i] + segments[row][2*i+1];
}

vector<int> add2Vectors(vector<int>&v1, vector<int>&v2) {
    vector<int> ans(v1.size());
    for(int i=0; i<v1.size(); i++) {
        ans[i] = v1[i] + v2[i];
    }
    return ans;
}
void buildTree(vector<vector<int>>&segments, vector<vector<int>>&tree, int s, int e, int i) {
    if(s == e) {
        tree[i] = segments[s];
        return;
    }

    int mid = (s+e)/2;
    buildTree(segments, tree, s, mid, 2*i);
    buildTree(segments, tree, mid+1, e, 2*i+1);

    //add values
    tree[i] = add2Vectors(tree[2*i], tree[2*i+1]);
}
int queryCol(vector<int>&treeSegment, int s, int e, int i, int left, int right) {
    //completely outside
    if(s > right || e < left) {
        return 0;
    }

    //completely inside
    if(s >= left && e <= right) {
        return treeSegment[i];
    }

    //partially inside
    int mid = (s+e)/2;
    int ans1 = queryCol(treeSegment, s, mid, 2*i, left, right);
    int ans2 = queryCol(treeSegment, mid+1, e, 2*i+1, left, right);

    return ans1 + ans2;
}
int query(vector<vector<int>>&tree, int s, int e, int i, int y1, int y2, int x1, int x2, int n) {
    if(s > y2 || e < y1) {
        return 0;
    }
    
    if(s >= y1 && e <= y2) {
        return queryCol(tree[i], 0, n-1, 1, x1, x2);
    }

    int mid = (s+e)/2;
    int ans1 = query(tree, s, mid, 2*i, y1, y2, x1, x2, n);
    int ans2 = query(tree, mid+1, e, 2*i+1, y1, y2, x1, x2, n);

    return ans1 + ans2;
}
int main() {
    int n, q;
    cin>>n>>q;
    vector<vector<int>> input(n, vector<int>(n, 0));

    vector<vector<int>> segments(n, vector<int>(4*n, 0));
    vector<vector<int>> tree(4*n, vector<int>(4*n, 0));

    //take input
    for(int i=0; i<n; i++) {
        string s;
        cin>>s;
        for(int j=0; j<n; j++) {
            if(s[j] == '*') {
                input[i][j] = 1;
            }
        }
    }

    for(int i=0; i<n; i++) {
        buildSegments(input, i, segments, 0, n-1, 1);
    }
    buildTree(segments, tree, 0, n-1, 1);

    while(q--) {
        int y1, x1, y2, x2;
        cin>>y1>>x1>>y2>>x2;
        cout<<query(tree, 0, n-1, 1, y1-1, y2-1, x1-1, x2-1, n)<<endl;
    }
    return 0;
}