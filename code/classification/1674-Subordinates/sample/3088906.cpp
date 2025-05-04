#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <bitset>
#include <cassert>
using namespace std;
 
typedef long long ll;
const int N = 2e5+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
 
#define deb(x) cout << #x << " " << x << endl;
 
template<typename... T>
void read(T&... args){
	((cin >> args), ...);
}
 
bool lexo_inc(string a, string b) {
	return a < b;
}
 
bool lexo_dec(string a, string b){
	return a > b;
}
 
vector<ll> tree[200001];
 
void solve(ll src, ll par, vector<ll> &subordinate){
 
	ll sub = 0;
	for(ll child: tree[src]){
		if(child != par){
			solve(child, src, subordinate);
			sub += (1 + subordinate[child]);
		}
	}
	subordinate[src] = sub;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;cin >> n;
    vector<ll> subordinate(n+1);
    for(ll i=2;i<n+1;i++){
		ll x;
    	cin >> x;
    	tree[x].push_back(i);
    	tree[i].push_back(x);
    }
   	solve(1,0,subordinate);
 
    for(ll i=1;i<n+1;i++) cout << subordinate[i] << " ";
    	cout << endl;
}
