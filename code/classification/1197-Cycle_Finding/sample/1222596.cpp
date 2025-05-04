#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
struct edge
{
    ll src,dst,wt;
};
void bellman(vector<edge> &Edges,ll V,ll E)
{
    vector<ll> par(V+1,-1);
    //vector<ll> cost_par(V+1);
    vector<ll> value(V+1,0);
    value[1]=0;
    int x=-1;
    for(ll i=1;i<=V;i++)
    {
        x=-1;
        for(ll j=0;j<E;j++)
        {
            ll u=Edges[j].src;
            ll v=Edges[j].dst;
            ll wt=Edges[j].wt;
            if(value[u]!=1e17 && value[u]+wt<value[v])
            {
                value[v]=value[u]+wt;
            par[v]=u;
            x=v;
 
                //cost_par[v]=value[v];
            }
        }
 
    }
     if(x==-1)
    cout<<"NO";
 
    else
    {
        for(int i=1;i<=V;i++)
        x=par[x];
 
        int k=x;
        cout<<"YES"<<endl;
        stack<int> s;
        while(par[x]!=k)
        {
            s.push(par[x]);
            x=par[x];
        }
        s.push(k);
        s.push(par[k]);
        while(s.empty()==false)
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    //cout<<value[V]*(-1);
}
int main()
{
    ll V,E;
    cin>>V>>E;
    vector<edge> Edges(E+1);
    ll src,dst,wt;
    for(ll i=0;i<E;i++)
    {
        cin>>src>>dst>>wt;
        Edges[i].src=src;
        Edges[i].dst=dst;
        Edges[i].wt=wt;
    }
    bellman(Edges,V,E);
    return 0;
}
