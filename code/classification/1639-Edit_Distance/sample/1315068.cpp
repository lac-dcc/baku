#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long int
#define tinput int t; cin>>t; while(t--)
#define rep(i,n,s) for((i)=(s); (i)<(n); (i)++)
 
template <typename T>
T getmini(T x, T y) { return (x<y)?x:y; }
template <typename T>
T getmaxi(T x, T y) { return (x>y)?x:y; }   
ll M = 1e9+7;
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("d_input.txt", "r", stdin);  freopen("d_output.txt", "w", stdout);
    #endif
    boost;
    
    string s1,s2;
    cout << "here" << endl;
    cin>>s1>>s2;
    int n = s1.length(), m = s2.length();
    cout << "here1" << endl;
    int dp[n+1][m+1];
    cout << "here2" << endl;
    memset(dp, 0, sizeof(dp));
    for(int i = 0;i<=n;i++) {
        for(int j = 0;j<=m;j++) {
            if(i==0 || j==0) {
                dp[i][j] = getmaxi<int>(i, j);
            }
            else {
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {                  //        delete                    replace        add      
                    dp[i][j] = 1 + getmini<int>(dp[i][j-1], getmini<int>(dp[i-1][j-1], dp[i-1][j]));
                }
            }
           // cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
