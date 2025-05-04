#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const ll INF = 1e18;
char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
ll gcd(ll a,ll b){
    if((a==0) || (b==0)){
        return a+b;
    }
    if(a<b){
        return gcd(a,b%a);
    }
    return gcd(b,a%b);
}
ll dp[1000010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,c;cin>>n>>c;
    for(ll i=1;i<=c;i++){
        dp[i] = INF;
    }
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        dp[a[i]] = 1;
    }
    for(ll i=1;i<1000010;i++){
        if(dp[i]==INF){
            continue;
        }
        for(ll j=0;j<n;j++){
            if(i+a[j] >= 1000010){
                continue;
            }
            dp[i+a[j]] = min(dp[i+a[j]],1+dp[i]);
        }
    }
    dp[c]==INF ? cout<<"-1\n" : cout<<dp[c]<<"\n";  
    return 0;
}