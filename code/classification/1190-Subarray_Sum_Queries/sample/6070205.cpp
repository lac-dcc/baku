#include <bits/stdc++.h>
#define ll long long
//#define M 1000000007
#define INF 10000000000
#define PII pair<ll, ll>
#define ff first
#define ss second
 
using namespace std;
 
ll MIN(ll a, ll b){
    return a < b ? a : b;
}
 
ll MAX(ll a, ll b){
    return a > b ? a : b;
}
 
struct node{
    ll maxsum;
    ll lsum;
    ll rsum;
    ll totsum;
};
 
///ARRAY is 1-indexed
node T[1000000];  // at least 2*n size (good to go 4*n, because we use 2*n and 2*n+1 stuffs) for segment trees
 
void combine(ll p, ll L, ll M, ll R){
    // lsum
    T[p].lsum = max(T[2*p].totsum + T[2*p+1].lsum, T[2*p].lsum);
    //rsum
    T[p].rsum = max(T[2*p + 1].totsum + T[2*p].rsum, T[2*p + 1].rsum);
 
    // maxsum
    ll midsum = T[2*p].rsum + T[2*p+1].lsum;
    T[p].maxsum = max(T[2*p].maxsum, max (midsum, T[2*p+1].maxsum));
 
    //totsum
    T[p].totsum = T[2*p].totsum + T[2*p + 1].totsum;
}
// p is the node/segment
void build(vector<ll> &a, ll p, ll L, ll R){
    //base case
    if (L == R){
        ll m = max(0ll, a[L]);
        T[p] = {m, m, m, a[L]};
    }
    else{
        //let us now divide... i.e: for [1, 4] -> [1,2] + [3,4] or [1,5] -> [1,2,3] + [4,5] --> [1, 2] + [3]
        ll mid = (L+R)/2;
        build(a, p*2, L, mid);
        build(a, p*2+1, mid+1, R);
 
        /// now combine from left and right.. this is the combine function part
        combine(p, L, mid, R);
    }
}
 
//update node u -> val
void update(ll p, ll u, ll val, ll L, ll R){
    if (L == R){
        ll m = max(0ll, val);
        T[p] = {m, m, m, val};
    }
    else{
        ll mid = (L+R)/2;
        //we are only updating 1 index... so just go the right direction
        if (u <= mid)
            update(p*2, u, val, L, mid);
        else
            update(p*2+1, u, val, mid +1, R);
 
        combine (p, L, mid, R);
    }
}
 
/*
ll query(ll p, ll ql, ll qr, ll L, ll R){
    // [ql...qr] is outside [L...R]
    if (ql > qr)
        return INF; //returns INF so, doesn't hamper with other part values
 
    if (ql == L && qr == R)
        return T[p];
 
    ll mid = (L+R)/2;
    ll left = query(p*2, ql, MIN(qr, mid), L, mid);
    ll right = query(p*2+1, MAX(ql, mid+1), qr, mid+1, R);
    /// now combine from left and right.. this is the combine function part
    return MAX(left, right);
}
*/
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
 
    build(a, 1, 1, n);  //build Segment Tree
 
    ll u, v;
    while(q--){
        cin >> u >> v;
        //update
        update(1, u, v, 1, n);
        cout << T[1].maxsum << '\n';
    }
    return 0;
}
