#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
 
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n,x;cin>>n>>x;int a[n];
for(int i=0;i<n;cin>>a[i++]);
//pab[n*n][];memset(b,0,sizeof b);
vector<pair<int,pair<int,int>>>vp;
 
//sort(b,b+n);
int stat=1;
int ans[4];memset(ans,0,sizeof ans);
for(int i=0;i<n&&stat;i++)
{
  for(int j=i+1;j<n&&stat;j++)
  {
    vp.push_back({a[i]+a[j],{i,j}});
    
  }
}
sort(vp.begin(),vp.end());
for(int i=0;i<n&&stat;i++)
{
  for(int j=i+1;j<n&&stat;j++)
  {
    auto it=lower_bound(vp.begin(),vp.end(),make_pair(x-a[i]-a[j],make_pair(-1,-1)));
    int cnt=1;
    while(it!=vp.end()&&cnt<7&&x-a[i]-a[j]==it->fi&&stat)
    {
      if(it->se.fi!=i&&it->se.se!=j&&it->se.fi!=j&&it->se.se!=i)
      stat=0,ans[0]=it->se.fi,ans[1]=it->se.se,ans[2]=i,ans[3]=j;
      cnt++,it++;
    }
  }
}
 
//sort(vp.begin(),vp.end());
 
// for(int i=0;i<n&&stat;i++)
// {
//   auto it=lower_bound(vp.begin(),vp.end(),make_pair(x-a[i],make_pair(-1,-1)));
//   int cnt=1;
//   while(it!=vp.end()&&x-a[i]==(it->first)&&stat&&cnt<5)
//   {
//       if(i!=it->se.fi&&i!=it->se.se)
//       stat=0,ans[0]=i,ans[1]=it->se.fi,ans[2]=it->se.se;
//       cnt++;it++;
//   }
// }
sort(ans,ans+3);
if(stat)
cout<<"IMPOSSIBLE";
else
for(auto x:ans)cout<<x+1<<" ";
 
}