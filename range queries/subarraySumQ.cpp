#include<bits/stdc++.h>
using namespace std;
 
class treeNode {
    public:
    long long maxSubSum, tltSum, prefix, suffix;
    treeNode() {
        maxSubSum = tltSum = prefix = suffix = INT_MIN;
    }
    
};
 
void buildTree(vector<treeNode>&tree, vector<long long>&input, int s, int e, int i) {
    if(s == e) {
        tree[i].maxSubSum = tree[i].tltSum  = tree[i].prefix = tree[i].suffix = input[s];
        return;
    }
 
    int mid = (s+e)/2;
    buildTree(tree, input, s, mid, 2*i);
    buildTree(tree, input, mid+1, e, 2*i+1);
 
    tree[i].maxSubSum = max(tree[2*i].maxSubSum, 
                            max(tree[2*i+1].maxSubSum, 
                                max(tree[2*i].tltSum + tree[2*i+1].prefix,
                                    max(tree[2*i].suffix + tree[2*i+1].tltSum, 
                                        max((long long) 0, tree[2*i].suffix + tree[2*i+1].prefix)))));
 
    tree[i].tltSum = tree[2*i].tltSum + tree[2*i+1].tltSum;
    tree[i].prefix = max(tree[2*i].prefix, tree[2*i].tltSum + tree[2*i+1].prefix);
    tree[i].suffix = max(tree[2*i+1].suffix, tree[2*i+1].tltSum + tree[2*i].suffix);
}
 
void update(vector<treeNode>&tree, vector<long long>&input, int s, int e, int i, int idx, long long val) {
    if(s == e) {
        input[s] = val;
        tree[i].maxSubSum = tree[i].tltSum  = tree[i].prefix = tree[i].suffix = val;
        return;
    }
 
    int mid = (s+e)/2;
    if(idx > mid) {
        update(tree, input, mid+1, e, 2*i+1, idx, val);
    } else {
        update(tree, input, s, mid, 2*i, idx, val);
    }
 
    tree[i].maxSubSum = max(tree[2*i].maxSubSum, 
                            max(tree[2*i+1].maxSubSum, 
                                max(tree[2*i].tltSum + tree[2*i+1].prefix,
                                    max(tree[2*i].suffix + tree[2*i+1].tltSum, 
                                        max((long long) 0, tree[2*i].suffix + tree[2*i+1].prefix)))));
 
    tree[i].tltSum = tree[2*i].tltSum + tree[2*i+1].tltSum;
    tree[i].prefix = max(tree[2*i].prefix, tree[2*i].tltSum + tree[2*i+1].prefix);
    tree[i].suffix = max(tree[2*i+1].suffix, tree[2*i+1].tltSum + tree[2*i].suffix);
}
int main() {
    int n, m;
    cin>>n>>m;
    vector<long long> input(n);
    for(int i=0; i<n; i++) {
        cin>>input[i];
    }
    vector<treeNode> tree(4*n);
    buildTree(tree, input, 0, n-1, 1);
 
    while(m--) {
        long long idx, val;
        cin>>idx>>val;
        update(tree, input, 0, n-1, 1, idx-1, val);
        long long ans = tree[1].maxSubSum;
        cout<<ans<<endl;
    } 
    return 0;
}