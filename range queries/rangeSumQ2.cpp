#include<bits/stdc++.h>
using namespace std;

void buildTree(vector<long long>&input, vector<long long>&tree, int s, int e, int i) {
    if(s == e) {
        tree[i] = input[s];
        return;
    }

    int mid = (s+e)/2;
    buildTree(input, tree, s, mid, 2*i);
    buildTree(input, tree, mid+1, e, 2*i+1);

    tree[i] = tree[2*i] + tree[2*i + 1];
}

void update(vector<long long>&input, vector<long long>&tree, int s, int e, int i, int idx, long long val) {
    if(s == e) {
        input[idx] = val;
        tree[i] = val;
        return;
    }

    int mid = (s+e)/2;
    if(idx <= mid) {
        update(input, tree, s, mid, 2*i, idx, val);
    } else {
        update(input, tree, mid+1, e, 2*i+1, idx, val);
    }

    tree[i] = tree[2*i] + tree[2*i+1];

}

long long query(vector<long long>&tree, int s, int e, int i, int left, int right) {
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
    long long ans1 = query(tree, s, mid, 2*i, left, right);
    long long ans2 = query(tree, mid+1, e, 2*i+1, left, right);

    return ans1+ans2;
}
int main() {
    int n, q;
    cin>>n>>q;

    vector<long long> input(n);
    for(int i=0; i<n; i++) {
        cin>>input[i];
    }

    vector<long long> tree(4*n, INT_MAX);
    buildTree(input, tree, 0, n-1, 1);

    while(q--) {
        int qry;
        cin>>qry;
        if(qry == 1) {
            long long idx, val;
            cin>>idx>>val;
            update(input, tree, 0, n-1, 1, idx-1, val);
        } else {
            int left, right;
            cin>>left>>right;
            cout<<query(tree, 0, n-1, 1, left-1, right-1)<<endl;
        }
    }
    return 0;
}