#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define Created ios_base::sync_with_stdio(0);
#define By cin.tie(0);
#define Sofar cout.tie(0);
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const long long int MOD=1e9+7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;   
int main()
{
    Created By Sofar
    int n,t;
    cin>>n>>t;
    vector<ll> coins(n);
    for(auto &i : coins)cin>>i;
    vector<ll> dp(t+2,0);
    dp[0] = 1;
    for(auto &coin :coins)
    {
        for(int i = 1 ; i <= t ; i++)
            {
                if(i-coin >= 0)
                {
                    dp[i] += (dp[i-coin]%MOD); 
                }
            }
    }
    cout<<dp[t]%MOD;
 
    return 0;
}
 
