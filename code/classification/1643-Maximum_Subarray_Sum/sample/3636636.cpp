                              /*Bismillahir Rahmanir Rahim*/
 
#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define ff      first
#define ss      second
#define ll     long long int
#define dd      double
#define pb      push_back
#define pr      pair<ll,ll>
#define pqmx    priority_queue<ll>
#define pqmn    priority_queue<ll,vector<ll>,greater<ll>>
#define MOD     998244353
#define pd(x,y)     fixed<<setprecision(y)<<x
#define w(x)     ll x; cin>>x; while(x--)
#define loop(i,x,n) for(ll i=x;i<n;i++)
#define rloop(x,n) for(ll i=n-1;i>=x;i--)
#define all(x)            (x).begin(),(x).end()
#define rall(x)            (x).rbegin(),(x).rend()
#define dbg1(x)      cout<<"["<<#x<<": "<<x<<"]"<<endl;
#define dbg2(x, y) cout<<"["<<#x<<": "<<x<<"]"<<"  ["<<#y<<": "<<y<<"]"<<endl;
#define dbg3(x, y, z) cout<<"["<<#x<<": "<<x<<"]"<<"  ["<<#y<<": "<<y<<"]"<<"  ["<<#z<<": "<<z<<"]"<<endl;
#define dbg4(x, y, z, k) cout<<"["<<#x<<": "<<x<<"]"<<"  ["<<#y<<": "<<y<<"]"<<"  ["<<#z<<": "<<z<<"]"<<"  ["<<#k<<": "<<k<<"]"<<endl;
#define no          cout << "NO" << endl;
#define yes          cout << "YES" << endl;
#define endl            "\n"
#define FAST     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi        3.141592653
 
//Samee Sevas
 
ll const N=1000006;
#define mxp 1000007
 
using namespace std;
 
void solve()
{
  
 ll n,m,k;
 cin>>n;
vector<ll> a(n);
ll ans=0;
  loop(i,0,n)
  {
    cin>>a[i];
  ans+=a[i];
 
  }
  //ll pre[n+10]={0};
  vector<ll> pre(n + 10, 0); 
  loop(i,0,n)
  {
    pre[i+1]=pre[i]+a[i];
  }
  ll mn=0;
 
  loop(i,1,n+1)
  {
  
    ans=max(ans,pre[i]-mn);
    mn=min(mn,pre[i]);
     // dbg1(ans)
    
  }
 cout<<ans<<endl;
  
  
 
  
 
}
signed main()
{
  //  freopen("runway_input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
   FAST;
         ll t=1,u=0; 
        // cin>>t; 
   
      
         while(t--)
         {
           //cout<<"Case #"<<++u<<": ";
             solve();
         }
      
   
 }
