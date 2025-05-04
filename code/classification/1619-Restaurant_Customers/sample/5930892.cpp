#include <bits/stdc++.h>
 
// Program go brrr Fun stuff
#define Gotta ios_base::sync_with_stdio(false);
#define go cin.tie(nullptr);
#define fast cout.tie(nullptr);
 
 
// -----TEMPATE START-----
 
// Macros
#define For(i,k) for(int i=0;i<k;i++)
#define gcd __gcd
#define lcm(a,b) a*b/__gcd(a,b)
#define _memset(arr, to_set, start, end) for (int ___=start;___<end;___++) {arr[___]=to_set;}
 
// Debug
#ifdef DEBUG
#define Debug(expr) expr;
#endif
#ifndef DEBUG
#define Debug(expr) ;
#endif
 
 
// Aliases
#define ull unsigned long long
#define ll long long
#define vec vector
#define mp make_pair
#define pb push_back
#define fi first
#define se second
 
#define paint pair<int,int>
#define pii pair<int,int>
 
#define pall pair<ll,ll>
#define pll pair<ll,ll>
 
 
// Constants
const ll LL_INF = 1e18;
const int INF = 1e9;
 
#define MOD9 998244353
#define MOD1 1000000007
 
using namespace std;
 
// Multiple test cases or not
// #define BATCH true
 
// -----TEMPLATE END-----
 
 
void init() {
 
}
 
 
void solve() {
    int n;
    cin>>n;
    vec<int> a(n+1), b(n+1);
    for (int i=0;i<n;i++) {
        cin>>a[i]>>b[i];
    }
    a[n]=b[n]=2e9;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int curr,pa,pb,ans;
    curr=pa=pb=0;
    ans=0;
    while (pa<n || pb<n) {
        if (a[pa]<b[pb]) {
            curr++;
            pa++;
        } else {
            curr--;
            pb++;
        }
        ans=max(ans,curr);
    }
    cout<<ans<<endl;
}
 
 
int main(){
    Gotta go fast;
    int t=1;
    #ifdef BATCH
    cin >> t;
    #endif
    while (t--) {
        #ifdef BATCH
        Debug(cout << "TCase:" << t+1 << endl << "Calling Init\n");
        #endif
        init();
        #ifdef BATCH
        Debug(cout << "\nCalling Solve\n");
        #endif
        solve();
        #ifdef BATCH
        Debug(cout << "\n\n");
        #endif
    }
}
