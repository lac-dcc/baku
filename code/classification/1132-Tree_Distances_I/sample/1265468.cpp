#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int MAX_N = 2e5+10;
int n;
vector<int> G[MAX_N];
int depth[MAX_N];
int ans[MAX_N];
 
void add_edge(int from, int to)
{
	G[from].push_back(to);
	G[to].push_back(from);
}
 
void dfs1(int at, int par)
{
	int d = 0;
	for(int nxt : G[at])if(nxt != par){
		dfs1(nxt, at);
		d = max(d, 1+depth[nxt]);
	}
	depth[at]=d;
}
 
void dfs2(int at, int par, int par_ans)
{
	vector<int> prefixMax, suffixMax;
	for(int nxt : G[at])if(nxt != par) prefixMax.push_back(depth[nxt]), suffixMax.push_back(depth[nxt]);
	for(int i=1;i<(int)prefixMax.size();++i) prefixMax[i]=max(prefixMax[i],prefixMax[i-1]);
	for(int i=(int)suffixMax.size()-2;i>=0;--i) suffixMax[i]=max(suffixMax[i],suffixMax[i+1]);
	int c_no = 0;
	for(int nxt : G[at])if(nxt != par){
		const int op1=(c_no==0)?-1:prefixMax[c_no-1];
		const int op2=(c_no==(int)suffixMax.size()-1)?-1:suffixMax[c_no+1];
		const int temp = 1+max(par_ans,max(op1,op2));
		dfs2(nxt,at,temp);
		c_no++;
	}
	ans[at]=1+max(par_ans,(prefixMax.empty()?-1:prefixMax.back()));
}
 
void solve()
{
	dfs1(1, 0);
	dfs2(1,0,-1);
	for(int i=1;i<=n;++i) cout<<ans[i]<<' ';
}
 
int main()
{
	cin >> n;
	for(int i=0;i<n-1;++i){
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
	}
	solve();
	return 0;
}
