#include <bits/stdc++.h>
using namespace std;
 
template<typename T1, typename T2>
string to_string(pair<T1, T2> p);
template<typename T1, typename T2, typename T3>
string to_string(tuple<T1, T2, T3> tup);
template<typename T1, typename T2, typename T3, typename T4>
string to_string(tuple<T1, T2, T3, T4> tup);
string to_string(const string& v) {
  return "{" + v + "}";}
string to_string(const char* v) {
  return to_string((string) v);}
string to_string(const bool& v) {
  return (v ? "True" : "False");}
string to_string(vector<bool> v) {
  string ret = "[";
  int n = (int) v.size();
  for (int i = 0; i < n - 1; i++) {
    ret += "[" + to_string(i) + "](" +  to_string(v[i]) + "), ";}
  ret += "[" + to_string(n - 1) + "](" + to_string(v[n - 1]) + ")]";
  return ret;}
template<size_t N>
string to_string(bitset<N> b) {
  string ret = "";
  for (int i = 0; i < N; i++) {
    ret += (char)(b[i] + '0');}
  return ret;}
template<typename T>
string to_string(T v) {
  bool ok = true;
  string ret = "[";
  int cnt = 0;
  for (auto x : v) {
    if (!ok) {
      ret += ", ";}
    ok = false;
    ret += "[" + to_string(cnt++) + "](" + to_string(x) + ")";}
  return ret + "]";}
template<typename T1, typename T2>
string to_string(pair<T1, T2> p) {
  return "{" + to_string(p.first) + ", " + to_string(p.second) + "}";}
template<typename T1, typename T2, typename T3>
string to_string(tuple<T1, T2, T3> tup) {
  return "{" + to_string(get<0>(tup)) + ", " + to_string(get<1>(tup)) + ", " + to_string(get<2>(tup)) + "}";}
template<typename T1, typename T2, typename T3, typename T4>
string to_string(tuple<T1, T2, T3, T4> tup) {
  return "{" + to_string(get<0>(tup)) + ", " + to_string(get<1>(tup)) + ", " + to_string(get<2>(tup)) + ", " + to_string(get<3>(tup)) + "}";}
void DEBUG() { cerr << '\n';}
template<typename start, typename ... end>
void DEBUG(start first, end... other) {
  cerr << " | " << to_string(first);
  DEBUG(other...);}
 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: "; DEBUG(__VA_ARGS__);
#define ll          long long
#define pb          push_back
#define pii         pair<ll, ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define sum(a)      accumulate(all(a),0LL)
#define fi          first
#define se          second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define INF         LLONG_MAX
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define irep(i,a,b) for(ll i=b-1;i>=a;i--)
#define GCD         __gcd
 
vector<vector<int>> adj;
vector<int> visited;
vector<int> parent;
int dfs(int n)
{
  visited[n]=1;
  int temp=0;
  for(auto i:adj[n])
  {
    if(visited[i]==0)
    {
      parent[i]=n;
      temp=dfs(i);
      if(temp)
        return temp;
    }
    else if(visited[i]==1&&i!=parent[n])
    { 
      parent[i]=n;
      return i;
    }
  }
  return 0;
}
void solve()
{
  int n,m;
  cin>>n>>m;
  adj.assign(n+1,{});
  visited.assign(n+1,0);
  parent.assign(n+1,0);
  int a,b;
  while(m--)
  {
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  int temp=0;
  stack<int> s;
  int flag=0;
  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    {
      parent[i]=i;
      temp=dfs(i);
      if(temp)
      {
        flag=1;
        break;
      }
    }
  }
  if(!flag)
  {
    cout<<"IMPOSSIBLE";
    return;
  }
  int temp2=temp;
  while(temp2!=parent[temp])
  {
    s.push(temp);
    temp=parent[temp];
  }
  s.push(temp);
  cout<<s.size()+1<<endl;
  cout<<temp2<<" ";
  while(s.size())
  {
    cout<<s.top()<<" ";
    s.pop();
  }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
