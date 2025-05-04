#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<stack>
#include <queue>
#include<set>
#include<map>
#include<list>
#include<algorithm>
#include<string>
#include <cstring>
#include<unordered_set>
#include<unordered_map>
#define neginf -1000000000000
 
using namespace std;
typedef long long int ll;
//int md = 24738041398529;
//int md = 9007199254740847;
//ll md = 1000000007;
//int inf = pow(10,9);
ll inf = pow(10,17);
 
 
void createsegt(int u, ll segt[], int l, int r, ll pref[]){
    if(l==r){
        segt[u]=pref[l];
    }else{
        int md=l+(r-l)/2;
        createsegt(2*u+1, segt, l, md, pref);
        createsegt(2*u+2, segt, md+1, r, pref);
        segt[u] = max(segt[2*u+1],segt[2*u+2]);
    }
}
 
void update(int u, ll segt1[], ll segt2[], int l, int r, ll& val, int& ind){
    if(segt2[u]!=0){
        segt1[u]+=segt2[u];
        if(l!=r){
            segt2[2*u+1] += segt2[u];
            segt2[2*u+2] += segt2[u];
        }
        segt2[u] = 0;
    }
    if(ind<=l){
        segt1[u]+=val;
        if(l!=r){
            segt2[2*u+1] += val;
            segt2[2*u+2] += val;
        }
    }else if(ind<=r){
        int md = l+(r-l)/2;
        
        update(2*u+1, segt1, segt2, l, md, val, ind);
        update(2*u+2, segt1, segt2, md+1, r, val, ind);
        segt1[u] = max(segt1[2*u+1],segt1[2*u+2]);
    }
}
 
ll query(int u, ll segt1[], ll segt2[], int l, int r, int& p, int& q){
    if(segt2[u]!=0){
        segt1[u]+=segt2[u];
        if(l!=r){
            segt2[2*u+1] += segt2[u];
            segt2[2*u+2] += segt2[u];
        }
        segt2[u] = 0;
    }
    if(q<l || r<p){
//        cout<<l<<" to "<<r<<" returned "<<-inf<<"\n";
        return -inf;
    }else if(p<=l && r<=q){
//        cout<<l<<" to "<<r<<" returned "<<segt1[u]<<"\n";
        return segt1[u];
    }else{
        int md = l+(r-l)/2;
        ll ans = max(query(2*u+1, segt1, segt2, l, md, p, q), query(2*u+2, segt1, segt2, md+1, r, p, q));
//        cout<<l<<" to "<<r<<" returned "<<ans<<"\n";
        return ans;
    }
}
 
ll query2(int u, ll segt1[], ll segt2[], int l, int r, int ind){
//    if(segt2[u]>0){
//        segt1[u]+=segt2[u];
//        if(l!=r){
//            segt2[2*u+1] += segt2[u];
//            segt2[2*u+2] += segt2[u];
//        }
//        segt2[u] = 0;
//    }
    if(l==r){
        return segt2[u]+segt1[u];
    }else{
        int md = l+(r-l)/2;
        if(ind<=md){
            return segt2[u]+query2(2*u+1, segt1, segt2, l, md, ind);
        }else{
            return segt2[u]+query2(2*u+2, segt1, segt2, md+1, r, ind);
        }
    }
}
 
int main(){
    int n,q;
    cin>>n>>q;
    ll x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    ll pref[n];
    pref[0]=x[0];
    for(int i=1;i<n;i++){
        pref[i]=x[i]+pref[i-1];
    }
    ll segt1[4*n+10];
    ll segt2[4*n+10];
    for(int i=0;i<4*n+10;i++){
        segt1[i]=0;
        segt2[i]=0;
    }
    createsegt(0, segt1, 0, n-1, pref);
//    for(int i=0;i<n;i++){
//        cout<<query2(0, segt1, segt2, 0, n-1, i)<<" ";
//    }cout<<"\n";
    while(q--){
        int typ;
        cin>>typ;
        if(typ==1){
            int k;
            ll u;
            cin>>k>>u;
            k--;
            ll val = u-x[k];
            x[k]=u;
            update(0, segt1, segt2, 0, n-1, val, k);
        }else{
            int a,b;
            cin>>a>>b;
            a--;b--;
            ll ans = query(0, segt1, segt2, 0, n-1, a, b);
            if(b>0){
                ans -= query2(0, segt1, segt2, 0, n-1, a-1);
            }
            cout<<max(ans,ll(0))<<"\n";
        }
//        for(int i=0;i<n;i++){
//            cout<<query2(0, segt1, segt2, 0, n-1, i)<<" ";
//        }cout<<"\n";
    }
    
}
