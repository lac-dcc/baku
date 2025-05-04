#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
 
#define endl "\n"
#define rep(i,a,b) for(int i=a; i<b; i++)
#define re(i,a) for(int i=0; i<a; i++)
#define red(i,a) for(int i=a; i>=0; i--)
#define repd(i,a,b) for(int i=a; i>=b; i--)
#define vll vector<ll>
#define mod 1000000007
#define all(c) c.begin(),c.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define PI           3.14159265358979323846
#define in(v,n) vi v(n);re(i,n) cin>>v[i]
 
 
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n,m,q;
     cin>>n>>m>>q;
     vector<vll> dp(n,vll(n,LLONG_MAX));
     re(i,n){
         dp[i][i]=0;
     }
     re(i,m){
     int x,y,z;
     cin>>x>>y>>z;
     if(dp[x-1][y-1]!=LLONG_MAX){
        dp[x-1][y-1]=min((int)dp[x-1][y-1],(int)z);
        dp[y-1][x-1]=min((int)dp[x-1][y-1],(int)z);
        continue;
     }
     dp[x-1][y-1]=z;
     dp[y-1][x-1]=z;
     }
     re(k,n){
         re(i,n){
             re(j,n){
                 if(dp[i][k]==LLONG_MAX || dp[k][j]==LLONG_MAX){
                     continue;
                 }
                 if(dp[i][k]+dp[k][j]<dp[i][j]){
                     dp[i][j]=dp[i][k]+dp[k][j];
                 }
             }
         }
     }
     re(i,q){
         int a,b;
         cin>>a>>b;
         if(dp[a-1][b-1]==LLONG_MAX){
             cout<<"-1"<<endl;
         } 
         else{
             cout<<dp[a-1][b-1]<<endl;
          }   
          }
}
