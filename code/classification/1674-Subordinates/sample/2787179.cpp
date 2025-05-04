#include <bits/stdc++.h>
using namespace std;
#define fop(i, a, b) for(int i = a; i < b; i++)
#define fopp(i, a, b) for(int i = a; i < b; i+=2)
#define rfop(i, a, b) for(int i = a; i > b; i--)
#define pb push_back
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
const int MOD = 1e9 + 7;
vector<vector<int> > e;
vector<int> vis,cnt;
void dfs(int i){
	for(auto a:e[i]){
		if(!vis[a]){
			cnt[i]++;
			vis[a]=1;
			dfs(a);
			cnt[i]+=cnt[a];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    e.resize(n);
    cnt.assign(n,0);
    vis.assign(n,0);
    fop(i,0,n-1){
    	int x; cin>>x;
    	x--;
    	e[x].pb(i+1);
	}
	fop(i,0,n){
		if(!vis[i]){
			vis[i]=1; dfs(i);
		}
	}
	fop(i,0,n) cout<<cnt[i]<<' ';
}
