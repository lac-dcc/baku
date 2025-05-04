                        // Keep a little fire burning; 
                        // however small , however hidden;
// Small milate jao , large banate jao !!!
#pragma GCC optimize("O3")
#include<bits/stdc++.h>                      
using namespace std ;                        
typedef long long int ll;                   
typedef long double ld;                     
#define int long long                       
#define PB push_back                        
#define MP make_pair                      
#define F first                           
#define S second                          
#define ii pair <int,int>                 
#define P push                            
#define endl "\n"                        
#define vvi vector<vector<int> >        
#define vi vector<int>                   
#define vpi vector< pair<int,int> >       
#define sz(a) (int)a.size()             
#define all(a)   a.begin() , a.end()     
const ll mod =1e9+7  , N =  1e5+7;//  
#define fastrack ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void io(){ 
// #ifndef ONLINE_JUDGE                                                                 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
// #endif
   }
 
int modularbinary(int base ,int exp)
{
    if(exp==0)
        return 1;
    int result =modularbinary(base , exp/2);
    if(exp%2==1)
    {
        return (((result*result)%mod)*base)%mod;
    }
    else
        return (result*result)%mod;
 
}
 
int fact[1000005]={};
 
int power(int x,int y){
    int res=1;
    x=x%mod;
    while(y>0){
        if(y&1)
        res=((res%mod)*(x%mod))%mod;
        y=y>>1;
        x=((x%mod)*(x%mod))%mod;
    }
    return res;
}
 
void pre(){
   fact[0]=1;
   for (int i=1;i<1000005;i++)
   {
      fact[i]=i*fact[i-1];
      fact[i]%=mod;
   }
}
int ncr(int n,int r){
   if (r>n) return 0;
   int num = fact[n];
   int den = (fact[n-r]*fact[r])%mod;
   den = power(den,mod-2);
   return (num*den)%mod;
}
 
struct comp{
bool operator()( const pair<int , int> &p1 , const pair<int ,int> &p2 )
{
    if(p1.first!=p2.first)
    {
        return p1.first>p2.first;
    }
    else
    {
        return p1.second>p2.second;
    }
}
};
 
pair<int , int> dir[4]={{1 ,0},{-1 ,0} ,{0 ,1} ,{0 ,-1}};
//-----------------------------------------------------------------------------------------------------
 
int dp[1000007];
signed main()
{                                              
    // io();                  
    fastrack;                                          
    int t=1;
    // cin>>t;             
    while(t--){
       int n , x;
       cin>>n>>x;
 
       int a[n];
 
       for(int i=0;i<n;i++)
        cin>>a[i];
 
       //int dp[x+5]={};
       vector<int> dp(x + 5, 0);
       dp[0]=1;
 
       for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i>=a[j])
            dp[i]=(dp[i]+dp[i-a[j]])%mod;
        }
       }
 
       cout<<dp[x]<<endl;
    }
return 0;
}    
