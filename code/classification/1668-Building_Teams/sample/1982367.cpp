#include<bits/stdc++.h>
//#include <array>
//#include <unordered_map>
using namespace std;
 
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ar array
 
int n,m;
map<int, vector<int> > gr;
map<int, bool> visited;
map<int, int> group;
 
void init() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
  	cin.tie(0);
}
 
int main() {
	init();
	cin>>n>>m;
	for (int i =0;i<m;i++) {
		int l, r;
		cin>>l>>r;
		gr[l].push_back(r);
		gr[r].push_back(l);
	}
	queue<int> qu;
 
	for(int r=1;r<=n;r++) {
		if (!visited[r]) {
			qu.push(r);
			visited[r]=true;
			group[r] = 1;
			while(!qu.empty()) {
				int q = qu.front();
				qu.pop();
				for (int i: gr[q]) {
					if (!visited[i]) {
						int curgroup = (group[q] == 1) ? 2:1;
						qu.push(i);
						visited[i]=true;
						group[i]=curgroup;
					} else if (group[q] == group[i]) {
						cout<<"IMPOSSIBLE";
						return 0;
					}
				}
			}
		}
	}
	
	for (int i=1;i<=n;i++) cout<<group[i]<<" ";
	return 0;
}
 
 
 
 
 
 
 
