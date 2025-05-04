#include <bits/stdc++.h>  
using namespace std;  
using ll = long long;  
#define sz(x) int((x).size())
 
int32_t main()
{  
    ios::sync_with_stdio(false);  
    cin.tie(0);
   
    int n,m;
    cin >> n >> m;
    multiset<int,greater<int>> h; 
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        h.insert(x);
    }
    for(int j=0; j<m; j++){
        int t;
        cin >> t;
        auto it = h.lower_bound(t);
        if(it==h.end()){
            cout << -1 << "\n";
        }else{
            if(*it <= t){
                cout << *it << "\n";
                h.erase(it);
            }
            
        }
        
 
 
    }
 
        
}
