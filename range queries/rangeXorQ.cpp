#include<bits/stdc++.h>
using namespace std;

void buildTree(vector<int>&input, vector<int>&tree, int s, int e, int i) {
    if(s == e) {
        tree[i] = input[s];
        return;
    }

    int mid = (s+e)/2;
    buildTree(input, tree, s, mid, 2*i);
    buildTree(input, tree, mid+1, e, 2*i+1);

    tree[i] = tree[2*i]^tree[2*i + 1];
}


int query(vector<int>&tree, int s, int e, int i, int left, int right) {
    //completely outside
    if(s > right || e < left) {
        return 0;
    }

    //completely inside
    if(s >= left && e <= right) {
        return tree[i];
    }

    //partially inside
    int mid = (s+e)/2;
    int ans1 = query(tree, s, mid, 2*i, left, right);
    int ans2 = query(tree, mid+1, e, 2*i+1, left, right);

    return ans1^ans2;
}
int main() {
    int n, q;
    cin>>n>>q;

    vector<int> input(n);
    for(int i=0; i<n; i++) {
        cin>>input[i];
    }

    vector<int> tree(4*n, 0);
    buildTree(input, tree, 0, n-1, 1);

    while(q--) {

        int left, right;
        cin>>left>>right;
        cout<<query(tree, 0, n-1, 1, left-1, right-1)<<endl;

    }
    return 0;
}