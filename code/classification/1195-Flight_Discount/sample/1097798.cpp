#include <bits/stdc++.h>
#define ll long long
#define en "\n"
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
const ll INF = 1e17;
vector<vector<pair<ll, ll>>> g;
ll n, m, k;
vector<ll> disc;
vector<ll> dist;
 
void dijkstras(){
    disc[0] = 0;
    dist[0] = 0;
    disc[1] = 0;
    dist[1] = 0;
    priority_queue<pair<ll, pair<ll, ll>> ,vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    pq.push({0, {1, 0}});
    while(!pq.empty()){
        ll d = pq.top().first;
        ll u = pq.top().second.first;
        ll f = pq.top().second.second;
        pq.pop();
        if(f==1){
            if(disc[u]<d)   continue;
        }
        if(f==0){
            if(dist[u]<d)   continue;
        }
        
        for(auto e:g[u]){
            ll v = e.first, c = e.second;
            if(f==0){
                if(dist[v]>d+c){
                    dist[v]=d+c;
                    pq.push({dist[v], {v, 0}});
                }
                if(disc[v]>d+c/2){
                    disc[v]=d+c/2;
                    pq.push({disc[v], {v, 1}});
                }
            }
            if(f==1){
                if(disc[v]>d+c){
                    disc[v]=d+c;
                    pq.push({disc[v], {v, 1}});
                }
            }
        }
    }
}
 
 
int main()
{
	fio;
	cin>>n>>m;
	g.resize(n+1);
    disc.resize(n+1, INF);
    dist.resize(n+1, INF);
 
    for(ll i=0; i<m; i++){
        ll a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
    }
 
    dijkstras();
 
    cout<<disc[n];
 
		
	return 0;
}
