# include<bits/stdc++.h>
 
using namespace std ;
 
# define f first
 
# define s second
 
# define in insert
 
# define ll long long
 
# define pb push_back
 
# define pob pop_back
 
# define INF INT_MAX
 
# define INFL LLONG_MAX
 
# define mod 1000000007
 
# define vi vector<int>
 
# define vvi vector<vi>
 
# define v(x) vector<x>
 
# define vv(x) v( v(x) )
 
# define pll pair<ll , ll>
 
# define pil pair<int , ll>
 
# define pli pair<ll , int>
 
# define pii pair<int , int>
 
# define all(v) v.begin() , v.end()
 
# define debug(x) cerr << '\n' << #x << " = " << x << '\n' ;
 
# define rep( i , s , e ) for( int i = s ; i <= e ; i++ )
 
# define repR( i , e , s ) for( int i = e ; i >= s ; i-- )
 
 
/**************************************************************************/
 
 
void solve() {
 
	string s , t ;  cin >> s >> t ;
 
	int n = s.size() , m = t.size() ;
 
	int dp[n][m] ;
 
	if ( s[0] == t[0] ) dp[0][0] = 0 ;
 
	else dp[0][0] = 1 ;
 
	rep ( i , 1 , n - 1 ) dp[i][0] = min ( 1 + dp[i - 1][0] , i + ( s[i] != t[0] ) ) ;
 
	rep ( j , 1 , m - 1 ) dp[0][j] = min ( 1 + dp[0][j - 1] , j + ( s[0] != t[j] ) ) ;
 
	rep ( i , 1 , n - 1 ) 
 
		rep ( j , 1 , m - 1 ) {
 
			// Add , Remove , Replace
 
			dp[i][j] = min ( { 1 + dp[i - 1][j] , 1 + dp[i][j - 1] , 1 + dp[i - 1][j - 1] } ) ;
 
			// if the i'th and j'th characters are same we don't need an operation for replace
 
			if ( s[i] == t[j] ) dp[i][j] = min ( dp[i][j] , dp[i - 1][j - 1] ) ;
		}
	
	cout << dp[n - 1][m - 1] ;
}
 
 
int main() {
 
	ios_base::sync_with_stdio( false ) ;
 
	cin.tie(0) , cout.tie(0) ;
 
	solve() ;  return 0 ;
}
