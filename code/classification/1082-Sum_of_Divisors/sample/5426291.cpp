#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
//const int M=998244353;
const int M=1e9+7;
 
 
int32_t main(){
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
int n;
cin>>n;
 
int x=ceil(sqrt(n));
 
int ans=0;
auto P=[&](int a,int b){
    int res=1;
 
    while(b){
        if(b&1)
        res=res*a%M;
        a=a*a%M;
        b=b>>1;
    }
    return res;
};
 
auto MI=[&](int a){
    return P(a,M-2);
};
 
for(int i=1;i<=n/(x+1);i++)
{
    int x=i;
    int y=n/i;
    x%=M;
    y%=M;
    ans+=x*y%M;
    ans%=M;
}
 
for(int i=1;i<=x;i++){
    int c=n/i - n/(i+1);
    int d=n/i + n/(i+1) +1;
    c%=M;
    d%=M;
    int x=i;
    
    ans+=i%M*c%M*d%M*MI(2)%M;
    ans%=M;
}
 
cout<<ans<<"\n";
}