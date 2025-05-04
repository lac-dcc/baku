#include<bits/stdc++.h>
using namespace std;
 
void rec(int node,int par,vector<int> g[],vector<int> &h){
    int subor=0;
    for(int child:g[node]){
		if(child==par) continue;
		rec(child,node,g,h);
		subor+=(1+h[child]);
    }
    h[node]=subor;
}
int main(){
	int n,x;
	cin>>n;
	vector<int> g[n+1];
	for(int i=2;i<=n;++i){
		cin>>x;
		g[i].push_back(x);
		g[x].push_back(i);
	}
	vector<int> h(n+1,0);
	rec(1,0,g,h);
	for(int i=1;i<=n;++i)
		cout<<h[i]<<" ";
	return 0;
}
