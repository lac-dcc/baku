#include<bits/stdc++.h>
 
#define     ll          long long
#define     ld          long double
#define     sz(s)       s.size()
#define     pb          push_back
#define     ff          first
#define     ss          second
#define     mk          make_pair
#define     pii         pair<int, int>
#define     pll         pair<long long int, long long int>
#define     ALL(s)      (s).begin(), (s).end()
#define     rALL(s)     (s).rbegin(), (s).rend()
#define     fast        ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     show(x)     cout << #x << " : "<< x << endl;
#define     F(ii, n)       for(int i=ii; i<n; i++)
#define     vii(v,n)    for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define     vll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
 
#define     rPQ         vector<int>, greater<int> /// 1 2 3 4 priority queue
#define     rARR        greater<int>()
#define     cPQ         priority_queue <int>()   /// clear priority queue
#define     limit       -pow(2, 32)
const ll N = 1e5 + 5;
using namespace std;
 
/**************************************************FUNCTION***********************************************************/
void primeFactor(vector<ll>&v, ll n){ll i = 2;while(n!=1){bool ok = false;while(n%i==0 && n!=1){n/=i;ok =true;}if(ok) v.pb(i);++i;}}
void seive(vector<ll>&v, ll n){v.pb(n);for(int i=2; i*i <= n ; i++){if(n%i==0){if(n/i != i)v.pb(n/i);v.pb(i);}}}
ll lcm(ll a, ll b){return a / __gcd(a, b) * b;}
/*****************************************************END*************************************************************/
 
 
 
 
int main()
{
  int tc=1;
  //cin >> tc;
  g:
  while(tc--)
  {
      int n, m, k;
      cin >> n >> m >> k;
      ll a[n], b[m];
      F(0, n) cin >> a[i];
      F(0, m) cin >> b[i];
 
      sort(a, a+n);
      sort(b, b+m);
 
 
 
      ll ans=0, j=0;
     for(int i=0; i<n; i++){
        if(j>=m) break;
        for(; j<m ;){
            if(b[j] >= a[i]-k && b[j] <= a[i]+k){
                ++ans;
                ++j;
                break;
            }
            else if(a[i]+k > b[j]){
 
                //show(i);
                ++j;
            }
            else if(a[i]+k < b[j]){
                break;
            }
 
        }
      }
      cout << ans << endl;
  }
}
