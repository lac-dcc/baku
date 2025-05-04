#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> pii;
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mk make_pair
#define en '\n'
 
const int MOD = 1000000007;
 
// -1 3 -2 5 3 -5 2 2
// 9
 
void solve(){
    int n;
    cin >> n;
 
    int a[n];
    for(auto &x:a) cin >> x;
 
    ll curr_max,global_max,i = 1;
	curr_max = global_max = a[0];
 
	while(i < n){
		curr_max = max((ll)a[i],curr_max+a[i]);
		if(curr_max > global_max) global_max = curr_max;
		i += 1;
	}
	cout << global_max << en;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    //freopen("div7.in","r",stdin);
    //freopen("div7.out","w",stdout);
 
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}   
