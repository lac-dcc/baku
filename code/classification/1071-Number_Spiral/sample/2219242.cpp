#include <iostream>
#include <vector>
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define mod 1000000007
 
ll power(ll a, ll b, ll m = mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        b = b >> 1;
        a = (a * a) % m;
    }
    return res;
}
 
ll solve(ll y,ll x){
    ll temp;
    if(y>x){
        temp=(y-1)*(y-1);
        if(y%2==0)
            temp+=y+y-x;
        else
            temp+=x;
    }
    else{
        temp=(x-1)*(x-1);
        if(x%2==0)
            temp+=y;
        else
            temp+=x+x-y;
    }
    return temp;
 
}
 
int main() {
    ll t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<solve(a,b)<<"\n";
    }
}
