//Transform str1 to str2
#include<bits/stdc++.h>
#define ll long long
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vll vector<ll>
#define pb push_back
#define m_p make_pair
#define all(x) (x).begin(), (x).end()
#define INF LLONG_MAX
#define FOR(i, a, b) for(ll i=a; i<b; i++)
using namespace std;
 
const ll  N =1e6+5;
 
 
int main()
{ 
	FAST;
	     int tc;
	     //cin>>tc;
	     tc=1;
	 	while(tc--)
	 	{
	       
	       string s,t;
	       cin>>s>>t;
	       ll n = s.length();
	       ll m = t.length();
	       ll dp[n+1][m+1];
	       
	       FOR(i,0,n+1)
	       {
	           FOR(j,0,m+1)
	           {
                   if(i==0)
                   {
                       dp[i][j]=j ;//copy all characters of str2
                   }
                   else if(j==0)
                   {
                      dp[i][j]=i; 
                   }
	               //considering all operations on str1
                   else if(s[i-1]==t[j-1])
	               {
	                   dp[i][j] = dp[i-1][j-1];
	               }
	               else{
	                   dp[i][j] = 1 + min({dp[i-1][j], //remove the last char
                                          dp[i][j-1], //add
                                          dp[i-1][j-1]}); // replace
                                        
	               }
	           }
	       }
	        ll ans=dp[n][m];
	        cout<<ans<<endl;
	       
	 	}
}
 
 
 
