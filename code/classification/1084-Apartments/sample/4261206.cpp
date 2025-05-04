#include <bits/stdc++.h>
 
using namespace std;
typedef vector <int> vi;
typedef pair<int,int> pi;
typedef long long ll;
typedef long double ld;
#define FOR(i,a,b) for (int i=a;i<b;i++)
#define nl "\n"
#define pb push_back
#define fio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
 
void init_code(){
    fio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
 
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[n],b[m];
    FOR(i,0,n)
        cin>>a[i];
    FOR(i,0,m)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    ll i = 0,j=0,ans=0;
    while(1){
        if(i==n or j==m)
            break;
        if(a[i]-k>b[j])
            j++;
        else if(a[i]+k<b[j])
            i++;
        else{
            ans++;
            i++;
            j++;
        }
    }
    cout<<ans<<nl;   
}
 
int main(){
    init_code();
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
}
