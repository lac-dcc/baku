#include<bits/stdc++.h>
#include<vector>  

// ...  

using namespace std;
typedef long long ll;
ll op(ll x,ll y){
    return max(x,y);
}
int main(){
    ll n,q;cin>>n>>q;
    //ll sum[2*n]={0}, pre[2*n]={0};
    vector<ll> sum(2 * n, 0), pre(2 * n, 0);

    auto put=[&](ll k,ll x){
        k+=n;
        sum[k]=x;
        pre[k]=x;
        for(ll i=k/2;i>=1;i/=2){
            sum[i]=sum[2*i]+sum[2*i+1];
            pre[i]=max(pre[2*i],pre[2*i+1]+sum[2*i]);
        }
    };
    auto ss=[&](ll a,ll b){
        a+=n;b+=n;
        ll ans=0;
        ll s=0;
        ll pos=0;
 
        while(a<=b){
            if(a&1){
                ans=max(ans,s+pre[a]);
                s+=sum[a];
                a++;
            }
            if(!(b&1)){
                pos=max(sum[b]+pos,pre[b]);
                b--;
            }
            a/=2;b/=2;
        }
        return max(ans,s+pos);
    };
    
 
    for(ll i=0;i<n;i++){ll x;cin>>x;
    sum[n+i]=x;pre[n+i]=x;}
    for(ll i=n-1;i>0;i--){
        sum[i]=sum[2*i]+sum[2*i+1];
        pre[i]=max(pre[2*i],pre[2*i+1]+sum[2*i]);
    }
 
    while(q--){
        ll op,a,b;cin>>op>>a>>b;
        if(op==1){
            put(a-1,b);
        }else{
            cout<<ss(a-1,b-1)<<"\n";
        }
    }
 
    return 0;
}
