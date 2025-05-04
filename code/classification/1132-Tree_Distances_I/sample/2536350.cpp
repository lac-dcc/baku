#include <bits/stdc++.h>
#include <math.h>
#define FAST_IO cin.tie(0);ios_base::sync_with_stdio(false)
#define TEST int t;cin>>t;while(t--)
#define mp make_pair
#define pb push_back
#define rep(i, b, n) for (int i = b; i < n; i++)
#define drep(i, s, e) for (int i = s; i > e; i--)
#define ll long long
#define debug(x) cout<<(#x)<<" "<<x<<endl;
#define N 200001
 
using namespace std;
 
vector<vector<int>> g(N);
vector<pair<int,int>> mx1(N);
vector<pair<int,int>> mx2(N);
 
 
int dfs1(int i,int p){
	vector<pair<int,int>> mx={{0,i},{0,i}};
	for(int j:g[i]){
		if(j!=p){
			int tmp = dfs1(j,i);
			if(tmp>mx[0].first){mx[1] = mx[0];mx[0].first = tmp;mx[0].second = j;}
			else if(tmp>mx[1].first){mx[1].first = tmp;mx[1].second = j;}
		}
	}
	mx[0].first++;mx[1].first++;
	mx1[i] = mx[0];
	mx2[i] = mx[1];
	return mx[0].first;
}
 
void dfs2(int i,int p){
	if(mx1[p].first+1>mx1[i].first&&mx1[p].second!=i){
		mx2[i] = mx1[i];
		mx1[i].first = mx1[p].first+1;mx1[i].second=p;
		if(mx2[p].first+1>mx2[i].first&&mx2[p].second!=i){
			mx2[i].first = mx2[p].first+1;mx2[i].second = p;
		}
	}
	else if(mx1[p].first+1>mx2[i].first&&mx1[p].second!=i){
		mx2[i].first = mx1[p].first+1;mx2[i].second = p;
	}
	else if(mx2[p].first+1>mx1[i].first&&mx2[p].second!=i){
		mx2[i] = mx1[i];
		mx1[i].first = mx2[p].first+1;
		mx1[i].second = p;
	}
	else if(mx2[p].first+1>mx2[i].first&&mx2[p].second!=i){
		mx2[i].first = mx2[p].first +1;
		mx2[i].second = p;
	}
	else{
		if(mx1[i].first==1){
			if(mx1[p].second!=i) {mx1[i].first = 1+mx1[p].first;mx1[i].second = p;}
			else if(mx2[p].second!=i) {mx1[i].first = 1+mx2[p].first;mx1[i].second = p;}
		}
		else if(mx2[i].first==1){
			if(mx1[p].second!=i) {mx2[i].first = 1+mx1[p].first;mx2[i].second = p;}
			else if(mx2[p].second!=i) {mx2[i].first = 1+mx2[p].first;mx2[i].second = p;}
		
		}
	}
	for(int j:g[i]){
		if(j!=p){
			dfs2(j,i);
		}
	}
}
 
int main()
{
	FAST_IO;
    	int n;cin>>n;
	rep(i,0,n-1){int x,y;cin>>x>>y;g[x].pb(y);g[y].pb(x);}			
 
	dfs1(1,0);
	dfs2(1,0);
	rep(i,1,n+1){ cout<<max(mx1[i].first,mx2[i].first)-1<<" ";}
	cout<<endl;
}
