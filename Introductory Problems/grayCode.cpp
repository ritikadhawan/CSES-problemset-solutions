#include<bits/stdc++.h>
using namespace std;

void grayCodes(int n, vector<vector<int>>&output) {
    if(n == 1) {
        vector<int> v0(1, 0);
        vector<int> v1(1, 1);
        output.push_back(v0);
        output.push_back(v1);
        return;
    }

    vector<vector<int>> smalloutput;
    grayCodes(n-1, smalloutput);

    //add 0
    for(int i=0; i<smalloutput.size(); i++) {
        vector<int> v(1, 0);
        v.insert(v.end(), smalloutput[i].begin(), smalloutput[i].end());
        output.push_back(v);
    }
    //add 1
    for(int i=smalloutput.size()-1; i>=0; i--) {
        vector<int> v(1, 1);
        v.insert(v.end(), smalloutput[i].begin(), smalloutput[i].end());
        output.push_back(v);
    }
}
int main() {
    int n;
    cin>>n;
    vector<vector<int>> output;
    grayCodes(n, output);

    for(int i=0; i<output.size(); i++) {
        for(int j=0; j<output[i].size(); j++) {
            cout<<output[i][j];
        }
        cout<<endl;
    }
    return 0;
}