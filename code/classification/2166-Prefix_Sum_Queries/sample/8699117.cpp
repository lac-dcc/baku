#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
 
array<int,2> st[800005];
int arr[200005];
//0   ,  1
//sum , mxprf
int n;
void build(int l,int r,int ni)
{
    if(l == r)
    {
        st[ni][0]=arr[l];
        st[ni][1]=max(0ll,arr[l]);
        return;
    }
    int m=(l+r)/2;
    build(l,m,ni*2);build(m+1,r,ni*2+1);
    st[ni][0] = st[ni*2][0]+st[ni*2+1][0];
    st[ni][1] = max(st[ni*2][1],st[ni*2][0]+st[ni*2+1][1]);
 
}
void upd(int l,int r,int ind,int val,int ni)
{
    if(ind<l || ind>r)return;
    if(l == r)
    {
        arr[l]=val;
        st[ni][0]=arr[l];
        st[ni][1]=max(0ll,arr[l]);
        return;
    }
    int m=(l+r)/2;
    upd(l,m,ind,val,ni*2);upd(m+1,r,ind,val,ni*2+1);
    st[ni][0] = st[ni*2][0]+st[ni*2+1][0];
    st[ni][1] = max(st[ni*2][1],st[ni*2][0]+st[ni*2+1][1]);
}
array<int,2> query(int l,int r,int ql,int qr,int ni)
{
    if(ql>r || qr<l)
    {
        return {0,0};
    }
    if(l>=ql && r<=qr)return st[ni];
    int m=(l+r)/2;
    array<int,2>a,b;
    a=query(l,m,ql,qr,ni*2);
    b=query(m+1,r,ql,qr,ni*2+1);
    array<int,2>ret;
    ret[1] = max(a[0]+b[1],a[1]);
    ret[0] = a[0]+b[0];
    return ret;
 
}
void solve()
{
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build(1,n,1);
    while(q--)
    {
        int t,a,b;
        cin>>t>>a>>b;
        if(t == 1)
        {
            upd(1,n,a,b,1);
        }
        else
        {
            cout<<query(1,n,a,b,1)[1]<<endl;
        }
    }
}
int32_t main()
{
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t=1;
    //cin>>t;
    while(t--)
    {
       solve();
    }
}
