#include<bits/stdc++.h>
using namespace std;

long long findPrice(vector<long long>&h, long long maxPrice, vector<bool>&visited) {
    auto lb = lower_bound(h.begin(), h.end(), maxPrice, greater<long long>());
    int lbI = lb - h.begin();

    auto ub = upper_bound(h.begin(), h.end(), *lb, greater<long long>());
    int ubI = ub - h.begin();
    if(lb == h.end()) {
        return -1;
    }

    if(visited[lbI] && visited[ubI-1]) {
        return findPrice(h, *lb-1, visited);
    } else {
        //binary search
        if(!visited[lbI]) {
            visited[lbI] = true;

            
            return h[lbI];
        }
        int i=lbI, j=ubI-1;
        while(i <= j) {
            int mid = (i+j)/2;
            if(!visited[mid] && !visited[mid-1]) {
                //move towards left
                j = mid-1;
            } else if(visited[mid]) {
                i = mid+1;
            } else {
                visited[mid] = true;
                return h[mid];
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<long long> h(n);
    vector<long long> t(m);

    for(int i=0; i<n; i++) {
        cin>>h[i];
    }

    for(int i=0; i<m; i++) {
        cin>>t[i];
    }

    sort(h.begin(), h.end(), greater<long long>());
    vector<bool> visited(n, false);
    for(int i=0; i<m; i++) {
        // auto lb = lower_bound(h.begin(), h.end(), t[i], greater<long long>());
        // if(lb == h.end()) {
        //     cout<<-1<<endl;
        // } else {
        //     cout<<*lb<<endl;
        //     h.erase(lb);
        // }
        
        cout<<findPrice(h, t[i], visited)<<endl;
        // break;
    }
    return 0;
}