#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const N=1e6+10;
ll  MOD=1e9+7;
int main()
{ 
  int n,x;
  cin>>n>>x;
  vector<int>p(n),np(n);
  for(int i=0;i<n;i++){
        cin>>p[i];
  }
  for(int i=0;i<n;i++){
        cin>>np[i];
  }
  vector<vector<int>> dp2(n+1,vector<int>(x+1,0));
  for(int i=1;i<=n;i++){
    for(int j=0;j<=x;j++){
      dp2[i][j]=dp2[i-1][j];
      if(j>=p[i-1])
      dp2[i][j]=max(dp2[i][j],dp2[i-1][j-p[i-1]]+np[i-1]);
    }
  }
 cout<<dp2[n][x];
 return 0;
}
