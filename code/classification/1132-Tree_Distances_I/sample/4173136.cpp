#define STANDALONE
#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < (int)n; i++) // single incremental for loop starting at 0
#define forsn(i,s,n) for(int i = (int)s; i < (int)n; i++) //single incremental for loop starting at s
#define forstl(a,b) for(auto &a : b) //for loop iterating over STL container b
#define srt(x) std::sort(x.begin(), x.end()); //sorts the container x
#define rev(x) std::reverse(x.begin(), x.end()); //reverses the container x 
#define str std::string //string abbr
#define ll long long int //long long int abbr
#define nll "" //empty string abbr
#define br " " //space abbr
#define nl std::endl //newline abbr 
#define in(a) std::cin >> a;//single input abbr
#define in2(a, b) std::cin >> a >> b;//...
#define in3(a, b, c) std::cin >> a >> b >> c;//...
#define in4(a, b, c, d) std::cin >> a >> b >> c >> d;//...
#define in5(a, b, c, d, e) std::cin >> a >> b >> c >> d >> e;//...
#define in6(a, b, c, d, e, f) std::cin >> a >> b >> c >> d >> e >> f;//...
#define in7(a, b, c, d, e, f, g) std::cin >> a >> b >> c >> d >> e >> f >> g;//...
#define in8(a, b, c, d, e, f, g, h) std::cin >> a >> b >> c >> d >> e >> f >> g >> h;//...
#define stin(s) std::string s;std::cin >> s;//declares a string and inputs it via cin
#define stin2(s, t) std::string s, t;std::cin >> s >> t;//...
#define stin3(s, t, u) std::string s, t, u;std::cin >> s >> t >> u;//...
#define stin4(s, t, u, v) std::string s, t, u, v;std::cin >> s >> t >> u >> v;//...
#define llin(a) ll a = 0;std::cin >> a;//declares and takes in a long long integer
#define llin2(a, b) ll a = 0, b = 0;std::cin >> a >> b;//...
#define llin3(a, b, c) ll a = 0, b = 0, c = 0;std::cin >> a >> b >> c;//...
#define llin4(a, b, c, d) ll a = 0, b = 0, c = 0, d = 0;std::cin >> a >> b >> c >> d;//...
#define din(a) int a = 0;std::cin >> a;//declares and takes in an integer
#define din2(a, b) int a = 0, b = 0; std::cin >> a >> b;//...
#define din3(a, b, c) int a = 0, b = 0, c = 0; std::cin >> a >> b >> c;//..
#define din4(a, b, c, d) int a = 0, b = 0, c = 0, d = 0; std::cin >> a >> b >> c >> d;//...
#define din5(a, b, c, d, e) int a = 0, b = 0, c = 0, d = 0, e = 0; std::cin >> a >> b >> c >> d >> e;//...
#define din6(a, b, c, d, e, f) int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0; std::cin >> a >> b >> c >> d >> e >> f;//...
#define din7(a, b, c, d, e, f, g) int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0; std::cin >> a >> b >> c >> d >> e >> f >> g;//...
#define din8(a, b, c, d, e, f, g, h) int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0; std::cin >> a >> b >> c >> d >> e >> f >> g >> h;//...
#ifdef Debug 
#define dout(a) std::cout <<  a;//set output if debug flag is passed
#define dout2(a, b) std::cout <<  a << br <<  b;//...
#define dout3(a, b, c) std::cout <<  a << br <<  b << br <<  c;//...
#define dout4(a, b, c, d) std::cout <<  a << br <<  b << br <<  c << br <<  d;//...
#define dout5(a, b, c, d, e) std::cout <<  a << br <<  b << br <<  c << br <<  d << br <<  e;//...
#define dout6(a, b, c, d, e, f) std::cout <<  a << br <<  b << br <<  c << br <<  d << br <<  e << br <<  f;//...
#define dout7(a, b, c, d, e, f, g) std::cout <<  a << br <<  b << br <<  c << br <<  d << br <<  e << br <<  f << br <<  g;//...
#define dout8(a, b, c, d, e, f, g, h) std::cout <<  a << br <<  b << br <<  c << br <<  d << br <<  e << br <<  f << br <<  g << br <<  h;//...
#define douts(a) dout2(a,nll)//...
#define doutn(a) std::cout << a << nl;//...
#endif
#ifndef Debug
#define dout(a)//If Debug flag not passed
#define dout2(a, b)//...
#define dout3(a, b, c)//...
#define dout4(a, b, c, d)//...
#define dout5(a, b, c, d, e)//...
#define dout6(a, b, c, d, e, f)//...
#define dout7(a, b, c, d, e, f, g)//...
#define dout8(a, b, c, d, e, f, g, h)//...
#define douts(a)//...
#define doutn(a)//...
#endif
#define out(a) std::cout << a;//set output
#define out2(a, b) std::cout <<  a << br <<  b;//...
#define out3(a, b, c) std::cout <<  a << br <<  b << br <<  c;//...
#define out4(a, b, c, d) std::cout <<  a << br <<  b << br <<  c << br <<  d;//...
#define out5(a, b, c, d, e) std::cout <<  a << br <<  b << br <<  c << br <<  d << br <<  e;//...
#define out6(a, b, c, d, e, f) std::cout <<  a << br <<  b << br <<  c << br <<  d << br <<  e << br <<  f;//...
#define out7(a, b, c, d, e, f, g) std::cout <<  a << br <<  b << br <<  c << br <<  d << br <<  e << br <<  f << br <<  g;//...
#define out8(a, b, c, d, e, f, g, h) std::cout <<  a << br <<  b << br <<  c << br <<  d << br <<  e << br <<  f << br <<  g << br <<  h;//...
#define outs(a) out2(a,nll)//...
#define outn(a) std::cout << a << nl;//...
#define pii std::pair<int, int>
#define pll std::pair<ll, ll>
#define mll std::map<ll,ll>
#define msi std::map<str, int>
#define mis std::map<int, str>
#define mss std::map<str, str>
#define mii std::map<int, int>
#define mci std::map<char, int>
#define si std::set<int>
#define sll std::set<ll>
#define ss std::set<str>
#define sb std::set<bool>
#define sc std::set<char>
#define vi std::vector<int>
#define vll std::vector<long long int>
#define vb std::vector<bool>
#define vs std::vector<str>
#define vpii std::vector<pii>
#define vvi std::vector<vector<int> >
#define vvll std::vector<vector<ll> >
#define PI 2 * acos(0.0)
#define mod 1e9+7
#define fastio std::cin.tie(0);std::ios_base::sync_with_stdio(false);
 
 
template<typename T> inline void incontainer(std::vector<T> &v) {for(size_t i = 0; i < v.size(); i++){in(v[i]);}}
template<typename T> inline void outcontainer(std::vector<T> &v) {for(size_t i = 0; i < v.size(); i++){outs(v[i]);}out(nl);}
template<typename T> inline void inmatrix(std::vector<std::vector<T> > & v) {for(size_t i = 0; i < v.size(); i++){for(size_t j = 0; j < v[i].size(); j++){in(v[i][j])}}}
template<typename T> inline void outmatrix(std::vector<std::vector<T> > & v) {for(size_t i = 0; i < v.size(); i++){outcontainer(v[i]); }}
inline vs split(char c, str s){vs v;str temp = "";forn(i,s.size()){if(s[i] == c){if(temp != ""){v.push_back(temp);temp = "";}}else{temp = temp + s[i];}}if(temp != ""){v.push_back(temp);}return v;}
template<typename T> inline bool isodd(T x) {return ((x % 2) == 1);}
inline bool findchar(char c, str s) {return (s.find(c) != str::npos);}
inline int stringdiff(const str &a, const str &b) {int cnt = 0;forn(i,min(a.size(),b.size())){if(a[i] != b[i]){cnt++;}}return cnt;}
/*****
void fastin (int &x) 
{
  bool neg = false;
  int c = 0;
  x = 0;
  c = getchar();
  while(c != '-' && !(c > 47 && c < 58))
  {
    c = getchar();
  }
  if(c == '-')
  {
    neg = true;
    c = getchar();
  }
  for(;(c > 47 && c < 58); c = getchar())
  {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if(neg)
  {
    x *= -1;
  }
}
bool isPrime(int n)
{
    if (n <= 1)
    {
      return false;
    }
    if (n <= 3)
    {
      return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
      return false;
    }
    for (int i = 5; i * i <= n; i = i + 6)
    {
      if (n % i == 0 || n % (i + 2) == 0)
      {
        return false;
      }
    }
    return true;
}
ll binexpp(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while(b > 0)
    {
        if(b & 1)
        {
            res = res * a % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
ll binexp(ll a, ll b, ll m)
{
    if(isPrime(m))
    {
        return binexpp(a, (b % (m-1)), m);
    }
    return binexpp(a, b, m);
}
#define fibval 1000001
vll fib(fibval);
void fibonacci()
{
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < fibval; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
}
*****/
void solver(int node, int par, int md, vvi &adj_list, vector<pair<pii, pii> > &path, vi &ans){
  if(path[node].first.first < md){
    ans[node] = md;
  }
  else{
    ans[node] = path[node].first.first;
  }
  for(auto it : adj_list[node]){
    if(it == par){
      continue;
    }
    else if(it == path[node].first.second){
      solver(it, node, max(md+1, path[node].second.first + 1), adj_list, path, ans);
    }
    else{
      solver(it, node, max(md+1, path[node].first.first + 1), adj_list, path, ans);
    }
  }
  return;
}
int max_depth(int node, int par, vvi &adj_list, vector<pair<pii, pii>> &path){
  vpii d;
  for(auto it : adj_list[node]){
    if(it == par){
      continue;
    }
    d.push_back(make_pair((1 + max_depth(it, node, adj_list, path)), it));
  }
  srt(d);
  rev(d);
  if(d.empty()){
    path[node] = make_pair(make_pair(0,0), make_pair(0, 0));
    return 0;
  }
  else if(d.size() == 1){
    path[node] = make_pair(d[0], make_pair(0, 0));
    return d[0].first;
  }
  else{
    path[node] = make_pair(d[0], d[1]);
    return d[0].first;
  }
  return -1;
}
#ifdef STANDALONE
int main()
{
  fastio;
  int T = 1;
  //std::cin >> T;
  while(T--)
  {
    din(n);
    vvi adj_list(n+1);
    forn(i, n){
      din2(a, b);
      adj_list[a].push_back(b);
      adj_list[b].push_back(a);
    }
    vector<pair<pii, pii>> path(n+1);
    vi ans(n+1);
    max_depth(1, 0, adj_list, path);
    solver(1, 0, 0, adj_list, path, ans);
    // for(int i = 1; i <n+1; i++){
    //   cout << i << " " << endl << " " << path[i].first.first << " " << path[i].first.second << endl << " " << path[i].second.first << " " << path[i].second.second << endl << endl; 
    // }
    forsn(i,1,n+1){
      outs(ans[i]);
    }
    out(nl);
  }
}
#endif
