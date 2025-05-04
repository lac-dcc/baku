/**
  * Author           : Omar Elgammal
  * File Created on  : 3/Oct/2023
  * University       : Cairo University - FCAI
  * LinkedIn         : https://linkedin.com/in/omarelgammal1
  * GitHub           : https://github.com/OmarElgammal1
**/
 
#include <bits/stdc++.h>
 
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ones_in_binary(x) __builtin_popcount(x)
#define yes "YES\n"
#define no "NO\n"
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define cint(x); int x;cin>>x;
#define F first
#define S second
#define PB push_back
//#define fr(i,a,b) for (int i = a; i < b; i++)
#define fr(x) for(int i = 0; i < x; i++)
#define frj(x) for(int j = 0; j < x; j++)
#define sortFirst(myVector); sort(myVector.begin(), myVector.end(), [](const auto& a, const auto& b) {return a.first < b.first;});
#define sortSecond(myVector); sort(myVector.begin(), myVector.end(), [](const auto& a, const auto& b) {return a.second < b.second;});
#define clr(v, x); memset(v, x, sizeof v);
using namespace std;
typedef long long ll;
//typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pi;
 
//void files1(){freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);}
//void files2(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
 
#define calendar map<int, int> months{{1, 31}, {2, 28}, {3, 31}, {4, 30} , {5, 31}, {6, 30}, {7, 31} , {8, 31}, {9, 30}, {10, 31} , {11, 30}, {12, 31}};
const ll mod = 1000000007;
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
 
ll mult(ll a, ll b){
    return (a%mod * b%mod)%mod;
}
 
ll add(ll a, ll b){
    return (a%mod + b%mod)%mod;
}
ll subtract(ll a, ll b){
    return (a%mod - b%mod + 2*mod)%mod;
}
 
ll invMod(ll x, ll y){return (x % y + y) % y;}
 
int knightX[] = {-2, -2, 2, 2, 1, 1, -1, -1};
int knightY[] = {-1, 1, -1, 1, -2, 2, -2, 2};
 
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
 
const int N = 2000;
int m, n;
 
vector<vint> adj;
vector<bool> visited;
vint path;
void bfs(){
    vint prev(n + 1);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i : adj[x]){
            if(!visited[i]){
                prev[i] = x;
                visited[i] = true;
                q.push(i);
            }
        }
    }
    for(int i = n; i != 0; i = prev[i]){
        path.push_back(i);
    }
    if(path[path.size() - 1] != 1){
        cout << "IMPOSSIBLE";
        return;
    }
    cout << path.size() << endl;
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }
}
 
void solve(){
    int x, y;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    fr(m){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs();
}
 
int main() {
    fio
    ll t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
