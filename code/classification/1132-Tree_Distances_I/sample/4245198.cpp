                                                     /*JODD or WOTT!*/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i,k,n) for(int i=k;i<=n;i++)
#define repr(i,k) for(int i=k;i>=0;i--)
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9
#define PB push_back
#define MOD 100000007
#define MAX INT_MAX
#define MIN INT_MIN
const int MAXL= 2e5 + 5;
vector<int>g[MAXL];
int dist[MAXL][3];
int n;
int dfs(int v,int p,int y){
    int mx=0,idx=-1;
   for(int u: g[v]){
    if(u!=p){
        dist[u][y]=dist[v][y]+1;
        int curr = dfs(u,v,y);
        if (idx == -1 || dist[curr][y] > dist[idx][y]) idx = curr;
    }
   }
 
   return idx==-1?v:idx;
}
 
 
void run_case()
{
   cin>>n;
   rep(i,0,n-2){
     int a,b;
     cin>>a>>b;
     g[a].push_back(b);
     g[b].push_back(a);
   }
   int temp = dfs(1,0,0);
   //cout<<temp<<endl;
   int temp1 = dfs(temp,0,1);
   dfs(temp1,0,2);
   for(int i=1;i<=n;i++){
    cout<<max(dist[i][1],dist[i][2])<<" ";
   }
}
 
 
signed main()
{
 
ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t=1;//cin>>t;
 
   while(t--)
   {
       run_case();
   }
return 0;
}
