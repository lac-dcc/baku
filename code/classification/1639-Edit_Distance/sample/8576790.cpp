// #include<debugger.h>
 
#include<bits/stdc++.h>
using namespace std;
 
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
 
#define int long long
// typedef long long ll;
// typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
#define endl '\n'
#define mem(a,b) memset(a, b, sizeof(a))
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 
#define MOD 1000000007
const double PI = acos(-1);
const double eps = 1e-9;
 
// int dx[] = {0, 0, +1, -1, -1, +1, -1, +1};
// int dy[] = {+1, -1, 0, 0, -1, +1, +1, -1};
 
int dp[5010][5010];
 
int func(string &s1, string &s2, int i, int j) {
    if (i == s1.size())
        return s2.size() - j;
    
    if (j == s2.size())
            return s1.size() - i;
    
    if (dp[i][j] != -1) return dp[i][j];
    
    int ans = func(s1, s2, i + 1, j + 1) + (s1[i] != s2[j]);
    
    ans = min(ans, func(s1, s2, i + 1, j) + 1);
    
    ans = min(ans, func(s1, s2, i, j + 1) + 1);
 
    return dp[i][j] = ans;
}
 
void solve(int ti)
{   
    memset(dp, -1, sizeof(dp));
 
    string s1, s2;
    cin >> s1 >> s2;
    cout << func(s1, s2, 0, 0) << endl;
}   
 
int tc = 0;
 
int32_t main()
{   
 
    
    optimize();
    // file();
    if(tc){int t;cin>>t;for(int i=1;i<=t;i++)solve(i);} 
    else solve(1);
    return 0;
}
