#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define mp make_pair
// GCD inbuilt func: __gcd(a,b)
// LCM formula: (a*b)/__gcd(a,b)
 
void Dfs(const vector<ll> v[], vector<bool>& visited, ll x){
	if(!visited[x]){
		visited[x]=true;
		for(int i=0;i<v[x].size();i++){
			Dfs(v,visited,v[x][i]);
		}
	}
	return;
}
 
void UndirGraph(vector<ll> v[], ll x, ll y){
	v[x].push_back(y);
	v[y].push_back(x);
}
 
int main(){
	// CODE goes here
	ll n,m;
	cin >> n >> m;
	vector<ll> v[n];
	for(ll i=0;i<m;i++){
		ll x,y;
		cin >> x >> y;
		x--;
		y--;
		UndirGraph(v,x,y);
	}
	vector<bool> visited;
	for(ll i=0;i<n;i++) visited.push_back(false);
	ll count=0;
	vector<ll> vertices;
	for(ll i=0;i<n;i++){
		if(visited[i]) continue;
		else{
			vertices.push_back(i);
			Dfs(v,visited,i);
			count++;
		}
	}
	cout << count-1 << "\n";
	ll i=0,j=1;
	while(count>1 && j<vertices.size()){
		cout << vertices[i]+1 << " " << vertices[j]+1 << "\n";
		i++;
		j++;
	}
	return 0;
}