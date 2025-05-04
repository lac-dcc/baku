#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class edge{
    public:
    ll from;
    ll to;
    ll w;
    edge(ll f,ll t,ll w1):from(f),to(t),w(w1)
    {}
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<edge>edges;
    vector<ll>d(n+1),p(n+1,-1);
    for(int i=0;i<m;++i){
        ll a,b,c;
        cin>>a>>b>>c;
        edge e(a,b,c);
        edges.push_back(e);
    }
    int f;
    for(int i=0;i<n;++i){
        f=-1;
        for(auto e:edges){
            if(d[e.from]+e.w<d[e.to]){
                d[e.to]=d[e.from]+e.w;
                p[e.to]=e.from;
                f=e.to;
            }
        }
        if(f==-1){
            break;
        }
    }
    if(f!=-1){
        cout<<"YES\n";
        for(int i=0;i<n;++i){
            f=p[f];
        }
        vector<ll> cycle;
        for(ll v=f;;v=p[v]){
            if(cycle.size()>0 && v==f){
                cycle.push_back(v);
                break;
            }
            cycle.push_back(v);
        }
        for(auto it=cycle.rbegin();it!=cycle.rend();++it){
            cout<<*it<<" ";
        }
    }else{
        cout<<"NO\n";
    }
}
