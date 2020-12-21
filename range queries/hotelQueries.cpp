#include<bits/stdc++.h>
using namespace std;

void buildTree(vector<int>&input, vector<int>&tree, int s, int e, int i) {
    if(s == e) {
        tree[i] = s;
        return;
    }

    int mid = (s+e)/2;
    buildTree(input, tree, s, mid, 2*i);
    buildTree(input, tree, mid+1, e, 2*i+1);

    if(max(input[tree[2*i]], input[tree[2*i + 1]]) == input[tree[2*i]]) {
        tree[i] = tree[2*i];
    } else {
        tree[i] = tree[2*i + 1];
    }
}

void update(vector<int>&input, vector<int>&tree, int s, int e, int i, int idx, int val) {
    if(s == e) {
        input[idx] -= val;
        return;
    }

    int mid = (s+e)/2;
    if(idx <= mid) {
        update(input, tree, s, mid, 2*i, idx, val);
    } else {
        update(input, tree, mid+1, e, 2*i+1, idx, val);
    }

    if(max(input[tree[2*i]], input[tree[2*i + 1]]) == input[tree[2*i]]) {
        tree[i] = tree[2*i];
    } else {
        tree[i] = tree[2*i + 1];
    }

}

int query(vector<int>&input, vector<int>&tree, int s, int e, int i, int val) {

   
    if(input[tree[i]] < val) {
        return -1;
    } else if(s == e) {
        return tree[i];
    } else {
        int mid = (s+e)/2;
        if(input[tree[2*i]] >= val) {
            return query(input, tree, s, mid, 2*i, val);
        } else {
            return query(input, tree, mid+1, e, 2*i+1, val);
        }
    }
}   
int main() {
    int n, q;
    cin>>n>>q;

    vector<int> input(n);
    for(int i=0; i<n; i++) {
        cin>>input[i];
    }

    vector<int> tree(4*n, INT_MAX);
    buildTree(input, tree, 0, n-1, 1);

    while(q--) {
        
        int val;
        cin>>val;
        int index = query(input, tree, 0, n-1, 1, val)+1;
        if(index != 0) {
            update(input, tree, 0, n-1, 1, index-1, val);
        }
        cout<<index<<" ";
        
    }
    return 0;
}