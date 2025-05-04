/**
 *    author:  Pushkar Mujumdar
 *    email:   pushkarm27@gmail.com
 *    github:  github.com/pmujumdar27
**/
 
#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define newline cout<<"\n"
#define deb(x) cout<<#x<<" "<<x<<endl;
 
template<typename... T>
void read(T&... args){
    ((cin>>args), ...);
}
 
template<typename... T>
void write(T... args){
    ((cout<<args<<" "), ...);
}
 
void printarr(vector<int> &v){
    for(int x: v){
        cout<<x<<" ";
    }
    newline;
}
 
template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}
 
vector<pair<int, int> > nbrs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
 
const int MOD = 1e9+7;
const int nax = 1e7+7;
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    ll n,x; read(n,x);
 
    ll c[n];
 
    for(ll i=0; i<n; i++){
        cin>>c[i];
    }
 
    ll dp[x+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
 
    for(ll i=0; i<n; i++){
        for(ll j=c[i]; j<=x; j++){
            dp[j]+=dp[j-c[i]];
            dp[j]%=MOD;
        }
    }
 
    cout<<dp[x]<<endl;
 
    return 0;
}
