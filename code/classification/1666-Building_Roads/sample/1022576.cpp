#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define ssd ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)
#define MOD 1000000007
typedef long long int ll;
using namespace std;
using namespace __gnu_pbds;
 
void initialize(vector<ll> &id,vector<ll> &weight)
{
 
    for(ll i=1;i<id.size();i++)
    {
        id[i]=i;
        weight[i]=1;
    }
}
 
 
ll root(vector<ll> &id,ll v)
{
    if(id[v]==v)
        return v;
    return id[v]=root(id,id[v]);
}
 
bool find(vector<ll> &id,ll a,ll b)
{
    return (root(id,a)==root(id,b));
}
 
 
void union_weighted(vector<ll> &id,vector<ll> &weight,ll a,ll b,vector<pair<ll,ll>> &v)
{
    if(find(id,a,b))
        return ;
 
    if(weight[root(id,a)]<weight[root(id,b)])
    {
 
        v.push_back(make_pair(root(id,a),root(id,b)));
        id[root(id,a)]=id[root(id,b)];
        weight[root(id,b)]+=weight[root(id,a)];
    }
    else
    {
 
        v.push_back(make_pair(root(id,a),root(id,b)));
        id[root(id,b)]=id[root(id,a)];
        weight[root(id,a)]+=weight[root(id,b)];
    }
}
 
 
int main()
{
	ssd
	#define task "TASK"
	 //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
 
    ll n,m,a,b;
    cin>>n>>m;
    vector<pair<ll,ll>>edgelist(m);
 
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b;
        edgelist[i]={a,b};
    }
 
    vector<ll>id(n+1);
    vector<ll>weight(n+1);
    initialize(id,weight);
    vector<pair<ll,ll>>p;
    for(ll i=0;i<m;i++)
    {
        union_weighted(id,weight,edgelist[i].first,edgelist[i].second,p);
    }
 
 //   for(ll i=1;i<=n;i++)
   // {
       // trace(root(id,i));
     //   trace(weight[i]);
   // }
    //cout<<"\n";
    vector<pair<ll,ll>>v;
    for(ll i=2;i<=n;i++)
    {
        union_weighted(id,weight,i,i-1,v);
    }
 
  //  for(ll i=1;i<=n;i++)
    //{
      //  trace(root(id,i));
    //    trace(weight[i]);
  //  }
 
    cout<<v.size()<<endl;
    for(ll i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<" ";
	return 0;
}