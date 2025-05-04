#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <numeric>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <stack>
 
using namespace std;
 
#define ll long
#define ull unsigned long long
#define endl "\n"
#define pb push_back
#define PI 3.1415926535897932384626433832795
const ll MOD = 1e9 + 7;
ll cases = 1;
 
ll solve(vector<ll> &price, vector<ll> &pages, ll ind, ll total, vector<vector<ll> > &dp) {
    if(ind==0) {
        if(price[0]<=total)
            return pages[0];
        return 0;
    }
    if(dp[ind][total]!=-1)
        return dp[ind][total];
    ll notPick = solve(price, pages, ind-1, total, dp);
    ll pick = 0;
    if(price[ind]<=total) {
        pick = pages[ind]+solve(price, pages, ind-1, total-price[ind], dp);
    }
    return dp[ind][total]=max(pick, notPick);
}
 
void sample() {
    ll n, total;
    cin>>n>>total;
    vector<ll> price(n);
    for(ll i=0; i<n; i++) {
        cin>>price[i];
    }
    vector<ll> pages(n);
    for(ll i=0; i<n; i++) {
        cin>>pages[i];
    }
    vector<ll> prev(total+1, 0), curr(total+1, 0);
    for(ll i=price[0]; i<=total; i++) {
        prev[i] = pages[0];
    }
    for(ll i=1; i<n; i++) {
        for(ll j=0; j<=total; j++) {
            ll notPick = prev[j];
            ll pick = INT_MIN;
            if(price[i]<=j)
                pick = pages[i]+prev[j-price[i]];
            curr[j]=max(pick, notPick);
        }
        prev = curr;
    }
    cout<<prev[total];
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        sample();
    }
    return 0;
}
