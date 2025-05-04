#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
 
    int n, m; cin >> n >> m;
    // vector<int> tickets(n);
    multiset<int> tickets;
    vector<int> maxPrices(m);
 
    // for(int i = 0; i < n; i++) cin >> tickets[i];
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        tickets.insert(num);
    }
    for(int i = 0; i < m; i++) cin >> maxPrices[i];
 
    // sort(tickets.begin(), tickets.end());
 
    vector<int> res(m);
 
    for(int maxPriceI = 0; maxPriceI < m; maxPriceI++){
        int maxPrice = maxPrices[maxPriceI];
        // auto tbeg = tickets.begin();
        
        auto it = tickets.upper_bound(maxPrice);
 
        if(it == tickets.begin()){
            res[maxPriceI] = -1;
        }else{
            res[maxPriceI] = *(--it);
            tickets.erase(it);
        }
    }
 
    for(int ans : res) cout << ans << '\n';
 
    return 0;
}
