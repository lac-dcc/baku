#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MOD 1e12
 
using namespace std;
const ll MAX = 1e6;
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
	// int t;
    // cin >> t;
    // while(t--){
        ll n, m, x;
        cin >> n >> m;
        multiset<ll> s;
        ll arr[m];
        for(int i=0; i<n; i++){
            cin >> x;
            s.insert(x);
        }
        for(int i=0; i<m; i++) cin >> arr[i];
        for(int i=0; i<m; i++){
            if(s.size()==0){
                cout << "-1" << endl;
                continue;
            }
            auto it = s.begin();
            if(arr[i]<(*it)){
                cout << "-1" << endl;
            }
            else{
                it = s.upper_bound(arr[i]);
                // cout << *it << endl;
                it--;
                cout << *it << endl;
                s.erase(it);
            }
        }
    // }
 
 
    return 0;
}
