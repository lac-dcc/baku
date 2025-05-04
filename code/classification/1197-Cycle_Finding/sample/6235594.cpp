#include <bits/stdc++.h>
#define maxn
#define name ""
#define fi(i,a,b) for(int i = a; i <= b; i++)
#define fid(i,a,b) for(int i = a; i >= b; i--)
 
using namespace std;
int n, m, ts[2509][2509], cha[2509], tmp;
long long l[2509];
pair<int,int> p[5009];
vector<int> d;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int z;
        cin >> p[i].first >> p[i].second >> z;
        ts[p[i].first][p[i].second]=z;
    }
 
    for(int i=1; i<=n; i++)
        l[i]=1e18;
 
    for(int i=1; i<=n; i++)
    {
        tmp=0;
        for(int j=1; j<=m; j++)
        {
            int u=p[j].first;
            int v=p[j].second;
            if(l[u]+ts[u][v]<l[v])
            {
                l[v]=l[u]+ts[u][v];
                cha[v]=u;
                tmp=v;
            }
        }
    }
 
    if(!tmp) cout << "NO";
    else
    {
        int u=tmp;
        for(int i=1; i<=n; i++)
            u=cha[u];
        int c=cha[u];
        while(c!=u)
        {
            d.push_back(c);
            c=cha[c];
        }
        cout << "YES" << '\n';
        cout << u << " ";
        for(int i=d.size()-1; i>=0; i--)
            cout << d[i] << " ";
        cout << u;
    }
 
 
 
}
