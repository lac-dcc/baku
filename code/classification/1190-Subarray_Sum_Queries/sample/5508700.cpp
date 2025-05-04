#include<bits/stdc++.h>
#include<random>
using namespace std;
 
template<typename T> void _do(T x){cerr<<x<<"\n";}
template<typename T,typename ...U> void _do(T x,U ...y){cerr<<x<<", ";_do(y...);}
#define dbg(...) cerr<<#__VA_ARGS__<<" = ";_do(__VA_ARGS__);
 
#define float double
#define ss(n) fixed<<setprecision(n) 
#define ll long long
#define int ll
#define IO ios::sync_with_stdio(false);cin.tie(0);
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define rep(i,a) for(int i=1;i<=a;i++)
#define rep0(i,a) for(int i=0;i<a;i++)
#define F first
#define S second
#define uni(a) a.resize(distance(a.begin(),unique(a.begin(),a.end())));
#define unisort(a) sort(a.begin(),a.end()); uni(a);
 
ll gcd(ll a,ll b){if(b==0) return a; return gcd(b,a%b);}
 
const ld pi=3.14159265358979323846264338327950288419716939931;
const int lar=3e18;
const int mol1=1e9+7;
const int mol2=998244353;
const int MX=2e5+5;
 
int a[200005],seg[800005],segl[800005],segr[800005];
int sum[800005];
 
void build(int l,int r,int ind){
    if(l==r){
        seg[ind]=a[l];segl[ind]=a[l],segr[ind]=a[l];
        sum[ind]=a[l];
        return;
    }
    int mid=l+r>>1;
    build(l,mid,ind*2);build(mid+1,r,ind*2+1);
    seg[ind]=max({seg[ind*2],seg[ind*2+1],segr[ind*2]+segl[ind*2+1]});
    segl[ind]=max(segl[ind*2],sum[ind*2]+segl[ind*2+1]);
    segr[ind]=max(segr[ind*2+1],sum[ind*2+1]+segr[ind*2]);
    sum[ind]=sum[ind*2]+sum[ind*2+1];
}
 
void upd(int l,int r,int ind,int ii,int vv){
    if(l==r) {
        seg[ind]=a[l];segl[ind]=a[l],segr[ind]=a[l];
        sum[ind]=a[l];
        return;
    }
    int mid=l+r>>1;
    if(ii<=mid) upd(l,mid,ind*2,ii,vv);
    else upd(mid+1,r,ind*2+1,ii,vv);
    seg[ind]=max({seg[ind*2],seg[ind*2+1],segr[ind*2]+segl[ind*2+1]});
    segl[ind]=max(segl[ind*2],sum[ind*2]+segl[ind*2+1]);
    segr[ind]=max(segr[ind*2+1],sum[ind*2+1]+segr[ind*2]);
    sum[ind]=sum[ind*2]+sum[ind*2+1];
}
 
void solve()
{
    int n,q;
    cin>>n>>q;
    rep(i,n) cin>>a[i];
    build(1,n,1);
    rep(i,q){
        int g,h;
        cin>>g>>h;
        a[g]=h;
        upd(1,n,1,g,h);
        cout<<max(0LL,seg[1])<<"\n";
    }
}
 
signed main()
{
    IO
    solve();
    return 0;
}
