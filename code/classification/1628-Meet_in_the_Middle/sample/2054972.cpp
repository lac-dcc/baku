#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FOR(i, x, n) for(int i = x; i < n; ++i)
#define REP(i, n) for(int i = 0; i < n; ++i)
#define TRACE(x) cerr << #x << " " << x << endl;
#define endl "\n"
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MOD = 1e9+7;
const int inf = 2147483647;
 
int n;
int a[41];
vector<int> sums1, sums2, f1, f2, c1, c2;
ll csum;
ll x;
ll cnt;
int mask, half;
int main(){
//	ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> x;
    REP(i, n) cin >> a[i];
    half = n/2;
    mask = 0;
    while(1){
    	csum = 0;
    	REP(i, half){
    		if((1 << i) & mask){
    			csum += a[i];
			}
		}
		if(csum <= x) sums1.push_back(csum);
		if(__builtin_popcount(mask) == half) break;
    	mask++;
	}
	mask = 0;
	while(1){
		csum = 0;
		for(int i = half; i <= n; ++i){
			if(1 << (i-half) & mask){
				csum += a[i];
			}
		}
		if(csum <= x) sums2.push_back(csum);
		if(__builtin_popcount(mask) == n-half) break;
		mask++;
	}
	sort(sums1.begin(), sums1.end());
	sort(sums2.begin(), sums2.end());
	f1.push_back(sums1[0]);
	f2.push_back(sums2[0]);
	c1.push_back(1);
	c2.push_back(1);
	FOR(i, 1, sums1.size()){
		if(sums1[i] == f1[f1.size()-1]){
			c1[c1.size()-1]++;
		}
		else{
			f1.push_back(sums1[i]);
			c1.push_back(1);
		}
	}
	FOR(i, 1, sums2.size()){
		if(sums2[i] == f2[f2.size()-1]){
			c2[c2.size()-1]++;
		}
		else{
			f2.push_back(sums2[i]);
			c2.push_back(1);
		}
	}
	int p1 = 0, p2 = f2.size()-1;
	for(; p1 < f1.size(); ++p1){
		while(f1[p1] + f2[p2] > x){
			p2--;
			if(p2 < 0) break;
		}
		if(p2 < 0) break;
		if(f1[p1] + f2[p2] == x){
			cnt += ((ll)c1[p1] * (ll)c2[p2]);
		}
	}
	cout << cnt;
	return 0;
}
 
