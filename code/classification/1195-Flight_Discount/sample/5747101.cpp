#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int maxx=1e18;
const int minn=-1e18;
void inp();
void solve();
vector<vector<pair<int,int> > >a;
vector<int> giam,full;
priority_queue<pair<int,pair<int,int> >, vector< pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>> >> q;
int n,m;
signed main()
{   //freopen("1.inp","r",stdin);
    inp();
    solve();
    return 0;
}
void inp()
{ 
    int x,y,z;
    cin>>n>>m;
    a.resize(n+1);
    giam.resize(n+1,maxx);
    full.resize(n+1,maxx);
    rep(i,1,m)
    {
        cin>>x>>y>>z;
        a[x].pb({y,z});
    }
    q.push({0,{1,0}});
   
 
}
void solve()
{  giam[1]=0;
   full[1]=0;
    while(!q.empty())
    {
        auto it= q.top();
        int dinh=it.ss.ff, val=it.ff, giamko=it.ss.ss;
        q.pop();
        if(giamko==1&&giam[dinh]<val) continue;
        if(giamko==0&&full[dinh]<val) continue;
        for(auto k: a[dinh])
        {   int node=k.ff, vall=k.ss;
            if(giamko==0)
            {   if(val+vall<full[node])
                 {
                    full[node]=full[dinh]+vall;
                    q.push({full[node],{node,0}});
                 }
 
                if(val+vall/2<giam[node])
                {
                    giam[node]=full[dinh]+vall/2;
                    q.push({giam[node],{node,1}});
                }
            }
            else
            {
                if(val+vall<giam[node])
                {
                    giam[node]=val+vall;
                    q.push({giam[node],{node,1}});
                }
            }
        }        
    }
    cout<<giam[n];
}
