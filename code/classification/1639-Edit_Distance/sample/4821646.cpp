#include <bits/stdc++.h>
#include <vector>
 
#define cn count
#define pb push_back
#define in insert
#define fs first
#define sc second
#define sz size
#define len length
#define X real()
#define Y imag()
#define forn(i, n) for (ll i = 0; i < (ll) (n); ++i)
#define forn1(i, n) for (ll i = 1; i < (ll) (n); ++i)
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(),s.rend()
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define precise(n,k) fixed << setprecision(k) << n
 
using namespace std;
using ll = long long;
typedef complex<ll> P;
const ll inf = 1e9+7; 
const double PI =  3.141592653589793;
 
int main(){
	IO;
	string n,m;
	cin>>n>>m;
	vector<vector<ll>> dp(n.len()+1, vector<ll> (m.len()+1, 0));
	forn(i,n.len()+1){
		forn(j,m.len()+1){
			if(i==0) dp[i][j] = j;
			else if(j==0) dp[i][j] = i;
			else {
				dp[i][j] = min(dp[i][j-1]+1ll,min(
						dp[i-1][j]+1ll,
						dp[i-1][j-1] + (n[i-1]==m[j-1]? 0ll : 1ll)));
			}
		}
	}
	cout<<dp[n.len()][m.len()]<<'\n';
	return 0;
}
 
 
// _   .-')                .-. .-')                 .-')                                               
//( '.( OO )_              \  ( OO )               ( OO ).                                             
// ,--.   ,--.).-'),-----. ,--. ,--.  .-'),-----. (_)---\_) ,--. ,--.     .-----.  ,-.-')  .-'),-----. 
// |   `.'   |( OO'  .-.  '|  .'   / ( OO'  .-.  '/    _ |  |  | |  |    '  .--./  |  |OO)( OO'  .-.  '
// |         |/   |  | |  ||      /, /   |  | |  |\  :` `.  |  | | .-')  |  |('-.  |  |  \/   |  | |  |
// |  |'.'|  |\_) |  |\|  ||     ' _)\_) |  |\|  | '..`''.) |  |_|( OO )/_) |OO  ) |  |(_/\_) |  |\|  |
// |  |   |  |  \ |  | |  ||  .   \    \ |  | |  |.-._)   \ |  | | `-' /||  |`-'| ,|  |_.'  \ |  | |  |
// |  |   |  |   `'  '-'  '|  |\   \    `'  '-'  '\       /('  '-'(_.-'(_'  '--'\(_|  |      `'  '-'  '
// """    """     """""""" """  """"      """""""  """""""  """"""""      """"""   """         """""""
 