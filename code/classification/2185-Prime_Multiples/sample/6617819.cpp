#include<bits/stdc++.h>
#include <cmath>
#include <complex>
#include<string>
    //freopen("orxor.in", "r", stdin);
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define dcm(a) setprecision(a)<<fixed
#define endl '\n'
 
void solve(int testCase){
ll n;
cin>>n;
int k;
cin>>k;
vector<ll> a(k);
for(int i=0;i<k;i++)
    cin>>a[i];
ll ans=0;
for(int i=1;i<(1<<k);i++){
    int numb=__builtin_popcount(i);
    ll x=1;
    bool flage=true;
    for(int j=0;j<k;j++){
        if(i&(1<<j)){
            if(log(x)+log(a[j])>log(n)){
                flage=false;
                break;
 
            }
            x*=a[j];
        }
    }
    if(!flage)
        continue;
    if(numb%2)
        ans+=(n/x);
    else
        ans-=(n/x);
}
cout<<ans<<endl;
}
 
int main()
{
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testCase=1;
    //cin>>testCase;
    for(int i=1; i<=testCase; i++)
        solve(i);
 
 
    return 0;
}