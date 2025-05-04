// all problems and thats it
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define fr(i,a,b) for(int i = a; i <= b; i++)
 
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
 
using namespace std;
ll mod=1e18;
long double pi=3.14159265359;
long double eps=0.000000001;
ll MOD=998244353;
 
 
struct data1
{
    ll sum,l,ans;
};
 
data1 dumb;
 
 
const int  N=3e6+2;
ll a[N];
data1 tree[4*N];
ll fn(ll n1,ll n2){return max(n1,n2);}
 
void build(int node,int st,int en){
    if(st==en){
        tree[node].sum=a[st];
        tree[node].l=a[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
 
    tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
    tree[node].l=max(tree[2*node].l,tree[2*node].sum+tree[2*node+1].l);
 
 
}
 
 
data1 query(int node,int st,int en,int left,int right){
    if(en<left||right<st){return       dumb;}
    if(left<=st&&en<=right){return tree[node];}
    // the main part----->
    int mid=(st+en)/2;
 
    data1 p1=query(2*node,st,mid,left,right);
    data1 p2=query(2*node+1,mid+1,en,left,right);
    data1 x;
    x.l=max(p1.l,p1.sum+p2.l);
    x.sum=p1.sum+p2.sum;
    return x;
 
}
 
 
 
void update(int node,int st,int en,int idx,ll val){
    if(st==en){
        a[st]=val;
        tree[node].l=val;
        tree[node].sum=val;
        return;
    }
    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx,val);
    }
    else{
        update(2*node+1,mid+1,en,idx,val);
    }
 
    tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
    tree[node].l=max(tree[2*node].l,tree[2*node].sum+tree[2*node+1].l);
 
}
 
 
 
 
 
void f()
{
 
dumb.ans=0;
dumb.l=0;
int n,q;cin>>n>>q;
for(int i=1;i<=n;i++){cin>>a[i];}
build(1,1,n);
while(q--)
{
    int t;cin>>t;
    if(t==1)
    {
        int pos,val;cin>>pos>>val;
        update(1,1,n,pos,val);
    }
    else{
        int n1,n2;cin>>n1>>n2;
        cout<<max((ll)0,query(1,1,n,n1,n2).l)<<"\n";
 
    }
}
 
 
 
 
}
 
int main() {
 
 
 
 
 
   fast_io;
 
 
 
 
 
 
 
 
 
 
	int t=1;
	while(t--)
    {
        f();
        cout<<"\n";
    }
 
 
 
 
 
 
 
 
 
}
