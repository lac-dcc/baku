#include<bits/stdc++.h>
#define l long 
#define ll long long 
#define ld long double 
#define MOD 1000000007
#define MAX_N 200006
#define f first 
#define s second 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll inf=1e18;
vector<ll> tree(4l*MAX_N);
vector<ll> dp(MAX_N);
void build(l v,l tl,l tr){
    if(tl==tr){
        tree[v]=dp[tl];
        return;
    }
    l tm=(tl+tr)>>1;
    build(2l*v,tl,tm);
    build(2l*v+1,tm+1,tr);
    tree[v]=max(tree[2l*v],tree[2l*v+1]);
    return;
}
void update(ll val,l pos,l v,l tl,l tr){
    tree[v]+=val-dp[pos];
    if(tl==tr){
        dp[pos]=val;
        return;
    }
    l tm=(tl+tr)>>1;
    if(pos<=tm){
        update(val,pos,2l*v,tl,tm);
    }
    else{
        update(val,pos,2l*v+1,tm+1,tr);
    }
    tree[v]=max(tree[2l*v],tree[2l*v+1]);
}
ll rng_max(l lo,l hi,l v,l tl,l tr){
    if(lo>hi){
        return -1;
    }
    if(lo==tl&&hi==tr){
        return tree[v];
    }
    l tm=(tl+tr)>>1;
    return max(rng_max(lo,min(hi,tm),2l*v,tl,tm),rng_max(max(lo,tm+1),hi,2l*v+1,tm+1,tr));
}
bool compar(pair<ll,pair<ll,ll>> a,pair<ll,pair<ll,ll>> b){
    return (a.s.f<=b.s.f);
}
int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    l n;
    cin>>n;
    vector<pair<ll,pair<ll,ll>>> p(n);
    for(l i=0;i<n;i++){
        cin>>p[i].f>>p[i].s.f>>p[i].s.s;
    }
    sort(p.begin(),p.end(),compar);
    l lo,hi,mid;
    build(1l,0l,n-1);
    ll ans=0,x;
    for(l i=0;i<n;i++){
        lo=-1;
        hi=i;
        while(hi-lo>1){
            mid=(lo+hi)>>1;
            if(p[mid].s.f<p[i].f){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }
        if(lo==-1){
            x=p[i].s.s;
        }
        else{
            x=rng_max(0,lo,1l,0l,n-1)+p[i].s.s;
        }
        update(x,i,1l,0l,n-1);
        ans=max(ans,x);
    }
    cout<<ans<<endl;                   
}