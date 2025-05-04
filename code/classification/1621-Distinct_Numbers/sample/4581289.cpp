#include<bits/stdc++.h>
using namespace std;
#define int int64_t
#define inf INT64_MAX
#define pii pair<int,int>
#define vi vector<int>
#define endl '\n'
#define pb push_back
int t, n, m, i, j, k,a, b,c,p,x,y,ans,n1,re;
string s1,s2;
const int M = 1e9+7;
bool bo;
 
int  binpow(int a, int  b, int  m) {
    a %= m;
    int  res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
 
void solve() {
    int n;
    set<int> s;
    cin>>n;
    while(n--){
        int i;
        cin>>i;
        s.insert(i);
    }
    cout<<s.size()<<endl;
  }
 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    t = 1;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
   // cin >> t;
    while (t--) solve();
}
 
 