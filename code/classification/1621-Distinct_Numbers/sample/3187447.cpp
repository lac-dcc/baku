/*CP is fun!
DANGER: always put brackets around 1<<j like.. (1<<j)
binary lifting-> reverse mein
Fenwick tree mein testcase ke andar wali max value size ko add() function mein rakhna (MAX global wali MAT RAKHNA PLEASE!)....hazar baar galti kar chuka hoon bohot annoying hai ! Cmon!!!!
*/
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define ll long long
#pragma GCC optimize("O3") //how good is this? lol
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int MAXN=2e3+5;
const int MAXL=32;
const int MOD=998244353;
const int MAX=2e7+5;
const int MAXA=5e3+5;
const int INF=2e18;
 
int powerm(int a,int b) { //m-> mod
    if(b==0) {
        return 1;
    }
    int curr=a,res=1;
    for(int i=0;i<MAXL;i++) {
        if((1LL<<i)&b) {
            res=(res*curr)%MOD;
        }
        curr=(curr*curr)%MOD;
    }
    return res;
}
 
class facm {
public:
    vector<int>fac,inv;
    int n=0,mod;
    facm(int x,int M) { //precomputes factorials!
        n=x;
        mod=M;
        fac.resize(n+1),inv.resize(n+1); //till fac[n] and inv[n]
        fac[0]=1;
        for(int i=1;i<=n;i++) {
            fac[i]=(fac[i-1]*i)%mod;
        }
    }
    void preinv() { //precomputes inverse! Thanks Aman for that trick! :P
        inv[n]=powerm(fac[n],mod-2);
        for(int i=n-1;i>=0;i--) {
            inv[i]=(inv[i+1]*(i+1))%mod;
        }
    }
    int choose(int a,int b) { //get nCr
        if(a<b || a<0 || b<0) {
            return 0;
        }
        return ((fac[a]*inv[b])%mod*inv[a-b])%mod;
    }
};
 
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<setprecision(9)<<fixed;
    //freopen("closing.in","r",stdin);
    //freopen("closing.out","w",stdout);
    int n,num;
    cin>>n;
    set<int>s;
    for(int i=0;i<n;i++) {
        cin>>num;
        s.insert(num);
    }
    cout<<s.size();
    return 0;
}
 
 
