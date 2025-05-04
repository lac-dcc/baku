#include<bits/stdc++.h>
using namespace std;
#define int long long
#define w int t;cin>>t;while(t--)
#define v(n) int n;cin>>n;
#define pb push_back
#define vi(name,size) vector<int>name(size);for(int i =0;i<size;i++) cin>>name[i];
#define f(n) for(int i =0;i<n;i++)
#define all(vv) vv.begin(), vv.end()
 
#define pri(vv) f(vv.size()) cout << vv[i] << char(32);cout<<endl;
int n;
int a[110];
int dp[1000101];
int rec(int x){
    if(x==0)
        return 0;
    if(dp[x]!=-1)
        return dp[x];
    int temp = INT_MAX;
    for (int i = 0; i < n;i++){
        // cout << a[i] << " " << x << endl;
        if(a[i]<=x){
            temp = min(temp, 1 + rec(x - a[i]));
            // cout << a[i];
            // cout << rec(x - a[i]) << " ";
        }
        
    }
    return dp[x]=temp;
}
int32_t main(){ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    // v(n);
    // int x;
    // cin >> x;
    cin >> n;
    v(x);
    memset(dp, -1, sizeof(dp));
    f(n){
        cin >> a[i];
    }
    int k = rec(x);
    if(k==INT_MAX)
        cout << -1 << endl;
    else
        cout << k << endl;
    // cout << rec(x);
}
