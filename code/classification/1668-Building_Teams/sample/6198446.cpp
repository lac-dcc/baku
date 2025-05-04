#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const ll INF = 1e18;
char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
ll power(ll x,ll y){
    ll ans = 1;
    while(y>0){
        if(y%2==1){
            ans = (ans*x)%mod;
        }
        x = (x*x)%mod;
        y/=2;
    }
    return ans;
}
ll gcd(ll a,ll b){
    if((a==0) || (b==0)){
        return a+b;
    }
    if(a<b){
        return gcd(a,b%a);
    }
    return gcd(b,a%b);
}
vector<vector<ll>> g(100010);
bool visited[100010],val[100010];
bool possible;
void dfs(ll x,bool yes){
    visited[x] = true;
    val[x] = yes;
    for(auto &y:g[x]){
        if(possible){
            return;
        }
        if(visited[y]){
            if(val[x]&val[y]){
                possible = true;
                break;
            }
        }
        else{
            dfs(y,!yes);
        }
    }
    if(possible){
        return;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(ll i=1;i<=n;i++){
        if(possible){
            break;
        }
        if(!visited[i]){
            dfs(i,true);
        }
    }
    if(possible){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for(ll i=1;i<=n;i++){
        if(val[i]){
            cout<<"1 ";
        }
        else{
            cout<<"2 ";
        }
    }
    cout<<"\n";
    return 0;
}
