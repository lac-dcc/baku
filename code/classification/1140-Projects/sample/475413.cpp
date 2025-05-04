#include <bits/stdc++.h>
using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define int long long
  #define endl "\n"
  const int N = 1000005;
 
 
vector<int> a(N),b(N),p(N);
 vector<int> dp(N);
 
map<int,int> mp;
 
  int timer = 1;
 
void compress()
{
 
 
  for(auto &i : mp)
  {
    i.second = timer++;
  }
}
 
int32_t main()
{
  
 
 
    
    IOS
 
    int n;
    cin >> n;
 
    
    for(int i = 0; i < n; i++)
    {
      cin >> a[i] >> b[i] >> p[i];
      mp[a[i]]++;
      mp[b[i]]++;
    }
 
    compress();
 
 
    for(int i = 0; i < n; i++)
    {
      a[i] = mp[a[i]];
      b[i] = mp[b[i]];
    }
 
    vector<pair<int,pair<int,int>>> v;
 
    for(int i = 0; i < n; i++)
    {
      v.push_back({a[i],{b[i],p[i]}});
    }
 
    sort(v.begin(),v.end());
 
    vector<vector<pair<int,int>>> v1(timer);
 
    for(int i = 0; i < n; i++)
    {
      v1[v[i].second.first].push_back(make_pair(v[i].first,v[i].second.second));
    }
 
 
 
 
   
    // dp[i] denotes the maximum money we can earn before starting the day i
 
    for(int i = 1; i <= timer; i++)
    {
      if(i)dp[i] = dp[i-1];
 
      for(auto &j : v1[i-1])
      {
        dp[i] = max(dp[i],dp[j.first] + j.second);
      }
    }
 
    cout << dp[timer];
  
    
    return 0;
}
