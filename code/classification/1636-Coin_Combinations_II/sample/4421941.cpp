#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define F(i,L,R) for (int i = L; i < R; i++) 
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
const ll inf = LLONG_MAX;
const int MOD = int(1e9)+7;
 
const int NMAX=int(1e6)+10;
int n,x;
vi c;
ll dp[NMAX];
 
int main(){
	cin>>n>>x;
	F(i,0,n){
		int t; cin>>t;
		c.pb(t);
	}
	
	dp[0]=1;
	for (auto coin : c ) {
		for (int weight=0; weight <= x ; ++weight)
			if (weight-coin>=0) {
				dp[weight]+=dp[weight-coin];
				dp[weight]%=MOD;
			}
	}
	
	cout<<dp[x];
	return 0;
}
