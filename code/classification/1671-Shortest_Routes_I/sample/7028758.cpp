#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e17 + 7;
 
vector<vector<pair<int,int>>> adj;
int n, m;
int main(){
    cin >> n >> m;
    adj.assign(n, vector<pair<int,int>>());
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        --a,--b;
        adj[a].push_back(make_pair(b, (ll)c));
    }
 
    set<pair<ll,int>>s;
    vector<ll> d(n, mod);
    d[0] = 0;
 
    s.insert(pair<ll,int>(0LL,0)); 
 
    while(!s.empty()){
        int node = s.begin()->second;
        s.erase(s.begin());
 
        for(auto nbr: adj[node]){
            int to = nbr.first;
            int dist = nbr.second;
 
            if(d[to]>d[node]+dist){
                s.erase({d[to],to});
                d[to] = d[node]+dist;
                s.insert(pair<ll,int>(d[to],to));
            }
        }
    }
 
    for(int i=0; i<n; i++){
        if(i!=0)cout<<" ";
        cout<<d[i];
    }
    cout<<endl;
    return 0;
}
