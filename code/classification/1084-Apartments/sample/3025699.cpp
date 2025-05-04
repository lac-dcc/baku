#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define S second
#define v vector
#define dbg(x)              cout<<#x<<"="<<(x)<<endl;
#define dbg2(x,y)           cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<endl;
#define dbg3(x,y,z)         cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<" "<<#z<<"="<<(z)<<endl;
#define dbg4(x,y,z,w)       cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<" "<<#z<<"="<<(z)<<" "<<#w<<"="<<(w)<<endl;
#define mp make_pair
#define pb push_back
#define endl                '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
void fun() {
 
#ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
 
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE
}
int main() {    
fun();
ll n,m,d;
cin>>n>>m>>d;
vector<ll> a1(n);
ll i;
for(i=0;i<n;i++)
  cin>>a1[i];
vector<ll> a2(m);
ll temp[m];
for(i=0;i<m;i++)
{
  temp[i]=-1;
}
for(i=0;i<m;i++)
 {
  ll x1;
  cin>>x1;
  a2[i]=x1;
 }
sort(a1.begin(),a1.end());
sort(a2.begin(),a2.end());
ll last=0,j,c=0;
for(i=0;i<n;i++)
{
 auto z1=lower_bound(a2.begin()+last,a2.end(),a1[i]-d)-a2.begin();
 
  for(j=z1;j<m;j++)
{
  if((a2[j]-a1[i])>=0&&(a2[j]-a1[i])<=d&&temp[j]==-1)
  {
    temp[j]=1;
    c++;
    last=j;
    break;
 
  }
  if((a1[i]-a2[j])>=0&&(a1[i]-a2[j])<=d&&temp[j]==-1)
  {
    temp[j]=1;
    c++;
    break;
  }
  if((a2[j]-a1[i])>=0&&(a2[j]-a1[i])>d)
    break;
 
}
 
}
cout<<c<<endl;
    return 0;
 
}
