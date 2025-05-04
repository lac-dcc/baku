#include<bits/stdc++.h>
using namespace std;
 
/***typededfs***/
typedef long long ll;
typedef long double ldb;
 
/***defines***/
#define M1 1000000007
#define M2 998244353
#define F first
#define S second
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forz(i,n) for(int i=0;i<(n);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define rforz(i,n) for(int i=(n-1);i>=0;i--)
#define rfore(i,a,b) for(int i=(a);i>=(b);i--)
#define test int T; cin>>T; while(T--)
 
 
 
template<typename T>
class Graph{
	map<T,list<T>>l;
	map<T,T> parent;
 
public:
	void addEdge(T x,T y){
		l[x].pb(y);
		l[y].pb(x);
	}
	map<T,T> bfs(T src,T tar){
		map<T,bool> visited; queue<T> q;
		q.push(src);
		int dist{};
		visited[src]=true;
		//cout<<node<<"-> ";
		while(!q.empty()){
			T node = q.front();
			//cout<<node<<" ";
			q.pop();
			if(node==tar){return parent;}
			dist++;
			for(auto nbr:l[node]){
				if(!visited[nbr]){
					visited[nbr]=true;
					parent[nbr]=node;					
					q.push(nbr);
				}
			}
		}
		map<int,int> mp;
		return mp;
	}
	
 
};
 
 
int main(){
    FASTIO;
    int n,m;
    cin>>n>>m;
    Graph<int> g;
 
    forz(i,m){
    	int x,y;
    	cin>>x>>y;
    	g.addEdge(x,y);
    }
    //int len = g.bfs(1,n);
    //cout<<"\nlen = "<<len<<'\n';
    map<int,int> parent = g.bfs(1,n);
    if(parent.size()==0){cout<<"IMPOSSIBLE\n";return 0;}
    int x=n;
    vector<int> ans;
    while(x!=1){
    	int nx=parent[x];
    	ans.pb(nx);
    	x=nx;
    }
    cout<<ans.size()+1<<'\n';
    int len=ans.size();
    rforz(i,len){
    	cout<<ans[i]<<' ';
    }cout<<n<<' ';
  	    
}
