#include <iostream>
#include<math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <deque>
#include <random>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <tuple>
#include <thread>
typedef long long ll;
using namespace std;
 
const ll mod = 1e9+7;
const ll inf = 1e18+1e17;
 
int bitcount(ll n) { return n == 0 ? 0 : bitcount(n & (n - 1)) + 1;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
ll binexp(ll a, ll b){
    if (!b) return 1;
    ll res = binexp(a, b/2);
    res = (res*res)%mod;
    if(b%2) res = (res*a)%mod;
    return res;
}
ll rev(ll x) {return binexp(x, mod - 2);}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, s;
    cin >> n >> s;
    unordered_map<ll,ll> cnt_left, cnt_right;
    //set<ll> all;
    vector<ll> a(n);
    for(int i =0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    //ll mx = 0;
 
    int len_left = n/2;
    for(int mask = 0; mask<(1<<len_left);mask++){
        ll cur = 0;
        for(int bit = 0;bit<len_left;bit++){
            if (cur>s) {
                cur=inf;
                break;
            }
            if(mask&(1<<bit)) cur+=a[bit];
        }
        //mx = max(mx,cur);
        if(cur<=s)cnt_left[cur]++;
    }
    ll ans = 0;
    for(int mask = 0;mask<(1<<(n-len_left));mask++){
        ll cur = 0;
        for(int bit = 0; bit<n-len_left;bit++){
            if(mask&(1<<bit)){
                cur+=a[bit+len_left];
            }
        }
        if(cnt_left.find(s-cur)!=cnt_left.end()) ans+=cnt_left[s-cur];
    }
    
    // for(auto [c,x] : cnt_left){
    //     if(c>s) break;
    //     ans+=1ll*x*cnt_right[s-c];
    // }
    cout << ans << endl;
}
