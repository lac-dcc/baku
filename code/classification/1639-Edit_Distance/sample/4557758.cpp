#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
 
const int INF=1e18;
const int mod=1e9+7; 
const int N=1e6+5;
 
int helper(string s,string t,int i,int j,vector<vi>& dp){
    int n=s.size(),m=t.size();
    if(i>=n || j>=m){
        if(i<s.size()){
            return s.size()-i;
        }
        if(j<t.size()){
            return t.size()-j;
        }
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    if(s[i]==t[j]){
        return dp[i][j] = helper(s,t,i+1,j+1,dp);
    }
    int op1=helper(s,t,i,j+1,dp);
    int op2=helper(s,t,i+1,j,dp);
    int op3=helper(s,t,i+1,j+1,dp);
 
    return dp[i][j]=1+min({op1,op2,op3});
}
 
void solve(){
    string s,t;
    cin>>s>>t;
    int x=s.size(),y=t.size();
    vector<vi> dp(x+1,vector<int>(y+1,-1));
    // int ans=helper(s,t,0,0,dp);
    dp[x][y]=0;
    fr(i,x,0){
        fr(j,y,0){
            if(i==x){
                dp[i][j]=y-j;
                continue;
            }
            if(j==y){
                dp[i][j]=x-i;
                continue;
            }
 
            if(s[i]==t[j]){
                dp[i][j]=dp[i+1][j+1];
            }else{
                dp[i][j]=1+min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]});
            }
        }
    }
    cout<<dp[0][0]<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1,x=1;
    // cin>>t;
    while(t--){
        // cout<<"Case #"<<x<<": ";
        // x++;
        solve();
        // cout<<endl;
    }
    return 0;
}