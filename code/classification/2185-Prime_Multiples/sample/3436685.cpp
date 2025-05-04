#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
 
int n,k,ans;
vi primes;
void prime(string s,int i){
    if(i==k){
        int curr=n;
        int count=0;
        asc(i,0,k){
            if(s[i]=='1'){
                count++;
                curr/=primes[i];
            }
        }
        if(count==0){
            return;
        }
        if(!(count&1)){
            curr=-1*curr;
        }
        ans+=curr;
        return;
    }
    s.push_back('1');
    prime(s,i+1);
    s.pop_back();
    s.push_back('0');
    prime(s,i+1);
}
I main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    primes.resize(k);
    asc(i,0,k){
        cin>>primes[i];
    }
    ans=0;
    string s="";
    prime(s,0);
    cout<<ans;
}