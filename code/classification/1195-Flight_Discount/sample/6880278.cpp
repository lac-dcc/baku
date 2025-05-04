#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long,long long>>> adj;
vector<vector<pair<long long,long long>>> radj;
vector<long long> d1;
vector<long long> d2;
void dij(long long node,vector<long long>& d){
    set<pair<long long,long long>> st;
    st.insert({0,node});
    while(!st.empty()){
        long long curr=st.begin()->second;
        st.erase(st.begin());
        for(auto e: adj[curr]){
            long long to=e.first;
            long long len=e.second;
            if(d[curr] < LONG_LONG_MAX){
                if(d[to] > d[curr]+len){
                    st.erase({d[to],to});
                    d[to]=d[curr]+len;
                    st.insert({d[to],to});
                }
            }
        }
    }
}
void dij2(long long node,vector<long long>& d){
    set<pair<long long,long long>> st;
    st.insert({0,node});
    while(!st.empty()){
        long long curr=st.begin()->second;
        st.erase(st.begin());
        for(auto e: radj[curr]){
            long long to=e.first;
            long long len=e.second;
            if(d[curr] < LONG_LONG_MAX){
                if(d[to] > d[curr]+len){
                    st.erase({d[to],to});
                    d[to]=d[curr]+len;
                    st.insert({d[to],to});
                }
            }
        }
    }
}
typedef struct Edges{
    long long from;
    long long to;
    long long cost;
}Edges;
vector<Edges> edges;
void solve()
{   
    long long n,m;
    cin>>n>>m;
    adj.resize(n);
    radj.resize(n);
    d1.assign(n,LONG_LONG_MAX);
    d2.assign(n,LONG_LONG_MAX);
    for(long long i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b,c});
        radj[b].push_back({a,c});
        edges.push_back({a,b,c});
    }
    d1[0]=0;
    dij(0,d1);
    d2[n-1]=0;
    dij2(n-1,d2);
    long long ans=LONG_LONG_MAX;
    for(auto e: edges){
        if(d1[e.from] < LONG_LONG_MAX && d2[e.to]<LONG_LONG_MAX) ans=min(ans,d1[e.from]+(e.cost/2)+d2[e.to]);
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
