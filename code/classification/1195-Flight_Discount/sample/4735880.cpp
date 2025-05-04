#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
 
#define ld long double
#define endl "\n"
 
int inf = 1000000007 ;
double pi=acos(-1);
pair<int,pair<int,int>>p[200100];
void dij(int st,vector<vector<pair<int,int>>>&g,vector<int>&dist){
    dist[st]=0;
    int n=dist.size();
    vector<int>vis(n+1,0);
    priority_queue<pair<int,int>>pq;
    pq.push(make_pair(-0,st));
    while(pq.size()){
        pair<int,int>p=pq.top();
        pq.pop();
        if(vis[p.second]) continue;
        vis[p.second]=1;
        for(auto &it : g[p.second]){
            if( dist[it.first]>-p.first+it.second ){
                dist[it.first]=-p.first+it.second;
                pq.push(make_pair(-dist[it.first],it.first));
            }
        }
    }
}
signed main(){
    IOS
    int t=1;
    for(int tt=1;tt<=t;tt++){
        int n,m;cin>>n>>m;
        vector<vector<pair<int,int>>>g1(n+10),g2(n+10);
        
        for(int i=0;i<m;i++){
            int a,b,c;cin>>a>>b>>c;
            p[i].first=a;p[i].second.first=b;p[i].second.second=c;
            g1[a].push_back(make_pair(b,c));
            g2[b].push_back(make_pair(a,c));
        }
        vector<int>dis1(n+10,1e16),dis2(n+10,1e16);
        dij(1,g1,dis1);
        dij(n,g2,dis2);
        int ans=1e18;
        for(int i=0;i<m;i++){
            int dum= dis1[p[i].first]+dis2[p[i].second.first]+p[i].second.second/2;
            ans=min(ans,dum);
        }
        cout<<ans<<'\n';
    }
    return 0;
}