#include<bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define F first
#define S second
using namespace std;
typedef int ll;
ll n,m,col[100009];
vector<vector<ll> >v;
queue<ll>q;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    v.resize(n+1);
    while(m--)
    {
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(ll i=1; i<=n; i++)
    {
        if(col[i])
            continue;
        col[i]=1;
        q.push(i);
        while(!q.empty())
        {
            ll x=q.front();
            q.pop();
            for(auto&it:v[x])
            {
                if(col[it])
                {
                    if(col[it]==col[x])
                        return cout<<"IMPOSSIBLE",0;
                    continue;
                }
                col[it]=3-col[x];
                q.push(it);
            }
        }
    }
    for(ll i=1; i<=n; i++)
        cout<<col[i]<<" ";
    return 0;
}
