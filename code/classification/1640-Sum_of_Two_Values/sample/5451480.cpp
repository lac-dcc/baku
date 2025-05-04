#include <bits/stdc++.h>
     
using namespace std;
     
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
     
#define int long long int
 
#define pb push_back
 
#define pii pair<int,int>
 
#define f first
 
#define s second
 
     
void solve()
{
    
   int n,x;
   cin>>n>>x;
   
   vector<pii>a;
   for(int i=0;i<n;i++){
       int t;
       cin>>t;
       a.push_back({t,i+1});
   }
   
   vector<int>v;
   
   sort(a.begin(), a.end())
   ;
   
   for(int i=0;i<a.size();i++){
    v.push_back(a[i].first);
   }
   
   for(int i=0;i<n;i++){
    if(a[i].first>=x){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    
    int y = x-a[i].first;
    auto p = upper_bound(v.begin()+i+1, v.end(),y)-v.begin();
    p--;
    if(p>=0&&a[p].first==y&&a[i].second!=a[p].second){
        cout<<a[i].second<<" "<<a[p].second<<endl;
        return;
    }
    
   }
   
   cout<<"IMPOSSIBLE"<<endl;
   return;
}
 
signed main()
{
    fastio
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}
                
