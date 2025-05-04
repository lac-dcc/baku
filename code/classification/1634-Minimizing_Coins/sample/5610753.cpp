//oamh namoh bhagwate vaudevaye namah//
 
#include <bits/stdc++.h>
#include <string>
#include <sstream>
 
using namespace std;
 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1e9
 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
 
const long long MAXAI = 1000000000000ll;
 
ll power(int a , int b)
{
    if (b==0) return 1;
    else return (a*power(a , b-1));
}
 
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
 
int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
 
        if (j == M)
            return i;
    }
 
    return -1;
}
 
ll func(vector<ll> &arr,int n){
  ll p=1;
  for(int i=0;i<arr.size();i++){
    p*=arr[0];
  }
  return n/p;
}
ll call(int n){
  vector<ll> arr;
  for(int i=2;i<=(int)(sqrt(n));i++){
    if(n%i==0){
      ll x=func(arr,i);
 
      arr.push_back(x);
    }
  }
  return func(arr,n);
}
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("error.txt" , "w" , stderr);
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int tc=1;
    // SieveOfEratosthenes();
    // cin >> tc;
    for (int t = 1; t <= tc; t++){
      ll n;ll x;
      cin>>n;cin>>x;
      // cout<<n<<endl;
      vector<int> a(n,0);
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
      sort(a.begin(),a.end());
      vector<int> dp(x+1,INF);
      dp[0]=0;
      for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
          if(i-a[j]<0){
            break;
          }
          dp[i]=min(dp[i-a[j]]+1,dp[i]);
        }
      }
      // for(int i=0;i<=x;i++){
      //   cout<<dp[i]<<" ";
      // }
      // cout<<endl;
      if(dp[x]==INF){
        cout<<-1<<endl;
      }
      else{
        cout<<dp[x]<<endl;
      }
    }
    return 0;
}