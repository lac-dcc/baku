#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i = 1; i <= n; i++)
#define vi vector<int>
 
typedef long long LL;
typedef pair<int,int> pii;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
vector<int> visited[200001];
//vi ar[200001];
 
 
int fv[200001];
int gv[200001];
int d;
 
void dfs(int node, int par){
	vector<int> children;
	for(int child: visited[node]){
		if(child!=par){
			dfs(child, node);
			fv[node]=max(fv[node], fv[child]+1);
			children.push_back(fv[child]);
		}
	}
	d=max(d, fv[node]);
	sort(children.begin(), children.end());
	if(children.size()>=2){
		gv[node]=2+children[children.size()-1]+children[children.size()-2];
		d=max(d, gv[node]);
	}
}
 
int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	int n, a, b;
	cin>>n;
	for(int i=1; i<=n-1; i++){
		cin>>a>>b;
		visited[a].push_back(b);
		visited[b].push_back(a);
	}
	//REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
 
	dfs(1, -1);
	cout<<d;
 
	cout.flush();
	return 0;
}
