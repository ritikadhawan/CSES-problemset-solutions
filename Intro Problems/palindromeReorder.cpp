#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;

    vector<long> freq(26, 0);
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        int index = ch - 'A';
        freq[index]++;
    }

    bool oddValueExists = false, solPresent = true;
    char oddFreqChar = '.';
    for(int i=0; i<26; i++) {
        if(freq[i]% 2 != 0 && !oddValueExists) {
            oddValueExists = true;
            oddFreqChar = 'A' + i;
        } else if(freq[i]% 2!= 0 && oddValueExists) {
            solPresent = false;
            break;
        }
    }
    

    if(solPresent) {
        string ans = "";
        for(char ch = 'A'; ch <= 'Z';  ch++) {
            if(freq[ch - 'A'] > 0 && freq[ch - 'A']  % 2 == 0) {
                ans.append((freq[ch - 'A'])/2u,ch);
            } 
        }
        cout<<ans;
        if(oddValueExists) {
            for(int i=0; i<freq[oddFreqChar - 'A']; i++)
                cout<<oddFreqChar;
        }
        reverse(ans.begin(), ans.end());
        cout<<ans;
    } else {
        cout<<"NO SOLUTION";
    }
    return 0;
}