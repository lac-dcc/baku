#include <bits/stdc++.h>
using namespace std;
 
#define hell 1000000007
#define PI acos(-1.0)
#define S second
#define F first
#define lli long long int
#define li long int
#define ld long double
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
lli numdigit(lli n){return floor(log10(n)) + 1;}
bool isPowerTwo (lli x) { return x && (!(x&(x-1))); } 
#define run(j, n) for(auto ii=j;ii!=n;ii++)
#define out(j, n) for(auto ii=j;ii!=n;ii++) cout<<(*ii)<<" ";
#define L_MAX LLONG_MAX
#define I_MAX 1e6
const int sz = 505;
 
lli gp[sz][sz];
 
 
 
void slv(int n)
{
  
  for(int k=0;k<n;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(gp[i][k]!=L_MAX && gp[k][j]!=L_MAX && gp[i][k]+gp[k][j]<gp[i][j])
        {
          gp[i][j]=gp[i][k]+gp[k][j];
        }
      }
    }
  }
 
 
}
 
 
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
cout << fixed << showpoint;
cout << setprecision(11);
 
/*
#ifndef ONLINE_JUDGE
freopen("inpute.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
*/
 
int t=1, x = 0;
//cin>>t;
while(t--)
{ 
  lli n, m, q;cin>>n>>m>>q;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
       gp[i][j]=L_MAX;
       if(i==j) {gp[i][j]=0;}
    }
  }
  for(int i=0;i<m;i++)
  {
    lli a, b, c;cin>>a>>b>>c;a--;b--;
    gp[a][b]=min(gp[a][b], c);gp[b][a]=min(c, gp[b][a]);
  }
  
 
  slv(n);
 
  while(q--)
  {
    int a, b;cin>>a>>b;a--;b--;
    if(gp[a][b]==L_MAX) cout<<"-1\n";
    else cout<<gp[a][b]<<"\n";
  }
 
  
  
} 
 
 
return 0;
}
