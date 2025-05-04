#include <bits/stdc++.h>
#define all(v) ((v).begin(),(v).end())
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int mxN = 1e5 + 5;
pair<int,int> a[mxN];
map<int,pair<int,int>>mp;
signed main()
{
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int n,x;
  cin >>n>>x;
  for(int i = 1;i <= n;i++){
    cin >>a[i].first;
    a[i].second = i;
  }
  sort(a + 1,a + n + 1);
  for(int i = 3;i <= n;i++){
    int z = a[i - 1].first;
    for(int k = i - 2; k > 0;k--){
      mp[a[k].first + z] = {a[k].second,a[i - 1].second};
    }
    for(int j = i + 1;j <= n;j++){
      if(mp[x - (a[i].first + a[j].first)].first && mp[x - (a[i].first + a[j].first)].second){
        cout <<a[i].second<<' '<<a[j].second<<' '<<mp[x - (a[i].first + a[j].first)].first<<' '<<mp[x - (a[i].first + a[j].first)].second;
        return 0;
      }
    }
  }
  cout <<"IMPOSSIBLE";
}
