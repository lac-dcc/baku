#include<bits/stdc++.h>
 
#define all(arr) arr.begin(), arr.end()
using namespace std;
 
typedef long long ll;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<long> vl;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
typedef vector<vi> vii;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
ll inf = 1e18;
int n, m;
 
vector<array<ll, 3>> graph;
 
vi neg_cycle(){
	vll dist(2525);
	vi parent(2525, 0);
	vi path;
	int x;
	for(int i = 0; i < n; i++){
		x = -1;
		for(auto [a, b, c]: graph){
			if(dist[a] < inf){
				if(dist[a] + c < dist[b]){
					dist[b] = max(-inf, dist[a] + c);
					parent[b] = a;
					x = b;
				}
			}
		}
	}
	if(x == -1){
		cout << "NO\n";
	}
	else{
		int y = x;
		for(int i = 1; i <= n; i++)
			y = parent[y];
		cout << "YES\n";
		int curr = y;
		while(true){
			path.push_back(curr);
			curr = parent[curr];
			if(curr == y)
				break;
		}
		reverse(all(path));
		path.push_back(path[0]);
	}
	return path;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	array<ll, 3> t;
    	cin >> t[0] >> t[1] >> t[2];
    	graph.push_back(t);
    }
    vi ans = neg_cycle();
    for(auto x: ans){
    	cout << x << ' ';
    }
    return 0;
}
