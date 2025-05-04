#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
 
int main(){
	int n,m;
	cin>>n>>m;
 
	vector<tuple<int,int,int>> edges;
	REP(i,0,m-1){
		int a,b,w;
		cin>>a>>b>>w;
		edges.push_back({a-1,b-1,w});
	}
 
	int x, relaxant[n];
	ll distance[n]; 
	REP(i,0,n-1) distance[i] = 0, relaxant[i] = -1;
 
	REP(i,0,n-1){
		x = -1;
		for(auto e: edges){
			int a,b,w;
			tie(a,b,w) = e;
			if(distance[a] + w < distance[b]){
				distance[b] = distance[a] + w;
				relaxant[b] = a;
				x = b;
			}
		}
	}
 
	if(x == -1) cout<< "NO" << endl;
	else{
		cout<< "YES" << endl;
		REP(i,0,n-1) x = relaxant[x];
 
		stack<int> cycle;
		cycle.push(x);
		int v = relaxant[x];
		while(v != x){
			cycle.push(v);
			v = relaxant[v];
		}
		cycle.push(v);
 
		while(!cycle.empty()){
			cout<<cycle.top()+1<<" ";
			cycle.pop();
		}
	}
}
 
