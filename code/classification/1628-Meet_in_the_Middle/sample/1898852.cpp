#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int mxN=1e6+7;const int inf=1e9+7; const ll mod=998244353; const ll infll=1e15+7;
 
ll n,k,s,a[mxN],price,res=0;
ll sum[mxN];
unordered_map<ll,ll> mp;
void backtrack(ll x,int _start,int _end)
{
    for(int i=_start;i<=_end;i++)
    {
        s+=a[i];
        if(s>k) 
        {
            s-=a[i];
            break;
        }
        backtrack(x+1,i+1,_end);
        mp[s]++;
        s-=a[i];
    }
}
 
void backtrack1(int x,int _start,int _end)
{
    for(int i=_start;i<=_end;i++)
    {
        s+=a[i];
        if(s>k)
        {
            s-=a[i];
            break;
        }
        res+=mp[k-s];
        backtrack1(x+1,i+1,_end);
        s-=a[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("task.inp","r",stdin);
    //freopen("task.out","w",stdout);
 
    cin >> n >> k;
    mp[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    backtrack(1,1,n/2);
    backtrack1(1,n/2+1,n);
    cout << res+mp[k];
 
    return 0;
}
