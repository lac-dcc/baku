#include <bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long
#define int long long
#define vi vector
#define vvi vector<vector
#define vvvi vector<vector<vector
 
void solve(){
    int n,m,x;
    cin>>n>>m;
    multiset<int> st;
    for(int i = 0; i < n ; i++){
        cin>>x;
        st.insert(x);
    }
    for(int i = 0; i < m ; i++){
        cin>>x;
        auto p = st.lower_bound(x);
        if(*(p) == x){
            cout<<x<<"\n";
            st.erase(p);
        }
        else if(p != st.begin()) {
            p--;
            int val = *p;
            cout<<val<<"\n";
            st.erase(p);
        }
        else cout<<-1<<"\n";
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1;
    // cin>>t;
    while(t--){;
        solve();
    }
    return 0;
}
