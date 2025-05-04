#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define fo(i,a,b) for(ll i=a;i<b;i++)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define eb emplace_back
#define nline "\n"
const ll mod=1e9+7;
 
vector<ll>level(100001,-1);
 
vector<ll>ans;
 
void dfs(vector<ll>graph[],ll src,ll next_expected){
    ans.push_back(src);
    for(auto child:graph[src]){
        if(level[child]==next_expected){
            dfs(graph,child,next_expected-1);
            break;
        }
    }
}
 
void bfs(vector<ll>graph[],vector<bool>&visited,ll src){
    queue<ll>q;
    q.push(src);
    visited[src]=true;
    level[src]=0;
    while(!q.empty()){
        ll vertex=q.front();
        q.pop();
        for(auto child:graph[vertex]){
            if(!visited[child]){
                level[child]=level[vertex]+1;
                q.push(child);
                visited[child]=true;
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    ll n,m;
    cin>>n>>m;
    vector<ll>graph[n+1];
    fo(i,0,m){
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool>visited(n+1,false);
    bfs(graph,visited,1);
    fo(i,0,n+1) visited[i]=false;
    if(level[n]==-1) cout<<"IMPOSSIBLE";
    else{
        dfs(graph,n,level[n]-1);
        cout<<level[n]+1<<nline;
        reverse(all(ans));
        for(auto a:ans) cout<<a<<" ";
    }
    return 0;
}
