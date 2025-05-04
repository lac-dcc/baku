#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int mod=1000000007;
struct mint{
    int a;
    mint()=default;
    mint(int x):a((x%mod+mod)%mod){}
    mint operator+(const mint &x)const{return this->a+x.a;}
    mint operator-(const mint &x)const{return this->a-x.a;}
    mint operator*(const mint &x)const{return this->a*x.a;}
    mint &operator+=(const mint x){*this=*this+x; return *this;}
    mint &operator-=(const mint x){*this=*this-x; return *this;}
    mint &operator*=(const mint x){*this=*this*x; return *this;}
    mint &operator++(){return *this+=1;}
    mint &operator--(){return *this-=1;}
    mint operator-()const{return (this->a?mod-this->a:0);}
    mint power(int y)const{
        mint x=*this;
        mint res=1;
        while(y){
            if(y&1) res*=x;
            x*=x;
            y>>=1;
        }
        return res;
    }
    mint inv()const{return power(mod-2);} //mod must be prime
    mint operator/(const mint &x)const{return *this*x.inv();}
    mint &operator/=(const mint &x){*this=*this/x; return *this;}
    bool operator==(mint x)const{return (this->a==x.a);}
    bool operator!=(mint x)const{return (this->a!=x.a);}
    bool operator<(mint x)const{return (this->a<x.a);}
    bool operator>(mint x)const{return (this->a>x.a);}
};
mint operator*(int &x,mint &y){return y*x;}
istream&operator>>(istream&stream,mint&y){int x;stream>>x;y=x;return stream;}
ostream&operator<<(ostream&stream,mint y){return stream<<y.a;}
vector<mint>fact(1,1),invf(1,1);
mint ncr(int n,int k){
    if(n<0||k<0||n<k) return 0;
    int x=(int)(fact.size());
    while(x<=n){
        mint f=fact[x-1]*x;
        fact.push_back(f);
        invf.push_back(f.inv());
        x++;
    }
    return fact[n]*invf[k]*invf[n-k];
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int>dp(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-v[j]>=0) dp[i]+=dp[i-v[j]];
            dp[i]%=mod;
        }
    }
    cout<<dp[x];
    return 0;
}