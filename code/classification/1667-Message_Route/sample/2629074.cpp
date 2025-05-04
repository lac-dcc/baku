#include <bits/stdc++.h>
#define startt ios_base::sync_with_stdio(false);cin.tie(0);
typedef unsigned long long ull;
typedef long long  ll;
using namespace std;
#define vint vector<int>
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define MOD 1000000007
#define MOD2 998244353
#define MX 1000000000
#define nax 100005
#define MXL 1000000000000000000
#define PI 3.14159265
#define pb push_back
#define pf push_front
#define sc second
#define fr first
#define endl '\n' //delete if interactive
#define ld long double
#define mp make_pair
//DFS
const int maxl = 100005;
bool visited[maxl]={0};
vector<int> adj[maxl];
int parent[maxl];
int n,m;
void bfs(int curr,int tar){
	queue<int> q;
	int temp;
	q.push(curr);
	visited[curr]=true;
	while(!q.empty()){
	    temp=q.front();q.pop();
	    //cout<<"visit: "<<temp<<", tar: "<<tar<<endl;
	    if(temp==tar){
	        break;
	    }
	    for(auto x: adj[temp]){
	        if(!visited[x]){
	            parent[x]=temp;
	            visited[x]=true;
	            q.push(x);
	        }
	    }
	}
}
void solve(){
	cin>>n>>m;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<maxl;i++) parent[i]=-1;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bfs(0,n-1);
    vector<int> v;
    int idx=n-1;
    v.pb(n-1);
    while(idx!=0 && idx!=-1){
        idx = parent[idx];
        v.pb(idx);
    }
    if(idx==0){
        cout<<sz(v)<<endl;
        for(int i=sz(v)-1;i>=0;i--){
            cout<<v[i]+1<<" ";
        }cout<<endl;   
    }else{
        cout<<"IMPOSSIBLE\n";
    }
    
}
 
int main(){
	solve();
	return 0;
}
