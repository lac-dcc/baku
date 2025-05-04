#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define trace(x) cerr<<#x<<"="<<x<<'\n'
#define sz(arr) ((int) arr.size())
#define len(str) ((int) str.length())
#define all(x) x.begin(), x.end()
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n;cin>>n;
vl nums(n);
for(int i=0;i<n;i++)cin>>nums[i];
ll res=-INF,act=0;
for(int i=0;i<n;i++){
	act+=nums[i];
	res=max(res, act);
	if(act<0)act=0;
}
cout<<res<<"\n";
return 0;
}
