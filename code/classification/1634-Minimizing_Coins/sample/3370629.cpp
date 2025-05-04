 
 
#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
//#define int long long int 
#define vi vector<int>
#define repi(s,e) for(int i=s;i<e;i++)
#define rep(j,s,e) for(int j=s;j<e;j++)
#define pb push_back
typedef pair<int, int> pii;
#define int long long int
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> o_set;
#define F first
#define S second
multiset<int>low;
multiset<int>up;
#define int long long int 
//const int  LINF = 1e18;
using ll = long long;
const ll LINF = 1e18;
bool cmp(const pii &p1,const pii &p2){
  //if(p1.second==p2.S){return p1.F>p2.F;}
  return p1.second<p2.second;
}
int s=1e6+1;
int mod=(1e9)+7;
int32_t main() {
   ios_base::sync_with_stdio(false);  
cin.tie(NULL); // flushes cout  
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//cout<<s<<endl;
//vector<ll>dp(s,INT_MAX);
ll dp[1000001];
dp[0]=0;//no of coins to make 0 Rs =1
int n,m;
cin>>m>>n;
vector<int>coin(m,0);
 
rep(i,0,m){
cin>>coin[i];
 
}
//sort(coin.begin(),coin.end());
dp[0]=0;
repi(1,n+1){
dp[i]=INT_MAX;
  rep(j,0,m){
    if(i-coin[j]>=0){
    int pos=(1+dp[i-coin[j]]);
    
    dp[i]=min(dp[i],pos);
    }
    
  }
}
cout << (dp[n] == INT_MAX ? -1 : dp[n]) << '\n';
}