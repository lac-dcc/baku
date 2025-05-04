#include<bits/stdc++.h>
using namespace std;
 
#define int long long
using pii=pair<int, int>;
using vi=vector<int>;
using vvi=vector<vector<int>>;
 
//using ll=long long;
 
#define loop(x,n) for(int x=0; x<n; x++)
#define loop1(x,n) for(int x=1; x<=n; x++)
#define loopr(x,n) for(int x=n; x-->0;)
 
#define pb push_back
#define lb lower_bound
#define mp make_pair
#define all(v) begin(v), end(v)
#define UNTIE_IO ios_base::sync_with_stdio(0);cin.tie(0);
 
const int SIZE=2e5+5;
const int INF=2e9;
const int MOD=998244353;
 
int a[2][42];
vector<int> ss[2];
 
void f(bool bn, int x){
    loop(mask, 1<<x){
        int s=0;
        loop(j,x){
            if ((mask>>j)&1) s+=a[bn][j];
        }
        ss[bn].pb(s);
    }
    sort(all(ss[bn]));
}
 
signed main(){
    UNTIE_IO;
    int N,X;
    cin>>N>>X;
 
    int m=(1+N)/2;
    loop(i,m) cin>>a[0][i];
    loop(i,N-m) cin>>a[1][i];
 
    f(0,m);
    f(1,N-m);
 
    int ans=0;
    for (int x: ss[0]){
        ans += upper_bound(all(ss[1]), X-x)-lower_bound(all(ss[1]), X-x);
    }
    cout << ans;
}
