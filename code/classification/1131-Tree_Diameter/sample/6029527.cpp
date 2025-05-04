#include<bits/stdc++.h>
#define int long long
#define fa(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define bp pop_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define hem  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
const int N=2e5+5;
vector<int>v[N],vis(N),dep(N);
int maxnode,maxi=-1;
void dfs(int ver){
vis[ver]=1;
for(auto child:v[ver]){
if(vis[child])continue;
dep[child]=dep[ver]+1;
dfs(child);
}
}
void solve(){
int n;
cin>>n;
fa(i,1,n){
int x,y;
cin>>x>>y;
v[x].pb(y),v[y].pb(x);
}
dfs(1);
fa(i,1,n+1){
if(dep[i]>maxi){
maxi=dep[i],maxnode=i;
}
}
fa(i,0,n+5){dep[i]=0,vis[i]=0;}
dfs(maxnode);
cout<<*max_element(all(dep))<<endl;
return;
}
signed main()
{
    hem;
int t=1;
//cin>>t;
while(t--)
solve();
}
