/* code of Ayush Tiwari
    codeforces- servermonk
    codechef- ayush572000
*/
 
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
 
//STL
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair 
#define all(v) v.begin(), v.end()
 
//loops
#define forn(i,a,b) for(int i=a;  i<b; i++)
#define rforn(i,a,b) for(int i=a; i>=b; i--)
 
// defined values
#define maxn 200004
#define Mod 1000000007
 
// fast io
#define FIO() ios_base::sync_with_stdio(0);cin.tie(0);
 
 
using namespace std;
 
 
void solution(){
 
    // This is the main code
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    forn(i,0,n) cin>>a[i];
    // forn(i,0,n) cout<<a[i]<<" ";
    ll mid=n/2;
    vector<ll> left, right;
    forn(i,0,(1<<mid)){
        ll sum=0;
        forn(j,0,21){
            if(i&(1<<j)) sum+=a[j];
        }
        left.pb(sum);
    }
    ll rem=n-mid;
    forn(i,0,(1<<rem)){
        ll sum=0;
        forn(j,0,21){
            if(i&(1<<j)) sum+=a[j+mid];
        }
        right.pb(sum);
    }
    // for(auto z: right) cout<<z<<" ";
    ll ans=0;
    // cout<<right[3];
    sort(all(right));
    for(int i=0;i<left.size();++i){
        ans += upper_bound(all(right), x - left[i]) - lower_bound(all(right), x - left[i]);
    }
    cout<<ans<<endl;
}
 
 
int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("D:/competitive-programming/input.txt","r",stdin);
    freopen("D:/competitive-programming/output.txt","w",stdout);
    #endif  
    
    FIO()   
    
    int t=1;
    // cin>>t;
    while (t--)
    {
        solution();
    }
    return 0;
}
