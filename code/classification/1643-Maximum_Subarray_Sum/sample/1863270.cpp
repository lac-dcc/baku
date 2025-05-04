#include <bits/stdc++.h>
using namespace std;
#define     optimize        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define     ll              long long
#define     vll             vector<ll>
#define     all(x)          x.begin(),x.end()
#define     reall(x)        x.rbegin(),x.rend()
#define     pb              push_back
#define     sz(s)           s.size();
#define     fori(i,b,e)     for(int (i)=(b); (i) <= (e); (i)++)
#define     for0(i,n)       for(int (i)=0; (i) < (n); (i)++)
#define     sp(a)           fixed<<setprecision(a)
#define     endl            '\n'
#define     yes             cout << "Yes" << '\n'
#define     no              cout << "No" << '\n'
#define     coutl(x)        cout << x << '\n'
#define     cout(x)         cout << x
#define     nl              cout << '\n'
#define     printv(v)       for(auto it:v) cout << it << " "
#define     CASE(t)         printf("Case %lld: ",++t)
#define     Fall_in_Code    int main(){optimize; int tt; cin >> tt;while(tt--){SakiBee();}return 0;}
#define     S_Fall_in_Code  int main(){optimize; SakiBee();return 0;}
 
 
void Kadans_algo(ll n, vector<ll>& v)
{
	ll mx = INT_MIN, csum = 0;
 
	for0(i,n)
	{
		csum += v[i];
		if(v[i] > csum) csum = v[i];
		if(csum > mx) mx = csum;
	}
	cout << mx << endl;
}
 
 
void SakiBee()
{
	ll n; cin >> n;
	vll v(n);
	for0(i,n) cin >> v[i];
	Kadans_algo(n,v);
}
    
 
 
//Fall_in_Code
S_Fall_in_Code
 
//Wrong doesn't mean bad