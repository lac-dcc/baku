#include <bits/stdc++.h>
using namespace std;
/*
	__________   _____     _________   __            __    __________    ________     _________
	----------  | ----\    ---------   \ \   		/ /    |  _______|	| _____  \    ---------
		||      ||    ||  	  ||		\ \		   / /	   | |			| |		\ \	     ||
		||      ||____//      ||		 \ \      / /	   | |_____ 	| |		 | |	 ||
		||      |__ __/       ||		  \ \    / /	   | _____|		| |		 | |	 ||
		||      || \\         ||		   \ \  / /	   	   | |			| |		 | |	 ||
		||      ||  \\     ___||____        \ \/ /         | |_______ 	| |_____/ /   ___||____
		||		|| 	 \\    _________         \__/		   |_________|	|________/	  _________
*/
/********************************************************************/
/*
Codeforces : @a.trivedi
Codechef   : @adityat25
HackerRank : @adityatrivedi
 
/********************************************************************/
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPR(i,a,b) for(ll i=b-1;i>=a;i--)
#define forr(i,n) for(ll i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define DB pop_back
#define mp make_pair
#define MT make_tuple
#define V(a) vector<a>
#define vi vector<ll>
#define endl '\n'
#define ce(ele) cout<<ele<<' '
#define cs(ele) cout<<ele<<'\n'
#define CASE(t) ll t; cin>>t; while(t--)
/********************************************************************/
const double pi = 3.1415926535;
/********************************************************************/
//FAST IO//
void FAST() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 
/********************************************************************/
int main() {
	FAST();
 
	ll na, nh, md;
	cin >> na >> nh >> md;
	vi sizes_req(na);
	vi sizes_actual(nh);
	for (auto &x : sizes_req) {
		cin >> x;
	}
	for (auto &x : sizes_actual) {
		cin >> x;
	}
	sort(sizes_actual.begin(), sizes_actual.end());
 
	sort(sizes_req.begin(), sizes_req.end());
	// for (auto x : sizes_req) {
	// 	cout << x << " ";
	// }
	// cout << endl;
	// for (auto x : sizes_actual) {
	// 	cout << x << " ";
	// }
	//cout << endl;
	ll ans = 0, i = 0, j = 0;
	for (int i = 0; i < na && j < nh ; i++) {
		//cout << sizes_req[i] << " " << sizes_actual[j] << " are being compared" << endl;
		if (abs(sizes_req[i] - sizes_actual[j]) <= md) {
			ans++;
			j++;
		}
		else if (sizes_req[i] > sizes_actual[j] + md) {
			j++;
			i--;
		}
		else if (sizes_req[i] < sizes_actual[j] - md) {
			//foo
		}
	}
	cout << ans << endl;
	return 0;
}
