#include<bits/stdc++.h>
#define int long long
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,i1,n) for(int i=i1;i<n;i++)
#define pb push_back
#define ppb pop_back
#define disp(v) for(int i=0;i<v.size();i++){cout<<v[i]<<' ';} cout<<endl
#define SUM(v) accumulate(all(v), 0LL)
#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define invec(v,n) vector<int> v(n); rep(i,0,n) cin>>v[i]
const int M=1e9+7;
#define endl '\n'
 
int binpow(int a, int b) {
int res = 1;
while (b > 0) {
if (b & 1)
res = (res * a)%M;
a = (a * a)%M;
b >>= 1;
}
return res;
}
 
inline void solve(int tc){
    int n,m; cin>>n>>m;
    invec(a,n);
    invec(b,m);
    multiset<int, greater<int>> ms;
    for(auto it:a) ms.insert(it);
    rep(i,0,m){
        auto it=ms.lower_bound(b[i]);
        if(it==ms.end()) cout<<-1<<endl;
        else {
            cout<<*it<<endl;
            ms.erase(ms.find(*it));
        } 
    }
}
 
signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cout<<fixed<<setprecision(0);
    int t=1;
    // cin>>t;
    for(int tc=0;tc<t;tc++){
        solve(tc);
    }
}
