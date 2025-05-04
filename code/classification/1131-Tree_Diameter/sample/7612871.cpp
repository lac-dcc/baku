#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld=long double;
 
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
 
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
const int N=2e5+5;
vector<int> adj[N];
int len[N];
 
 
void solve(){
	int n;
	cin>>n;
	if (n==1){
		cout<<0;
		return;
	}
	for (int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	queue<int> q;
	q.push(1);
	while (!q.empty()){
		int x=q.front();
		q.pop();
		for (int y:adj[x]){
			if (y!=1&&len[y]==0){
				len[y]=len[x]+1;
				q.push(y);
			}
		}
	}
	int mx=0,id;
	for (int i=2;i<=n;i++){
		if (len[i]>mx){
			mx=len[i];
			id=i;
		}
	}
	q.push(id);
	memset(len,0,sizeof(len));
	while (!q.empty()){
		int x=q.front();
		q.pop();
		for (int y:adj[x]){
			if (y!=id&&len[y]==0){
				len[y]=len[x]+1;
				q.push(y);
			}
		}
	}
	int res=0;
	for (int i=1;i<=n;i++) {res=max(res,len[i]);}
	cout<<res;
	
	
	
	
	
	
}
 
 
int main(){
	//setIO("");
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int tc=1;
	//cin>>tc;
	while (tc--){
		solve();
	}
}
