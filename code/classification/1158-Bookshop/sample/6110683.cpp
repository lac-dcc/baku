#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define ppi pair<int,pair<int,int>>
#define nl cout<<endl;
#define print(x) cout<<x<<endl;
# define modu 1e9+7
#define inp(x)   ll x;cin>>x;
#define ce continue;
#define pll pair<long long,long long>
#define max_heap(h) priority_queue<int> h;
#define min_heap priority_queue<int,vector<int>,greater<int>>
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define maxn 200010
#define r1 return
#define mp make_pair
const int MOD= pow(10,9)+7;
#define sprint(s)   std::for_each(s.begin(), s.end(), printElement);
//always inputing indexing do subtract -1
// always when we have to do square root of a non perfect square number there will be a problem that if I am ll t=sqrtl(n); then 
// there is a possibility that it can give a wrong answer for this we should check if(pow(t+1,2)==n){}
//set<int> b(A.begin(), A.end()); set can be initiated like this too
// always 1e9 put ll
// if 1e18 think of string
//auto it=s.upper_bound(g); please write like thisssssssssssssssss
// std::vector<int> v1(v.begin() + 4, v.end() - 2);
// advance (InputIterator& it, Distance n); this advance the iterator in any container it takes O(N) time complexity
// we can never find middle element in set in constant time 
// ORDERED SET:  time complexity(log(n))
//            order_of_key(k) : number of elements strictly smaller than k
//            find_by_order(n) : kth element in a set(counting from 0)
//  vector<vector<int>> vec( n , vector<int> (m, 0));  TO INITIALIZE 2D VECTOR with n rows and m columns
 
struct me
{
  ll s;
  ll i;
  ll j;
  bool operator < (const me & other)
  {
    if(s==other.s)
    {
      return(i<other.i);
    }
    return(s<other.s);
  }
};
// ll dp[MOD][MOD];
 
vector<vector<int>> dp;
ll fun()
{
 
}
 
void solve ()
{
 int n,x;
 cin>>n>>x;
 int c[n];
 int p[n];
 f(i,n)
 {
  cin>>c[i];
 }
 f(i,n)
 {
  cin>>p[i];
 }
  dp.resize(n+1,vector<int> (x+1,0));
  f(i,n)
  {
    for(int j=0;j<=x;j++)
    {
      if(i-1<0)
      {
        if(j-c[i]<0)
        {
            dp[i][j]=0;
        }
        else
        {
          dp[i][j]=p[i];
        }
        ce;
      }
      if(j-c[i]<0)
      {
        // print("f");
      // print(dp[i-1][j]);        
        dp[i][j]=dp[i-1][j];
        ce;
      }
      dp[i][j]=max(dp[i-1][j],p[i]+dp[i-1][j-c[i]]);
    }
  }
 
  print(dp[n-1][x]);
  // print(ans);
  // f(i,n)
  // {
  //   for(int j=0;j<=x;j++)
  //   {
  //     cout<<dp[i][j]<<" ";
  //   }nl;
  // }
 
}
 
 
 
 
int main()
{;
int t=1;
  // cin>>t;
while(t--)
{
 solve();
}
} 