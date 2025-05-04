#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ordered_set tree<pi, null_type,less<pi>, rb_tree_tag,tree_order_statistics_node_update>
#define w(t) int t; cin>>t; while(t--)
#define int long long int
#define I int32_t
#define asc(i,a,n) for(int i=a;i<n;i++)
#define dsc(i,n,a) for(int i=n;i>=a;i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MOD 1000000007
 
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
const long double PI = 3.1415926535897932384626433832795;
int modInv(int a){for(int x=1;x<MOD;x++){
if(((a%MOD)*(x%MOD))%MOD==1){return x;}}return 1;}
 
I main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vpi v(n);
    asc(i,0,n){
        cin>>v[i].second>>v[i].first;
    }
    sort(v.begin(),v.end());
    multiset<int>endTimes;
    int ans=0;
    asc(i,0,n){
        auto it=endTimes.ub(v[i].second);
        if(it!=endTimes.begin()){
            it--;
            endTimes.erase(it);
        }
        if(endTimes.size()<k){
            ans++;
            endTimes.insert(v[i].first);
        }
    }
    cout<<ans;
}