#include<bits/stdc++.h>
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
#define endl "\n"
#define ss second
#define ff first
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vl vector<ll>
#define vll vector<pair<ll,ll>>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd  pair<double,double>
#define vdd  vector<pdd>
#define speed ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
 
const ll mod = 1e9 + 7;
 
int coins[105];
int n;
 
int dp[1000005];
 
int main(){
    memset(dp, 0, sizeof dp);
    speed;
    cin >> n;int x;cin >> x;
    for(int i = 1; i <= n;i++){
        cin >> coins[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= n;i++){
        for(int w = 0; w <= x;w++){
            if(w - coins[i] >= 0){
                dp[w] += dp[w - coins[i]];
                dp[w] %= mod;
            }
        }
    }
    cout << dp[x] << endl;
}
 
/*
    NEVER GIVE UP!
    DOING SMTHNG IS BETTER THAN DOING NTHNG!!!
*/