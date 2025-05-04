#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <unordered_set>
 
#define Bekabot ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define fopen(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define all(x) (x).begin(), (x).end()
#define len(x) (int)x.size()
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define elif else if
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define lb(v,x) (int)(lower_bound(all(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(all(v),x)-v.begin())
 
const int N = 2e5 + 78 , inf = 1e18 , M = 1e9 + 7;
using namespace std;
 
string trans(int n , int k){
    string s = "";
    while(n != 0){
        int d = n % k;
        if(d < 10){
            s = to_string(d) + s;
        }
        else{
            s = char(d + 'A' - 10) + s;
        }
        n /= k;
    }
    return s;
}
int n , sz[N];
vector<int> g[N];
int dfs(int v){
	sz[v]++;
	for(auto to : g[v]){
		sz[v] += dfs(to);
	}
	return sz[v];
}
void skibidi_dop_dop_dop_yes_yes(){
	cin >> n;
	for(int i = 2 ; i <= n ; i++){
		int x;
		cin >> x;
		g[x].pb(i);
	}
	dfs(1);
	for(int i = 1 ; i <= n ; i++)cout << sz[i] - 1 << ' ';
}
 
signed main(){
    Bekabot
    int t = 1;
    //cin >> t;
    while(t--){
		skibidi_dop_dop_dop_yes_yes();
	}
}
