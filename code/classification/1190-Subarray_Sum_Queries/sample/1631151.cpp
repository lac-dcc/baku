#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 1e6+1; // 4 * size of array
long long segtree[MAXN];
long long pref[MAXN];
long long suf[MAXN];
long long sum[MAXN];
long long a[MAXN];
void f(long long n) // depends on the problem
{
    pref[n] = max(pref[2*n],sum[2*n]+pref[2*n+1]);
    suf[n] = max(suf[2*n+1],suf[2*n]+sum[2*n+1]);
    segtree[n] = max(segtree[2*n],max(segtree[2*n+1],suf[2 * n] + pref[2 * n + 1]));
    sum[n] = sum[2*n]+sum[2*n+1];
}
void build(int node,int start,int finish)
{
    if(start==finish)
    {
        pref[node] = a[start];
        suf[node] = a[start];
        segtree[node] = a[start];
        sum[node] = a[start];
    }
 
    else
    {
        int mid = (start+finish)/2;
        build(node*2, start,mid);
        build(node*2+1,mid+1,finish);
        f(node);
    }
}
void update(int node,int start,int finish,int idx,long long val)
{
    if(start>idx || finish<idx) return;
    if(start==finish)
    {
        pref[node] = val;
        suf[node] = val;
        segtree[node] = val;
        sum[node] = val;
    }
    else
    {
        int mid = (start+finish)/2;
        update(node*2,start,mid,idx,val);
        update(node*2+1,mid+1,finish,idx,val);
        f(node);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,m;
    cin >> n >> m;
    for(int i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    build(1,0,n-1);
    while(m--)
    {
 
            int i,v;
            cin >> i >> v;
            a[i-1] = v;
            update(1,0,n-1,i-1,v);
            if(segtree[1]>0)
            cout << segtree[1] << '\n';
            else cout << 0 << '\n';
 
    }
}
