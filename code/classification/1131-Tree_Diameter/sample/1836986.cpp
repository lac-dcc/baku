#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long 
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define double      long double
#define pb          push_back
#define pf          push_front
 
const int MOD = 1e9+7;
const int inf=1e18;
 
bool isprime(int n){
	if(n==1) return false;
	for(int i = 2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
	
int lcm(int a,int b){
	return (a*b)/__gcd(a,b);
}
 
int gcd(int a, int b){ 
    if (b == 0){
    	return a;
	} 
    return gcd(b, a % b);  
      
}
 
struct node{
	int x,y;
};
 
int n;
vector<int> graph[200005];
 
pair<int,int> bfs(int node){
	vector<bool> visit(200005,false);
	queue<pair<int,int>> q;
	q.push({node,0});	
	pair<int,int> pr;
	while(!q.empty()){
		pr = q.front();
		q.pop();
		visit[pr.first] = true;
		for(auto x: graph[pr.first]){
			if(!visit[x]){
				q.push({x,pr.second+1});
			}
		}
		//cout<<pr.second<<" ";
	}
	return pr;	
}
 
signed main(){
	FAST
	cin>>n;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);		
	}
	
	pair<int,int> p1 = bfs(1);
	//cout<<"p1 "<<p1.first<<" "<<p1.second<<" ";
	pair<int,int> p2 = bfs(p1.first);
	cout<<p2.second<<endl;
}
