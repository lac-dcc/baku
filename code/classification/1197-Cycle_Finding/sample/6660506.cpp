#include <iostream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <string_view>
#include <bit>
#include <climits>
#define MOD 1000000007
#define INF LONG_LONG_MAX/2
using namespace std;
typedef long long ll;
 
struct einfo{
	int from, to;
	ll cost;
	einfo(int _from, int _to, ll _cost):from(_from), to(_to), cost(_cost){}
};
 
void solve(void){
	int n, m;
	cin>>n>>m;
	vector<einfo> edg;
	edg.reserve(m);
	for(int i=0;i<m;i++){
		int a, b;
		ll c;
		cin>>a>>b>>c;
		edg.emplace_back(b-1, a-1, c);
	}
	vector<ll> dist(n, INF);
	vector<int> prev(n, -1);
	for(int i=0;i<n;i++){
		if(dist[i]==INF){
			bool done=false;
			dist[i]=0;
			for(int ii=1;ii<=n && !done;ii++){
				done=true;
				for(einfo& x : edg){
					if(dist[x.from]==INF) continue;
					if(dist[x.to]>dist[x.from]+x.cost){
						dist[x.to]=dist[x.from]+x.cost;
						prev[x.to]=x.from;
						done=false;
					}
				}
			}
			if(!done){
				int start;
				for(einfo& x : edg){
					if(dist[x.from]==INF) continue;
					if(dist[x.to]>dist[x.from]+x.cost){
						start=x.to;
						break;
					}
				}
				cout<<"YES\n";
				while(dist[start]!=-1){
					dist[start]=-1;
					start=prev[start];
				}
				int j=start;
				do{
					cout<<j+1<<' ';
					j=prev[j];
				}while(j!=start);
				cout<<start+1<<'\n';
				return;
			}
			
		}
	}
	cout<<"NO\n";
	return;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solve();
	return 0;
}
