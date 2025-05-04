#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define x           first
#define y           second
#define all(v)      v.begin(),v.end()
#define clr(v,d)    memset(v,d,sizeof(v));
 
const int N =  5e3 + 2 ;
const int mod = 1e9 + 7;
 
ll n, m, k ;
 
string s ,ss ;
ll dp[N][N];
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
 
    cin >> s >> ss;
 
    for(int j =0 ; j < ss.size() ; j++)
    {
        dp[s.size()][j] = ss.size() - j ;
    }
 
    for(int i =0 ; i < s.size() ; i++) dp[i][ss.size()] = s.size() - i;
 
    for(int i =s.size()-1 ; i >=0  ; i--)
    {
        for(int j =ss.size()-1 ; j >= 0 ; j--)
        {
            ll & ret = dp[i][j] ;
 
            ret = 1e18 ;
 
            if(s[i] == ss[j])
            {
                ret = dp[(i+1)][j+1];
            }
 
            ret = min(ret , 1 + dp[(i+1)][j+1] ) ; //replace
            ret = min(ret , 1 + dp[i][j+1] ) ; // add
            ret = min(ret , 1 + dp[(i+1)][j] ) ; //remove
        }
    }
 
    cout << dp[0][0] ;
 
    return 0;
}