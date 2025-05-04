#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>>v(n);
    for (auto &i : v) {
        cin >> i.F >> i.S;
    }
    sort(all(v),[](pair<int,int>x,pair<int,int>y){
        if (x.F != y.F) {
            return x.F < y.F;
        }
        else {
            return x.S > y.S;
        }
    });
    multiset<int>st;
    int ans = n;
    for (auto &i :v) {
        while (st.size() && *st.begin() <= i.F) {
            st.erase(*st.begin());
        }
        st.insert(i.S);
        if (st.size() > m) {
            st.erase(--st.end());
            ans--;
        }
        
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}