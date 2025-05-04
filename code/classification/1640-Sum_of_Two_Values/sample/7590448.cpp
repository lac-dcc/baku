#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=a ; i<b ; i++)
#define rep(i,n) FOR(i,0,n)
#define outl(n) printf("%lld\n",n)
#define out(n) printf("%lld ",n)
#define outintl(n) printf("%d\n",n)
#define outint(n) printf("%d ",n)
#define in(n) scanf("%lld",&n)      // llegers
#define in_int(n) scanf("%d",&n)    // integers
#define in_str(n) scanf("%s",n)     // char array
#define ll long long int 
 
const ll P = 1e9+7;
 
using namespace std;
 
bool comparefunc(pair<ll, ll>& p1, pair<ll, ll>& p2){
    if(p1.second != p2.second) return p1.second < p2.second;
    return p1.first < p2.first;
}
 
void solve(){
    ll n, x;
    in(n);
    in(x);
 
    vector<ll> vl(n);
    map<int, vector<int>> mp;
 
    rep(i, n){
        in(vl[i]);
        mp[vl[i]].push_back(i+1);
    }
 
    int a = -1, b;
    rep(i, n){
        if((vl[i] != x-vl[i]) && mp[x-vl[i]].size() > 0){
            a = i+1;
            b = mp[x-vl[i]][0];
            break;
        }
        else if(mp[x-vl[i]].size() > 1){
            a = i+1;
            b = mp[vl[i]][1];
            break;
        }
    }
 
    if(a != -1){
        outint(a);
        outintl(b);
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}
                                                                                                                           
 
int main(){                                                                                                              
 
    #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); //can need to change file . this one for taking input
       freopen("output.txt","w",stdout); // this one for output
    #endif
 
    solve();
 
    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
    #endif
 
    return 0;                                                                                                                                                                      
}
