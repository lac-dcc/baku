#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
using namespace std;
const int mxN=2e5;
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,m; cin>>n>>m;
      array<int,2>a[n];
      rep(i,0,n) cin>>a[i][1]>>a[i][0];
      sort(a,a+n);
      multiset<int>s;
      rep(i,0,m) s.insert(0);
      int ans=0;
      rep(i,0,n){
            auto it=s.upper_bound(a[i][1]);
            if(it!=s.begin()){
                  s.erase(--it);
                  ans++;
                  s.insert(a[i][0]);
            }
      }
      cout<<ans;
      return 0;
}
