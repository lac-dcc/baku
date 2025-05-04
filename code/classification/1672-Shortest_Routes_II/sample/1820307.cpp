#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define INF  LONG_LONG_MAX
#define MAXN 1000005
#define amarks444                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
 
//map<ll,ll> totalFreq;
//vector<bool>visited;
//map<ll,ll> :: iterator itr;
//for(itr=freq.begin();itr!=freq.end();itr++)
//itr->f    itr->s
//set< ll , greater<ll> > ap , ap1;
//priority_queue<ll> gquiz;
ll n;
 
 
int main ( )
{
        amarks444;
        ll  m , q;
        cin>>n>>m>>q;
        vector<pair< ll , ll > >  adj[n];
        ll d[n][n];
       
         for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                        if(i==j){   d[i][j] = 0;    continue;   }
                        d[i][j] = INF; 
            }
        }
        for(ll i=0;i<m;i++){
            ll u , v , dist;
            cin>>u>>v>>dist;
            u--; v--;
            d[u][v] = min(dist ,d[u][v] );
            d[v][u] = d[u][v];
        }
 
        for (ll k = 0; k < n; ++k) {
                for (ll i = 0; i < n; ++i) {
                    for (ll j = 0; j < n; ++j) {
                        if (d[i][k] < INF && d[k][j] < INF)
                            {
                                d[i][j] = min( d[i][j] , d[i][k] + d[k][j] );
                                d[j][i] = d[i][j];
                             }
                    }
                }
        }    
 
        while(q--){
             ll u , v ;
            cin>>u>>v;
            u--; v--;
            if(d[u][v]  ==  INF){
                cout<<-1<<"\n";
            }else{
                cout<<d[u][v] <<"\n";
            }
 
        }
        
       
    return 0;
}
 
 
// you should actually read the stuff at the bottom
/* 
    Stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
 
