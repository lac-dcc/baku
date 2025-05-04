#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
 
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <deque>
#include <iomanip> 
#include <stack>
#include <iterator>
#include <complex>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
// ORDERED SET PBDS ( USE less<T> after null type for set and    less_equal<T> for multiset)
template<class T> 
using ordered_set = tree<T, null_type,less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to (k+1)th element 1,2,3,4 so, fbo(3)=4, o based indexing
// order_of_key(k) returns count of elements strictly smaller than k;
template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 
template<typename T>
void printVector(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
    cout<<'\n';
}
template<typename T>
void printVectorInVector(const T& t){
    std::for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
    cout<<'\n';
}
#define GODSPEED_SPIDERMAN ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define OH_oh(t) int t; cin>>t;
#define ull unsigned long long
#define ll long long
#define pb(i) push_back(i);
#define all(a)  a.begin(), a.end()
#define gall(a) a.begin(), a.end(), greater<int>()
#define mp(a, b)  make_pair(a, b)
#define pbk  pop_back()
#define printset(s) for(auto it: s){cout<<it<<" ";}
#define check(i) cout<<i<<endl;
#define concatenate(a, b) a.insert(a.end(), b.begin(), b.end());
const ll mod=1e9+7;
const ll moD=998244353;
const ll inf_big=1e18;
const ll inf=1e9;
const ll INF=1e18;
long double pi=2* acos(0.0);
 
int dp[13][12];
 
int lcs( int i, int j, string &s1, string &s2 ){
    
    if(i<0 or j<0) return 0;
 
    if( dp[i][j]>0 ){
        return dp[i][j];
    }
    else{
        if( s1[i] == s2[j] ){
            dp[i][j]= 1+ lcs( i-1, j-1, s1, s2 );
        }
        else{
            dp[i][j]= max( lcs( i-1, j, s1, s2 ), lcs( i, j-1, s1, s2 ) );
        }
    }
    return dp[i][j];
}
ll expo_mania(ll y, ll x){
    if(x==0) return 1;
    if(x==1) return y;
    else if(!(x&1)) return expo_mania(y*y, x/2);
    else return expo_mania(y*y, x/2)*y;
}
 
 
void dfs(vector<vector<int>> &v, vector<bool>& mark, int cur){
    mark[cur]=1;
    for(int i=0; i<v[cur].size(); i++){
        if(mark[v[cur][i]]==1){
            continue;
        }
        else{
            mark[v[cur][i]]=1;
            dfs(v, mark, v[cur][i]);
        }
    }
    return;
}
 
int main(){
    GODSPEED_SPIDERMAN;
    int n, m; cin>>n>>m;
    vector<vector<int>> v(n+1);
    vector<bool> mark(n+1, 0);
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int count=0;
    vector<pair<int, int>> paths;
    for(int i=1; i<=n; i++){
        if(mark[i]!=1){
            paths.push_back({i-1, i});
            count++;
            mark[i]=1;
            dfs(v, mark, i);
        }
    }
    cout<<count-1<<endl;
    for(int i=1; i<paths.size(); i++){
        cout<<paths[i].first<<" "<<paths[i].second<<endl;
    }
    
}
 
 
 
 
 
 
 
 
 
 
// int int ll ll 
