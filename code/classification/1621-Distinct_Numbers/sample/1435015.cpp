#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define mkp make_pair
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
#define all(x) x.begin(),x.end()
#define lun(x) (int)x.size()
typedef long long ll;
typedef long double ld;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=(1LL<<60);
const int inf=(1<<30);
const int nmax=5e5+50;
const ll mod=998244353;
using namespace std;
 
int n, i, ans, x;
vector <int> a;
int main()
{
    //freopen("sol.in","r",stdin);
    //freopen("sol.out","w",stdout);
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
   	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
   	cin >> n;
   	for(i = 0; i<n; i++){
        cin >> x;
        a.pb(x);
   	}
   	sort(a.begin(), a.end());
   	int cur = a[0];
    for(i = 1; i<n; i++){
        if(a[i] != cur){
            ans++;
            cur = a[i];
        }
    }
   	cout << ans + 1<< endl;
    return 0;
}