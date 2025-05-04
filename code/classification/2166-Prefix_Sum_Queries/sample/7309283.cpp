#include <bits/stdc++.h>
 
using namespace std;
//ifstream in("1.in");
//ofstream out ("1.out");
long long v[200008],aint1[2000008],cc[200008];
pair<long long,long long> aint[2000008];
void b1(long long node,long long left,long long right)
{
    if(left == right)
    {
        aint1[node] = cc[left];
        return;
    }
    long long mid = (left + right) / 2;
    b1(2 * node, left,mid);
    b1(2 * node + 1,mid + 1, right);
    aint1[node] = aint1[2 * node] + aint1[2 * node + 1];
}
void u1(long long node,long long left,long long right,long long pos, long long t)
{
    if(left == right)
    {
        aint1[node] = t;
        return;
    }
    long long mid = (left + right) / 2;
    if(pos <= mid)
    {
        u1(2 * node, left,mid,pos,t);
    }
    else
    {
        u1(2 * node + 1,mid + 1, right,pos,t);
    }
    aint1[node]= aint1[2 * node] + aint1[2 * node + 1];
}
void q1(long long node,long long left,long long right,long long a,long long b, long long &ans)
{
    if(a <= left && right <= b)
    {
        ans = ans + aint1[node];
        return;
    }
    long long mid = (left + right) / 2;
    if(a <= mid)
    {
        q1(2 * node, left,mid,a,b,ans);
    }
    if(b > mid)
    {
        q1(2 * node + 1,mid + 1, right,a,b,ans);
    }
}
void build(long long node,long long left,long long right)
{
    if(left == right)
    {
        aint[node].first = v[left];
        return;
    }
    long long mid = (left + right) / 2;
    build(2 * node, left,mid);
    build(2 * node + 1,mid + 1, right);
    aint[node].first = max(aint[2 * node].first,aint[2 * node + 1].first);
}
void propagate(long long node, long long left,long long right)
{
    if(left!= right)
    {
        aint[2 * node].first += aint[node].second;
        aint[2 * node + 1].first += aint[node].second;
 
        aint[2 * node].second += aint[node].second;
        aint[2 * node + 1].second += aint[node].second;
    }
    aint[node].second = 0;
}
void update(long long node,long long left,long long right,long long a,long long b, long long t)
{
    propagate(node,left,right);
    if(a <= left && right <= b)
    {
        aint[node].first += t;
        aint[node].second += t;
        return;
    }
    long long mid = (left + right) / 2;
    if(a <= mid)
    {
        update(2 * node, left,mid,a,b,t);
    }
    if(b > mid)
    {
        update(2 * node + 1,mid + 1, right,a,b,t);
    }
    aint[node].first = max(aint[2 * node].first,aint[2 * node + 1].first);
}
void query(long long node,long long left,long long right,long long a,long long b, long long &ans)
{
    propagate(node,left,right);
    if(a <= left && right <= b)
    {
        ans = max(ans,aint[node].first);
        return;
    }
    long long mid = (left + right) / 2;
    if(a <= mid)
    {
        query(2 * node, left,mid,a,b,ans);
    }
    if(b > mid)
    {
        query(2 * node + 1,mid + 1, right,a,b,ans);
    }
    aint[node].first = max(aint[2 * node].first,aint[2 * node + 1].first);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long m,i,n,a,b,c,q;
    cin >> n >> m;
    for(i = 1; i <= n; i ++)
    {
        cin >> q;
        cc[i] = q;
        v[i] = v[i - 1] + q;
    }
    build(1,1,n);
    b1(1,1,n);
    for(i = 1; i <= m; i ++)
    {
        cin >> a >> b >> c;
        if(a == 1)
        {
            update(1,1,n,b,n,-cc[b]);
            update(1,1,n,b,n,c);
            cc[b] = c;
            u1(1,1,n,b,c);
        }
        else
        {
            long long af = -9223372036854773808;
            query(1,1,n,b,c,af);
            long long af1 = 0;
            if(b - 1 > 0)
            {
                q1(1,1,n,1,b - 1,af1);
            }
            if(af - af1 < 0)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << af - af1 << '\n';
            }
        }
    }
    return 0;
}
