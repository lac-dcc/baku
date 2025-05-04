#include <bits/stdc++.h>
#define For(i,n,uu) for(int i=uu;i<n;++i)
#define fi first
#define se second
//#define int long long
using namespace std;
using ll = long long;
using ld = long double;
struct Edge
{
    int x,y;
    bool operator<(const Edge &other) const
    {
        return other.x < x;
    }
};
bool comp(const Edge &u,const Edge &v)
{
    return v.y>u.y;
}
bool comp2(const Edge &u,const Edge &v)
{
    return !(u.x<=v.x);
}
signed main (void)
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
   int n,k; cin>>n>>k;
   multiset<Edge> s;
   int res=0;
   vector<Edge> a;
   For(i,n,0)
   {
       int l,r; cin>>l>>r;
       a.push_back({l,r});
   }
  sort(a.begin(),a.end(),comp);
  For(i,k,0) s.insert({0,0});
  //solve
  For(i,n,0)
  {
      auto it=s.lower_bound(a[i]);
       if (it != s.end())
       {
           s.erase(it);
           s.insert({a[i].y,0});
           res++;
       }
  }
  //result
  cout<<res<<'\n';
    return 0;
}
