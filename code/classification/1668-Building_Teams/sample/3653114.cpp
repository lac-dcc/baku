#include<bits/stdc++.h>
using namespace std;
 
#define FASTIO						ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll 							long long 
#define mset(A,val) 				memset(A,val,sizeof(A))
#define fi(a,b) 					for(int i=a;i<=b;++i)
#define fj(a,b) 					for(int j=a;j<=b;++j)
#define all(x)  					x.begin(),x.end()
#define vi  						vector<int>
#define pii  						pair<int,int>
#define pb  						push_back
#define eb  						emplace_back
#define DEBUG(a...)  				cout<<#a<<": ";for(auto &it:a)cout<<it<<" ";cout<<endl;
#define debug(a) 					cout<<#a<<": "<<a<<"\n";
#define hola  						cout<<"hola"<<endl;
#define int long long
 
// ---------------------------------------------------------------------------
const int mod = 1e9+7;
const int maxn = 2e5 + 9;
int n,m;
vi color;
vector<vi>graph;
vector<bool>vis;
// ---------------------------------------------------------------------------
void init(){}
bool dfs(int node,int col){
    vis[node] = true;
    color[node] = col;
    for(auto & child : graph[node]){
        if(!vis[child]){
            if(!dfs(child,1-col)){
                return false;
            }
        }
        if(color[node]==color[child]){
            return false;
        }
    }
    return true;
}
// ---------------------------------------------------------------------------
void test_case(int tc)
{
    // cout<<"Case #"<<tc<<": ";
    cin>>n>>m;
    graph = vector<vi>(n+1);
    vis = vector<bool>(n+1,0);
    color = vi(n+1,0);
    fi(1,m){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    fi(1,n){
        if(!vis[i]){
            if(!dfs(i,0)){
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
    }
    fi(1,n){
        cout<<color[i]+1<<" ";
    }
}
 
int32_t main()
{
    FASTIO;
     #ifndef ONLINE_JUDGE
         freopen("input.txt","r",stdin);
         // freopen("output.txt","w",stdout);
     #endif
    
    int t=1;
    //cin>>t;
    for(int tc=1;tc<=t;++tc)test_case(tc);
}