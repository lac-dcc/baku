#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vector<int>,greater<int>>
using namespace std;
int mod=1e9+7;
void viin(vi &a){for(int i=0;i<a.size();i++) cin>>a[i];}
int visum(vi &a){int res=0;for(auto x:a) res+=x;return res;}
vector<int> in;
vector<int> out;
int dfs1(int i,int p,vector<int> adj[]){
    for(auto j:adj[i]){
        if(j!=p){
            int xx=dfs1(j,i,adj);
            in[i]=max(in[i],xx);
        }
    }
    return 1+in[i];
}
void dfs2(int i,int p,vector<int> adj[]){
    int mx1=-1,mx2=-1;
    for(auto j:adj[i]){
        if(j!=p){
            if(in[j]>=mx1){
                mx2=mx1;
                mx1=in[j];
            }
            else if(in[j]>mx2){
                mx2=in[j];
            }
        }
    }
   for(auto j:adj[i]){
    if(j!=p){
        int ll=mx1;
        if(ll==in[j])
        ll=mx2;
        out[j]=1+max(out[i],1+ll);
        dfs2(j,i,adj);
    }
   }
}
 
 
int32_t main(){
int n;
cin>>n;
// vi a(n);
// viin(a);
int x=n-1;
vector<int> adj[n+1];
while(x--){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
in.resize(n+1,0);
out.resize(n+1,0);
dfs1(1,-1,adj);
dfs2(1,-1,adj);
for(int i=1;i<=n;i++){
    cout<<max(in[i],out[i])<<" ";
}
cout<<endl;
return 0;
}
