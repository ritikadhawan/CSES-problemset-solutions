#include<bits/stdc++.h>
using namespace std;

#define ll long long

void printMaxPrice(map<ll, ll>&ticketPrice, vector<ll>&customerPrice, int m) {
    for(int i = 0; i < m; i++) {
        //find ticketPrice equal to or just less than our customerPrice
        map<ll, ll>::iterator it = ticketPrice.lower_bound( customerPrice[i]);
        if(ticketPrice.size() == 0 || (it != ticketPrice.end() && it->first > customerPrice[i] && it == ticketPrice.begin())) {
            cout<<-1<<endl;
            continue;
        } else if(it == ticketPrice.end() || it->first > customerPrice[i]) {
            it--;
        }

        cout<<it->first<<endl;
        it->second--;
        if(it->second == 0) {
            ticketPrice.erase(it);
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    map<ll, ll> ticketPrice;
    vector<ll> customerPrice(m);

    for(int i=0; i<n; i++) {
        int price;
        cin>>price;
        ticketPrice[price]++;
    }

    for(int i=0; i<m; i++) {
        cin>>customerPrice[i];
    }
    printMaxPrice(ticketPrice, customerPrice, m);
    return 0;
}