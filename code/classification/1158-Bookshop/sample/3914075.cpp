#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ull unsigned long long
#define fin for(int i=0;i<n;i++)
#define repj(l,r) for(int j=l;j<r;j++)
#define repi(l,r) for(int i=l;i<r;i++)
#define pii pair<int,int>
 #define vii vector<int>
 #define bu(n) 63-__builtin_clzll(n)
 #define nobu(n) __builtin_popcount(n)
#define prdj priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> >
const int eps=1000000007;
const int N = 1e7+5;
vector<int> spf(N+1,0);
void spff(){
for(int i=2;i*i<=N;i++){
if(spf[i]!=0) continue;
spf[i]=i;
for(int j=i*i;j<=N;j+=i){
if(spf[j]==0) spf[j]=i;
}
}
}
bool is[1000001];
void primesieve(){
for(int i=0;i<=1000000;i++){
is[i]=1;
}
is[1]=0;
is[0]=0;
for(int i=2;i*i<=1000000;i++){
if(is[i]==1){
for(int j=i*i;j<=1000000;j+=i){
is[j]=0;
}
}
}
}
int lcm (int a, int b)
{
    return  (a*b) / __gcd(a,b);
}
int mi(vector<int> &a,int k,int n){
    int sm=0;
    for(int i=0;i<n;i++){
        sm+=abs(a[i]-k);
    }
    return sm;
}
int bin(int i,int n,int x,int arr[]){
int lo=i;
int hi=n-1;
int ans=-1;
while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(arr[mid]+x>0){
        hi=mid-1;
        ans=mid;
    }
    else lo=mid+1;
}
return ans;
}
int n,m;
int noc;
int lar;
vector<pair<int,pii>> adj;
vector<bool> vis;
vii ran;
vii par;
void make_set(){
  for(int i=0;i<=n;i++) {
        par[i]=i;
        ran[i]=1;
  }
}
int find_lea(int k){
if(par[k]==k) return k;
return par[k]=find_lea(par[k]);
}
void un(int i,int j){
int u=find_lea(i);
int r=find_lea(j);
if(u!=r){
    if(ran[u]>ran[r]){
        par[r]=u;
        ran[u]+=ran[r];
       // lar=max(lar,ran[u]);
    }
    else{
        par[u]=r;
        ran[r]+=ran[u];
       // lar=max(lar,ran[r]);
    }
   // noc--;
}
}
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     int t;
  t=1;
//cin>>t;
       while(t--){
cin>>n;
int x;cin>>x;
int a[n+1];fin cin>>a[i+1];
int b[n+1];fin cin>>b[i+1];
int dp[n+1][x+1];
memset(dp,0,sizeof(dp));
dp[0][0]=0;
for(int i=1;i<=n;i++){
    for(int j=1;j<=x;j++){
            dp[i][j]=dp[i-1][j];
       if(j>=a[i]) dp[i][j]=max(dp[i-1][j-a[i]]+b[i],dp[i-1][j]);
 
    }
}
int ans=0;
//repi(1,x+1) ans=max(ans,dp[i]);
cout<<dp[n][x];
}
}