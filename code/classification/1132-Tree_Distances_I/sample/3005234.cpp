#include <bits/stdc++.h>
using namespace std;
 
#define null NULL
#define endl "\n"
#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
#define all(v) v.begin(), v.end()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii > vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vi > vvi;
typedef vector<vll > vvll;
typedef map<int, int> mii;
typedef map<char, int> mci;
template<typename... T>
void inp(T&... args) { ((cin >> args), ...);}
template<typename... T>
void out(T&&... args) { ((cout << args << " "), ...);}
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(ll i = s; i <= e; i++)
#define fr(i, s, e) for(ll i = s; i >= e; i--)
#define logarr(arr, s, e) for(int i = s; i <= e; i++) cout<<arr[i]<<" "; cout<<endl;
#define bitc(n) __builtin_popcount(n)
#define mp make_pair
#define pb push_back
#define sz size()
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define fi first
#define se second
#define INF 2e18
 
vi g[200005];
vi ans(200005, minf);
 
int bfs(int src) {
 
  vi dist(200005, -1);
  dist[src] = 0;
  ans[src] = max(ans[src], dist[src]);
 
  queue<int> q;
  int curr;
 
  q.push(src);
 
  while(not q.empty()) {
    curr = q.front();
    q.pop();
 
    for(int child: g[curr]) {
      if(dist[child] == -1) {
        q.push(child);
        dist[child] = dist[curr]+1;
        ans[child] = max(dist[child], ans[child]);
      }
    }
  } 
 
  return curr;
}
 
int main() {
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
 
  clock_t begin = clock();
 
  int n, a, b;
  inp(n);
 
  f(i, 1, n-1) {
    inp(a, b);
    g[a].pb(b);
    g[b].pb(a);
  }  
 
  int end1 = bfs(1);
  int end2 = bfs(end1);
  bfs(end2);
 
  f(i, 1, n) { 
    cout<<ans[i]<<" ";
  }
 
  cout<<endl;
 
  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif
 
  return 0;
}
