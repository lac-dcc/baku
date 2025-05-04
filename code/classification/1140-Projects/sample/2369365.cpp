#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int               long long
#define precise(a)        fixed<<setprecision(a)
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i = a; i < b; i++)
#define rrep(i,b,a)        for(int i = b; i >= a ; i--)
#define trav(a, x)        for(auto& a : x)
#define display(x)        trav(a,x) cout<<a<<" "; cout<<endl;
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define PI                3.14159265358979323844
#define INF               1000000000000000000
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
template<typename T>using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
 
 
// GRAPH DIRECTIONS
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
 
 
//Returns index of first element not less than key and more than key respectively
#define lb(data,key) lower_bound(all(data),key) - data.begin();
#define up(data,key) upper_bound(all(data),key) - data.begin();
#define fnd(data,key) find(all(data),key) - data.begin();
 
//MODS
const int32_t M=1e9+7;
const int32_t MM=998244353;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(3));
    rep(i, 0, n){
        rep(j, 0, 3){
            cin>>a[i][j];
        }
    }
    sort(all(a),[&](vector<int> &A, vector<int> &B){
        if(A[1] == B[1])
            return A[0] < B[0];
        return A[1] < B[1];
    });
    vector<int> endpoints(n);
    rep(i, 0, n) endpoints[i] = a[i][1];
    vector<int> dp(n+1);
    dp[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        int op1 = dp[i-1];
        int op2 = a[i-1][2];
        int itr = lb(endpoints, a[i-1][0]);
        if(itr != 0){
            op2 += dp[itr];
        }
        dp[i] = max(op1, op2);
    }
    cout<<dp[n]<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}