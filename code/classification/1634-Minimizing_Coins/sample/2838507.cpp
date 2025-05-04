#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<list>
#include<queue>
using namespace std;
#define MAX 1000000007
#define ll long long int
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define REP(i,n) for(int i=0;i<n;i++)
  ll a[200005];
    ll tree[800021];
    ll BIT[800021];
ll power(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
        res=((res%MAX)*(a%MAX))%MAX;
        a=((a%MAX)*(a%MAX))%MAX;
        b>>=1;
    }
 return res;
}
ll gcd(ll a ,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
/*bool solve(ll a[],ll b[],string s)
{
    for(int i=0;i<s.length();i++)
    {
        a[s[i]-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        if(a[i]!=b[i])
        return false;
    }
    return true;
}*/
bool compare2(pair<ll,ll> a,pair<ll,ll> b)
{
    if(a.second>b.second)return true;
    else if(a.second==b.second)
    {
        if(a.first<b.first)return true;
        return false;
    }
    return false;
}
bool compare1(pair<ll,ll> a,pair<ll,ll> b)
{
    if(a.first>b.first)
    return true;
    else if(a.first==b.first)
    {
        if(a.second<b.second)return true;
        return false;
    }
    return false;
}
void updatebit(ll i,ll n,ll inc)
{  
    while(i<=n)
    {
        BIT[i]+=inc;
        i+=(i&-i);
    }
}
ll querybit(ll i)
{  ll ans=0;
    while(i>0)
    {ans+=BIT[i];
        i-=(i&-i);
    }
    return ans;
}
void buildst(ll ss,ll se,ll in)
{
    if(ss==se)
    {
        tree[in]=a[ss];
        return;
    }
    ll m=(ss+se)/2;
   buildst(ss,m,2*in+1);
   buildst(m+1,se,2*in+2);
  // tree[in]=tree[2*in+1]+tree[2*in+2];
   
}
void updatest(ll qs,ll qe,ll ss,ll se,ll in,ll inc)
{
    if(qe<ss||qs>se)
    return ;
   else if(ss==se)
   {tree[in]+=inc;return ;}
    
      ll m=(ss+se)/2;
     
     updatest(qs,qe,ss,m,2*in+1,inc);
  updatest(qs,qe,m+1,se,2*in+2,inc);
   
    //tree[in]=tree[2*in+1]+tree[2*in+2];
   
}
ll queryst(ll qs,ll qe,ll ss,ll se,ll in)
{
    if(qe<ss||qs>se)
    return 0;
    else if(qs<=ss&&qe>=se)
    return tree[in];
    
      ll m=(ss+se)/2;
     
     ll left=queryst(qs,qe,ss,m,2*in+1);
   ll right=queryst(qs,qe,m+1,se,2*in+2);
   
   return left+right;
   
}
vi ordering;
 
class graph
{
    unordered_map<int,list<int>> l;
  
    public:
    void addEdge(int x,int y)
    {
       l[x].pb(y);
   //    l[y].pb(x);
      
       
    }
    void dfs_helper(int node,unordered_map<int,bool> &visited)
    {
        visited[node]=true;
       
        
        for(auto i:l[node])
      {  if(!visited[i])
        {
            dfs_helper(i,visited);
        }
      }
      ordering.pb(node);
   
    }
   
    void dfs()
    {
      unordered_map<int,bool> visited;
        for(auto i:l)
         visited[i.first]=0;
        for(auto i:l)
        {   auto node=i.first;
           if(!visited[node])
           {      
               dfs_helper(node,visited);
             
               
           }
           
        }
     
        
    }
     void dfs_helper2(int node,unordered_map<int,bool> &visited)
    {
        visited[node]=true;
       
        
        for(auto i:l[node])
      {  if(!visited[i])
        {
            dfs_helper2(i,visited);
        }
      }
    //  component[k].pb(node);
   
    }
    int dfs2(vi ordering)
    {
      unordered_map<int,bool> visited;
        for(auto i:l)
        visited[i.first]=0;
      //  int k=0;
        vi res;
         for(int i=ordering.size()-1;i>=0;i--)
         { int node=ordering[i];
             if(!visited[node])
         { dfs_helper2(node,visited);
           res.pb(node);
         }
         
         }
              
               
        if(res.size()==1)   
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
            cout<<res[1]<<" "<<res[0]<<endl;
           // cout<<component[0][0]<<" "<<component[1][0]<<endl;
        }
        
    }
    
};
 
ll fact[200005];
void factmod(ll md)
{
    fact[0]=1;fact[1]=1;
    for(int i=2;i<200005;i++)
    {
        fact[i]=((fact[i-1]%md)*(i%md))%md;
    }
    
}
ll dp[1000001]={0};
 long long int change(ll *a,ll m,ll n)
  { ll ans=0;
      if(n==0)
      return 1;
      if(dp[n]!=0)
      return dp[n];
      for(int i=0;i<m;i++)
      {
          if(n-a[i]>=0)
          {
              ans=(ans%MAX+change(a,m,n-a[i])%MAX)%MAX;
          }
      }
      dp[n]=ans%MAX;
      return ans;
  }
int main() {
 
int t;
t=1;
while(t--)
{
    ll m,n;cin>>m>>n;
    
  ll a[m];
  //ll dp[n+1]={0};
  vector<ll> dp(n + 1, 0);
  dp[0]=0;
  REP(i,m)cin>>a[i];
  // sort(a,a+m);
  for(int i=1;i<=n;i++)
  {  ll ans=MAX;
      for(int j=0;j<m;j++)
      {
          if(i-a[j]>=0)
          {
              ans=min(ans,dp[i-a[j]]+1);
          }
         // else
         // break;
      }
      dp[i]=ans;
      
  }
  if(dp[n]==MAX)cout<<-1<<endl;
  else
  cout<<dp[n]<<endl;
 // change(a,m,n);
//  cout<<dp[n]%MAX<<endl;
 
}
	return 0;
}
