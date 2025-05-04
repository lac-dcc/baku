 #include<bits/stdc++.h>
using  namespace std;
#define  ll   long long
#define  pb push_back
#define  lb lower_bound
#define  ub upper_bound
#define  fr first
#define  sc second
#define  memset( a, b )  memset( a, b , sizeof(a) )
#define  PI  3.1415926535897932384626
#define  lcm( a,b )  ( ( a )*( b) )/( __gcd((a),(b) ))
#define  gcd ( a,b )  __gcd( (a), (b))
#define  mod  1000000007
#define  fast()  ios_base::sync_with_stdio ( false) ,   cin.tie( nullptr ),cout.tie( nullptr );
#define  rrep( i , n)  for( i=n-1 ; i>=0 ; i--)
#define  rep( i , n )   for( i=0 ; i<n; i++ )
#define  int_max  1000000000000000000
 
 
ll t ,d , ct , q , ans ,l , r ,n ,m, i, j, k ,x , y , z , s  ;
 
 char ch;   double dr;     string ss = "" ,  str = "" ;
 
 map<pair<ll , ll>,ll>mp   ;        set< ll >st ;  
 
  ll a[200003] , b[200003] ;     // ll arr[200003] = {0} , c[2000003]; 
  
 // bool vis[200003] ;           vector< ll >vec[200003];   
  
 
 
 
 int main(){   	   fast()
 
 
 //  cin>>t ; while( t-- ) {
 
   s = k = d = l = m= r= q =i = j = z= x= y =ct =ans = 0;
 
cin>>n>>x ;
rep(i ,n) cin>>a[i] ;
 
ll dp[x+1]  ;
dp[0] = 0;
for(i=1 ; i<=x ;i++)
{  dp[i] = int_max ;
  
    for(j=0; j<n; j++)
    if(a[j] <= i) dp[i] = min(dp[i] , dp[i-a[j]] +1 ) ;
   
}
if(dp[x]== int_max) cout<<-1;
else 
cout<<dp[x] ;
 
 
 
   return 0;
     
}
