#include<bits/stdc++.h>
using namespace std;

vector<string> output;

void getCombination(string str, vector<int>&freq, int n) {
    if(n == 0) {
        output.push_back(str);
        return;
    }

    for(char ch='a'; ch<='z'; ch++) {
        if(freq[ch-'a'] > 0) {
            vector<int> newFreq = freq;
            newFreq[ch - 'a']--;
            getCombination(str + ch, newFreq, n-1);
        }
    }
}
int main() {
    string s;
    cin>>s;
    vector<int> freq(26, 0);

    for(char ch: s) {
        freq[ch-'a']++;
    }
    getCombination("", freq, s.size());
    cout<<output.size()<<endl;
    for(auto str: output) {
        cout<<str<<endl;
    }
    return 0;
}