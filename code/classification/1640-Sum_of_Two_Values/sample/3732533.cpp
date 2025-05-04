#include<bits/stdc++.h>
using namespace std;
#define all(t) t.begin(),t.end()
#define rll(t) t.rbegin(),t.rend()
#define pb push_back
#define fr first
#define sc second
#define prec(n) fixed<<setprecision(n)
#define MOD 1000000007
#define int long long
 
void solve(){
   int n,x;
   cin>>n>>x;
   vector<pair<int,int>> v;
   for(int i=0;i<n;i++){
      int a;cin>>a;
      v.pb({a,i+1});
   }
   sort(all(v));
   bool bat=1;
   for(int i=0;i<n;i++){
     int a=x-v[i].fr;
     if(a>=v[i].fr){
     pair<int,int> p={a,0};
     int found=lower_bound(v.begin()+i+1,v.end(),p)-v.begin();
     if(v[found].fr==a){
        int ans1=max(v[found].sc,v[i].sc);
        int ans2=min(v[found].sc,v[i].sc);
        cout<<ans2<<" "<<ans1<<"\n";
        bat=0;
        break;
     }}
   }
   if(bat){
    cout<<"IMPOSSIBLE"<<"\n";
   }
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    long t=1;
    //cin>>t;
    for(int i=0;i<t;i++){
     solve();
    }
}