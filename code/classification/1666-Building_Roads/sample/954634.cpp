#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb emplace_back
#define mod 1000000007
 
ll find_set(ll v, vector<ll> &parent){
    while(v!=parent[v]){
        parent[v] = parent[parent[v]];
        v = parent[v];
    }
    return v;
}
 
void union_sets(ll u, ll v, vector<ll> &parent, vector<ll> &rank){
    ll parent_u = find_set(u, parent), parent_v = find_set(v, parent);
    if(parent_u!=parent_v){
        if(rank[parent_u]<rank[parent_v]){
            swap(parent_u, parent_v);
        }
        parent[parent_v] = parent_u;
        if(rank[parent_u]==rank[parent_v]){
            rank[parent_u]++;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, m;
    cin>>n>>m;
    vector<ll> parent(n), rank(n, 1);
    for(ll i=0; i<n; i++){
        parent[i] = i;
    }
    for(ll i=0; i<m; i++){
        ll u, v;
        cin>>u>>v;
        u--; v--;
        union_sets(u, v, parent, rank);
    }
    for(ll i=0; i<n; i++){
        parent[i] = find_set(i, parent);
    }
    set<ll> s(parent.begin(), parent.end());
    cout<<s.size()-1<<"\n";
    while(s.size()>1){
        ll u = *s.begin();
        s.erase(s.begin());
        ll v = *s.begin();
        cout<<u+1<<" "<<v+1<<"\n";
    }
}
