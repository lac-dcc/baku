#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<long long int> vll;
typedef set<ll> sll;
typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<pair<ll,ll> > vpll;
 
#define repi(i,s,e) for(ll i=s;i<e;i++)
#define repd(i,e,s) for(ll i=e;i>=s;i--)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nl "\n"
const ll MOD = 998244353;
const int N = 2e5+10;
 
vector<vi> graph(N);
int sub[N];
void dfs(int n){
    for(auto elm: graph[n]){
        dfs(elm);
        sub[n]+=1+sub[elm];
    }
}
 
int main(){
    int n;cin >> n;
    repi(i, 0, n-1){
        int x;
        cin >> x;
        graph[x].pb(i+2);
    }
    dfs(1);
    repi(i, 1, n+1){
        cout << sub[i] << " ";
    }
    return 0;
}
