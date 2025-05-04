#include <bits/stdc++.h>
using namespace std;
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
//template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;//oset name name.order_of_key(#ele<k) *name.find_by_order(index) less_equal greater greater_equal
 
#define vi vector<int>
#define pii pair<int,int>
#define mii map<int,int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define int long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define back(v) v.rbegin(), v.rend()
#define yes cout << "YES" <<"\n";
#define no cout << "NO" <<"\n";
#define deb(a) cerr<< #a << "=" << (a)<<"\n";
#define nl "\n"
#define FastIO            \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define mod 1000000007
const int oo = 1e18;
void solve()
{
    int n;cin>>n;
    vector<vi>aa(n);
    mii renum;
    for(int i=0;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        aa[i]={a,b,c};
        renum[a]=1;renum[b]=1;
    }
    int j=1;
    for(auto [ac,bb]:renum){
        renum[ac]=j;j++;
    }
    sort(all(aa));
    vi dp(j+2,0);int k=0;
    for(int i=1;i<=j;i++){
        dp[i]=max(dp[i],dp[i-1]);
        while(k<n&&renum[aa[k][0]]==i){
            dp[renum[aa[k][1]]]=max(dp[renum[aa[k][1]]],dp[i-1]+aa[k][2]);
            k++;
        }
    }
    cout<<dp[j]<<nl;
 
}
signed main()
{
    FastIO;
    //freopen("p.in", "r", stdin);
    //freopen("p.out", "w", stdout);
    int test=1;
    // int test;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
