#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int dx[]{0,0,1,-1,-1,-1,1,1};
const int dy[]{1,-1,0,0,-1,1,-1,1};
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define LSB(i) ((i) & (-i))
 
int dcmp(double a, double b){
    if(fabs(a-b) <= EPS) return 0;
    return a < b ? -1 : 1;
}
ll gcd(ll a, ll b)
{
  if(b==0) return a;
  return gcd(b,a%b);
}
 
ll lcm(ll a, ll b)
{
  return (a/gcd(a,b))*b;
}
 
struct edge{
    int x, y, w;
};
 
bool cmp(edge a, edge b){
    return a.w < b.w;
}
 
int binExp(int a, int b, int m){
    a %= m;
    int res =1;
    while(b > 0){
        if(b & 1) res = res * a  % m;
        b>>=1;
        a = a *a %m;
    }
    return res;
}
 
 
char G[1001][1001];
int n, m;
int vst[1001][1001];
 
void dfs(int i, int j){
    vst[i][j] = 1;
    for(int k=  0; k<  4; ++k){
        int nr = i + dx[k], nc = j + dy[k];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && vst[nr][nc] == 0 && G[nr][nc] == '.'){
            dfs(nr, nc);
        }
    }
}
 
 
 
void solve(int testCase){   
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j< m; ++j){
            cin >> G[i][j];
        }
    }
    int ans = 0;
    for(int i = 0;i  < n; ++i){
        for(int j = 0; j < m; ++j){
            if(vst[i][j] == 0 && G[i][j] == '.')
            {
                ++ans;
                dfs(i,j);
            }
        }
    }
    cout << ans << '\n';
 
 
}
    
int main(){
    fastio();
    int t = 1;
   // cin >> t;
    for(int i = 1; i <= t; ++i){
        solve(i);
   }
   return 0;
}
    
