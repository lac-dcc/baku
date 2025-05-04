#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5 + 5;
 
int n, m;
multiset<int> tickets;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m;
    int x;
    for(int i = 1; i <= n; i++){
        cin >> x;
        tickets.insert(x);
    }
 
    for(int i = 1; i <= m; i++){
        cin >> x;
        auto it = tickets.upper_bound(x);
        if(it == tickets.begin()){
            cout << "-1\n";
        }else{
            it--;
            cout <<*it << "\n";
            tickets.erase(it);
        }
    }
 
    return 0;
}
