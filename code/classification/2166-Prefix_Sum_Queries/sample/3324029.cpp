//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
 
#define int ll
const int z=2e5+5;
int n,q,sum[z<<2],pre[z<<2];
#define ls rt<<1
#define rs ls|1
void up(int rt){
    sum[rt]=sum[ls]+sum[rs];
    pre[rt]=max({pre[ls],sum[ls]+pre[rs],sum[rt],0LL});
}
void build(int l,int r,int rt){
    if(l==r) return cin>>sum[rt],pre[rt]=sum[rt],void();
    int mid=l+r>>1;
    build(l,mid,ls);build(mid+1,r,rs);
    up(rt);
}
void mdf(int l,int r,int x,int rt,int val){
    if(l==r) return sum[rt]=pre[rt]=val,void();
    int mid=l+r>>1;
    if(x<=mid) mdf(l,mid,x,ls,val);
    else mdf(mid+1,r,x,rs,val);
    up(rt);
}
pii qry(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return mkp(sum[rt],pre[rt]);
    int mid=l+r>>1;
    if(qr<=mid) return qry(l,mid,ql,qr,ls);
    else if(ql>mid) return qry(mid+1,r,ql,qr,rs);
    pii ret,L=qry(l,mid,ql,qr,ls),R=qry(mid+1,r,ql,qr,rs);
    ret.F=L.F+R.F;
    ret.S=max({L.S,L.F+R.S,L.F+R.F,0LL});
    return ret;
}
signed main(){Aincrad
    cin>>n>>q;
    build(1,n,1);
    for(int x,y,k;q--;){
        cin>>k>>x>>y;
        if(k==1) mdf(1,n,x,1,y);
        else cout<<max(0LL,qry(1,n,x,y,1).S)<<"\n";
    }
    return 0;
}
