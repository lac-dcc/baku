#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll, ll>
#define vpl vector<pair<ll, ll>>
#define gpl greater<pair<ll, ll>>
#define in(v,n) for(ll i = 0; i < n; i++) cin>>v[i]
#define mid(l,r) l+(r-l)/2
#define fo(i,n) for(ll i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007 
 
void floydWarshall(vector<vector<ll>>& dist, ll n)
{
    for(ll k = 1; k <= n; k++)
    {
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= n; j++)
            {
                ll i_j = dist[i][j];
                ll i_k = dist[i][k];
                ll k_j = dist[k][j];
                dist[i][j] = min(i_j, i_k + k_j);
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1));
    for(ll i = 0; i <= n; i++)
    {
        for(ll j = 0; j <= n; j++)
            dist[i][j] = 1e18;
        dist[i][i] = 0;
    }
    while(m--)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    floydWarshall(dist, n);
    while(q--)
    {
        ll a, b; cin>>a>>b; 
        cout<<(dist[a][b] < 1e18 ? dist[a][b] : -1)<<endl;
    }
    return 0;
}


