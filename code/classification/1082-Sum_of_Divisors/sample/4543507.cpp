#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
 
ll naturalSum(ll n){
    ll a,b;
    if(n&1){
        a=n,b=(n+1)/2;
    }else{
        a=n/2,b=(n+1);
    }
    return ((a%mod)*(b%mod))%mod;
}
 
int main(){
    ll n;
    cin>>n;
 
    ll sum=0;
    for(ll x=1;x*x<=n;x++){
        ll count = n/x -x + 1;
        sum+=(count%mod)*x;
        sum%=mod;
        sum+=naturalSum(n/x)-naturalSum(x);
        sum+=mod;
        sum%=mod;
 
    }
    cout<<sum<<endl;
 
}
