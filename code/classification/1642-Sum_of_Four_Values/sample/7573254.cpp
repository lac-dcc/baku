#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
 
bool solve(ll lef, ll rig, vvl & pairs, ll tar){
	while(lef < rig){
    	// cout<<pairs[lef][1]<<" "<<pairs[lef][2]<<" "<<pairs[rig][1]<<" "<<pairs[rig][2]<<endl;
    	if(pairs[lef][0] + pairs[rig][0] == tar){
    		if(pairs[lef][1] == pairs[rig][1] || pairs[lef][1] == pairs[rig][2] || pairs[lef][2] == pairs[rig][1] || pairs[lef][2] == pairs[rig][2]){
    			return solve(lef+1, rig, pairs, tar) || solve(lef, rig-1, pairs, tar);
    		}
    		else{
    			cout<<pairs[lef][1]+1<<" "<<pairs[lef][2]+1<<" "<<pairs[rig][1]+1<<" "<<pairs[rig][2]+1;
    			return true;
    		}
       	}
    	else if(pairs[lef][0] + pairs[rig][0] < tar)
    		lef++;
    	else
    		rig--;
    }
    return false;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    #ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    ////////
 
    ll n, tar; cin>>n>>tar;
 
    vl vals(n);
    for(ll i=0; i<n; i++)
    	cin>>vals[i];
 
    vvl pairs;
 
    for(ll i=0; i<n-1; i++){
    	for(ll j = i+1; j<n; j++){
    		vl temp{vals[i] + vals[j], i, j};
    		pairs.pb(temp);
    	}
    }
 
    sort(pairs.begin(), pairs.end());
 
    ll lef = 0, rig = pairs.size()-1; 
 
    if(!solve(lef, rig, pairs, tar))
    	cout<<"IMPOSSIBLE";
 
    ///////
 
    #ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
    #endif
 
    return 0;
}