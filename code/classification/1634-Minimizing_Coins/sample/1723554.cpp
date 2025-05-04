#include <bits/stdc++.h>
#define ll long long int
#define st string
using namespace std;
const int maxn=1e6,mod=1e9+7;
ll a1[maxn];
ll b1[maxn];
ll c1[maxn];
ll dp[maxn+10];
string c[1001];
int main(){
    std::ios_base::sync_with_stdio(false);
    ll n,k,a,b,z;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i];
        dp[a1[i]]=1;
    }
    for(int i=1;i<=1000000;i++){
        if(dp[i]!=0){
            a=dp[i]+1;
            for(int j=1;j<=n;j++)
            {
                if(dp[i+a1[j]]==0)
                    dp[i+a1[j]]=a;
                if(dp[i+a1[j]]>a)
                    dp[i+a1[j]]=a;
            }
        }
    }
    if(dp[k]==0)
        dp[k]=-1;
    cout<<dp[k];
}