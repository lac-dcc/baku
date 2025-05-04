#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
 
#define mod 1000000007
#define ar array
#define one(x)   __builtin_popcountll(x)
#define zero(x)  __builtin_ctzll(x)
#define pii pair<ll,ll>
#define all(x) (x).begin(), (x).end()
#define removeDuplicates(a) a.resize(unique(all(a))-a.begin())
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
typedef long long int  ll;
const int mxn = 1e6 + 10;
 
 
 
/*vector<pii> que[mxn];
map<int,int> m;
int t[4*mxn];
 
int ans[mxn];
int v[mxn];
 
 void build(int nod,int l,int r){
     if(l==r){
         t[nod]=v[l];
         return ;
     }
     int med=(l+r)>>1;
     build(nod*2,l,med);
     build(nod*2+1,med+1,r);
     t[nod]=t[2*nod]^t[2*nod+1];
 }
 
void update(int nod,int l,int r,int poz,int val)
{
    if(poz<l || poz>r){
         return;
    }
    if(l==r)
    {
        t[nod]=val;
        return ;
    }
    int med=(l+r)>>1;
    //if(poz<=med) update(2*nod,l,med,poz,val);
    //else update(2*nod+1,med+1,r,poz,val);
    update(2*nod,l,med,poz,val);
    update(2*nod+1,med+1,r,poz,val);
    t[nod]=t[2*nod]+t[2*nod+1];
}
int query(int nod,int l,int r,int a,int b)
{
    if(b < l || a > r){
        return 0;
    }
    if(a<=l and r<=b){
        return t[nod];
    }
    int med=(l+r)>>1;
    int ans1=0,ans2=0;
    //if(a<=med) ans1=query(2*nod,l,med,a,b);
    //if(b>med) ans2=query(2*nod+1,med+1,r,a,b);
    ans1=query(2*nod,l,med,a,b);
    ans2=query(2*nod+1,med+1,r,a,b);
    return ans1+ans2;
}
*/
 
 
/*
ll kmp[mxn], num;
 
void kmp_preprocess(string P) {
    ll i = 0, j = -1; kmp[0] = -1;
    while (i < P.size()) {
        while (j >= 0 && P[i] != P[j]) j = kmp[j];
        i++; j++;
        kmp[i] = j;
    }
}
 
void kmp_search(string S, string P) {
    ll i = 0, j = 0;
    while (i < S.size()) {
        while (j >= 0 && S[i] != P[j]) j = kmp[j];
        i++; j++;
        if (j == P.size()) { // find a match at index i - j
            num++;
            j = kmp[j];
        }
    }
}*/
 
ll n, k;
ll a[21];
 
ll sum(ll x, ll y){
    if(y==k){
        if(x==1){return 0;}
        return n/x;
    }
    if(x*a[y]%a[y]){
        return -sum(x, y+1);
    }
    return sum(x*a[y], y+1)-sum(x, y+1);
}
 
void subMain(){
    cin >> n >> k;
    for(ll i = 0; i< k; i++){
        cin >> a[i];
    }
    cout << abs(sum(1, 0));
}
 
 
int main()
{
 
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	/*ll t; cin >> t;
	for (ll i = 1; i <= t; i++) {
        // cout << "Case #" << i  << ": ";
        subMain();
	}*/
	subMain();
	cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
	return 0;
}