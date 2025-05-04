#include<bits/stdc++.h>
#define lp(i,x,n) for(ll i=x;i<n;i++)
#define rlp(n,x,j) for(ll j=n-1;j>=x;j--)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define debug(x) cout<<(#x)<<" is "<<(x)<<endl
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;
using namespace std;
const ll mod=1000000007;
//code//
void bfs(map<int, vector<int>> &m, vector<int> &pa, vector<int>&di, int node, int parent)
{
     priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > q;
     di[node]=0;
     q.push({1,node});
    pa[node]=parent;
    while(!q.empty())
    {
        int wt= q.top().first, no= q.top().second;
        q.pop();
        for(auto x:m[no])
        {
            if(di[no]+wt<di[x])
            {
                di[x]=di[no]+wt;
                q.push({1,x});
                pa[x]=no;
            }
        }
    }
}
void printans(vector<int> &pa,vector<int> &ans, int node)
{
    if(node==pa[node]){ans.push_back(node);return;}
    printans(pa,ans,pa[node]);
    ans.push_back(node);
}
void testcase()
{
    int n,k,x,y;cin>>n>>k;
    map<int, vector<int>> m;
    while(k--)
    {
        cin>>x>>y;
        m[x].push_back(y);
        m[y].push_back(x);
    }
    vector<int> pa(n+1,-1);
    vector<int> di(n+1,INT_MAX);
    bfs(m,pa,di,1,1);
    // for(auto x:pa)cout<<x<<" ";cout<<endl;
    if(pa[n]==-1)cout<<"IMPOSSIBLE"<<endl;
    else
    {
      vector<int> ans;
      printans(pa,ans,n);
      cout<<ans.size()<<endl;
      for(auto x:ans)cout<<x<<" ";cout<<endl;
    }
    
}
 
int main()
{
    FAST;
    // ll t;cin>>t;while(t--)
     testcase();
   return 0;
}
