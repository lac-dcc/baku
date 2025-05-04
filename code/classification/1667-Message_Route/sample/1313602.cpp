#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define EL cout<<'\n'
#define pii pair <int,int>
#define ll long long
#define prob "1667"
#define ret return 0
using namespace std;
 
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,1,-1};
int n,m,vis[100001]{0};
vector <vector <int> > lk;
deque<int> s,res;
int l=1e9;
 
void dfs(int u,int d)
{
    if (u==n)
    {
        if (d<l)
        {
            res=s;
            l=res.size();
            return;
        }
    }
    for (int v:lk[u])
    {
        if (vis[v]) continue;
        s.push_back(v);
        vis[v]=1;
        dfs(v,d+1);
        vis[v]=0;
        s.pop_back();
    }
}
 
void bfs()
{
    queue <int> q;
    int f=0;
    vis[1]=1;
    q.push(1);
    while (q.size())
    {
        int u=q.front();
        q.pop();
        if (u==n) {f=1;break;}
        for (int v:lk[u])
        {
            if (vis[v]) continue;
            vis[v]=vis[u]+1;
            q.push(v);
        }
    }
    if (f==0) return;
    res.push_back(n);
    while (n!=1)
    {
        for (int v:lk[n] )
        {
            if (vis[v]==vis[n]-1)
            {
                n=v;
                res.push_back(v);
                if (v==1 ) return;
            }
 
        }
    }
}
 
void input()
{
    cin>>n>>m;
    lk.resize(n+1);
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        lk[u].pb(v);
        lk[v].pb(u);
    }
    bfs();
    if (res.size()==0) {cout<<"IMPOSSIBLE";return;}
    else
    {
        cout<<res.size();EL;
        while (res.size())
        {
            cout<<res.back()<<' ';
            res.pop_back();
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen(prob".inp","a+",stdin);
//    freopen(prob".out","w+",stdout);
    input();
    ret;
}
