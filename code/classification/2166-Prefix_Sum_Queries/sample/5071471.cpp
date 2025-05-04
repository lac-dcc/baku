/**
 * @file code.cpp
 * @author Prathik p kulkarni
 *
 */
#include <bits/stdc++.h>
#include<iostream>
//#include <ext/pb_ds/tree_policy.hpp>
using  namespace  std;
using namespace std::chrono;
//using namespace __gnu_pbds;
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
//#define rbtree tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pbb pop_back
#define bahut_tez  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define i64 int64_t
#define all(x) (x).begin(), (x).end()
#define INF 1e18
#define PI double(2 * acos(0.0))
#define ss second
#define ff first
#define pi pair<int,int>
#define pll pair<ll,ll> 
#define vi vector<int>
#define vll vector<ll>
#define V vector
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<"\n";_print(x);cerr<<endl;
#else
#define debug(x)
#endif
 
void _print(pair<int,int>p){cerr<<"["<<p.ff<<","<<p.ss<<"]";}
void _print(int x){cerr<<x;}
void _print(ll x){cerr<<x;}
void _print(string& x){cerr<<x;}
void _print(char x){cerr<<x;}
template<class T>void _print(vector<T>&v){cerr<<"[ ";for(T i:v){_print(i);cerr<<" ";}cerr<<"]\n";}
template<class T>void _print(set<T>&st){cerr<<"[ ";for(T i:st){_print(i);cerr<<" ";}cerr<<"]\n";}
 
ll gcd(ll a,ll b){if(b==0)return a;else return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll ceil(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll binpow(ll a,ll b){ll res = 1;while(b!=0){if(b%2){res*=a;}a*=a;b/=2;}return res;}
ll binmod(ll a,ll b,ll m){a %= m;ll res = 1;while (b > 0) {if (b & 1)res = res * a % m;a = a * a % m;b >>= 1;}return res;  }
//if m is prime
ll modinv(ll a,ll m){return binmod(a,m-2,m);}
 
struct item{
    long long pref,sum;
};
 
struct segtree{
    int size;
    vector<item>sums;
    item NEUTRAL = {0,0};
    void init(int n){
        size = 1;
        while(size<n)size*=2;
        sums.resize(2*size);
    }
    item single(int v){
        if(v>0){
            return {v,v};
        }else{
            return {0,v};
        }
    }
    item merge(item s1,item s2){
        item res;
        res.pref = max(s1.pref,s1.sum+s2.pref);
        res.sum = s1.sum+s2.sum;
        return res;
    }
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)(a.size())){
                sums[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x] = merge(sums[2*x+1],sums[2*x+2]);
    }
    void build(vector<int>&a){
        build(a,0,0,size);
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            sums[x] = single(v);
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x] = merge(sums[2*x+1],sums[2*x+2]);
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    item max_seg(int l,int r,int x,int lx,int rx){
        if(l>=rx || lx>=r)return NEUTRAL;
        if(lx>=l && rx<=r)return sums[x];
        int m = (lx+rx)/2;
        item  s1 = max_seg(l,r,2*x+1,lx,m);
        item  s2 = max_seg(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }
    item max_seg(int l,int r){
            return max_seg(l,r,0,0,size);
    }
};
 
void solve(int T){
	int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int& i:v)cin>>i;
    segtree st;
    st.init(n);
    st.build(v);
    while(m--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            st.set(l-1,r);
        }else{
            cout<<st.max_seg(l-1,r).pref<<"\n";
        }
    }
}
 
int main(){
    bahut_tez;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("Error.txt","w",stderr);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve(t);
    }
    return 0;
 }
