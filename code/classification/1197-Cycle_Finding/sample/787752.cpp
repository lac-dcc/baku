#include <bits/stdc++.h>
 
using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define vect vector
# define pll pair<ll,ll>
# define pii pair<int,int>
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
const ll INF=1e15;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
struct edge
{
    int a, b, cost;
};
bool bellman_ford(int v,int n,int m,vect<edge>&e,vect<bool>&visited)
{
    vector<ll>d(n,INF);
    d[v] = 0;
    vector<int> p (n );
    int x;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                    visited[e[j].b]=true;
                    visited[e[j].a]=true;
                }
    }
 
    if (x == -1)
        return false;
    else
    {
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];
 
        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());
 
        cout << "YES\n";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i]+1 << ' ';
        return true;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t-->0)
    {
        ll n,m;
        cin>>n>>m;
        vector<edge> e;bool found=false;
        vector<ll> possible_negatives;
        for(int i=0;i<m;i++)
        {
            ll aa,bb,cc;
            cin>>aa>>bb>>cc;
            edge temp;
            temp.a=aa-1;
            temp.b=bb-1;
            if(cc<0)
            {
                possible_negatives.push_back(aa-1);
                possible_negatives.push_back(bb-1);
            }
            if(aa==bb && cc<0)
            {
                found=true;
                cout<<"YES\n";
                cout<<aa<<" "<<aa;
            }
            temp.cost=cc;
            e.push_back(temp);
        }
        vect<ll> d(n,INF);
        vect<bool> visited(n,false);
        if(!found)
        {
            for(int i=0;i<possible_negatives.size();i++)
            {
                if(!visited[possible_negatives[i]])
                if(bellman_ford(possible_negatives[i],n,m,e,visited))
                {found=true;break;}
            }
        }
        if(!found)
        cout<<"NO\n";
    }
}
