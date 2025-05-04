#include<iostream>
#include<bits/stdc++.h>
typedef 	long long int 	ll;
#define 	mod 	1000000007
#define	rep(i,a,n)	for(int i=a;i<n;i++)
#define	all(v)	v.begin(),v.end()
#define	yes	std::cout<<"YES"
#define	no	std::cout<<"NO"
using	namespace	std;
void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
int main()
{
    run();
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<pair<int,int>>> adj(n);
    vector<vector<ll>> dis(n,vector<ll>(n,INT64_MAX));
    rep(i,0,m)
    {
        int a,b;
        ll c;
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
        adj[b-1].push_back({a-1,c});
        dis[a-1][b-1] = min(dis[a-1][b-1],c);
        dis[b-1][a-1] = min(dis[b-1][a-1],c);
    }
    for(int i=0;i<n;i++)
        dis[i][i] = 0;
    
    for(int k = 0;k<n;k++)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dis[i][k]!=INT64_MAX && dis[k][j]!=INT64_MAX)
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(dis[x-1][y-1] >= INT64_MAX)
            dis[x-1][y-1] = -1;
        cout<<dis[x-1][y-1]<<endl;
    }
    return 0;
}
