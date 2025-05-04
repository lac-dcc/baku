#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int v[200005];
struct dima
{
    int prefmax, sufmax, sum, ans;
}st[800005];
dima combine(dima x, dima y)
{
    dima rez;
    rez.sum=x.sum+y.sum;
    rez.prefmax=max(x.prefmax, x.sum+y.prefmax);
    rez.sufmax=max(y.sufmax, y.sum+x.sufmax);
    rez.ans=max(x.sufmax+y.prefmax, max(x.ans, y.ans));
    return rez;
}
void build(int node, int l, int r)
{
    if(l==r)
    {
        st[node]={v[l], v[l], v[l], max((int)0, v[l])};
        return;
    }
    int mij;
    mij=(l+r)/2;
    build(node*2, l, mij);
    build(node*2+1, mij+1, r);
    st[node]=combine(st[node*2], st[node*2+1]);
}
void update(int node, int l, int r, int poz, int val)
{
    int mij;
    if(l==r)
    {
        v[l]=val;
        st[node]={v[l], v[l], v[l], max((int)0, v[l])};
        return;
    }
    mij=(l+r)/2;
    if(poz<=mij)
    update(node*2, l, mij, poz, val);
    else
    update(node*2+1, mij+1, r, poz, val);
    st[node]=combine(st[node*2], st[node*2+1]);
}
signed main()
{
    int n, m, l, r, s=0, start=1, t=INT_MIN, p, x;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
        update(1, 1, n, i, v[i]);
    }
    for(int i=1; i<=m; i++)
    {
        cin>>p>>x;
        update(1, 1, n, p, x);
        cout<<st[1].ans<<'\n';
    }
 
    return 0;
}
