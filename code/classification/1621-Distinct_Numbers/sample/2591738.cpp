#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef vector<long long int> vi;
typedef vector<vi> vii;
typedef pair<ll, ll> ii;
typedef vector<ii> vpii;
 
#define pi 3.141592653590
#define sz(a) ll((a).size())
#define pb push_back
#define mp make_pair
#define all(C) C.begin(),C.end()
#define fai(i,n) for(ll i=0; i<n; i++)
#define rep(i,a,b) for(ll i=a; i<=b; i++)
#define repl(i,a,b) for(ll i=a; i<=b; i++)
#define fal(i,n) for(ll i=0; i<n; i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
// *it or it->second.first
 
ll getSum(ll n) 
 { 
    ll sum; 
  
    for (sum = 0; n > 0; sum += n % 10, n /= 10); 
  
    return sum; 
 } 
 
void yes(){
    cout<<"YES"<<endl;
}
 
void no(){
    cout<<"NO"<<endl;
}
 
//----------------- check if prime or not ------------------//
 
bool isPrime(ll n) 
{ 
 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
 
//------------------ Sieve Of Eratosthenes-----------------------//
// use: vector<ll> v= SieveOfEratosthenes(num) //
 
vector<ll> SieveOfEratosthenes(ll n)
{   
    vector<ll> primes;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true) 
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (ll p = 2; p <= n; p++)
        if (prime[p])
            primes.pb(p);
 
    return primes;
}
 
//-------------gcd -------------------//
 
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
// ------------- lcm -----------------//
 
ll lcm(ll a, ll b){
  ll G = gcd(a,b);
  ll k = (a*b)/G;
  return k;
}
 
//-----  first term ascending , if same then compare second -------------//
 
bool cmp(pair<ll,ll> &a, pair<ll,ll> &b){
    if(a.second == b.second)
        return a.first>b.first;
    return a.second>b.second;
}
 
//----------- Rounding Up -------------------------//
 
float round_up(float value, int decimal_places) {
    const float multiplier = pow(10.0, decimal_places);
    float v = value * multiplier;
    float u = value * multiplier*10;
    int k = floor(u);
    if(int(floor(v))%2==0){
      if(k%5==0 && k%10!=0){
        return floor(v) / multiplier;
      }
    }
    return ceil(value * multiplier) / multiplier;
}
 
//-------------------check if palindrome-------------------------//
 
bool palindrome(const string &s) {
    int n = s.length();
    for(int i = 0; i < n; i++) {
        if(s[i] != s[n - i - 1]) return false;
    }
    return true;
}
 
//-------------------main--------------------------//
 
bool isSubSequence(string k, string s, int m, int n)
{
    int j = 0; 
    for (int i = 0; i < n && j < m; i++)
        if (k[j] == s[i])
            j++;
 
    return (j == m);
}
 
 
 
int main()
{ 
  
 
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
 
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  
  int n;
  cin>>n;
  set<int> s;
  fai(i,n) {
    int k;
    cin>>k;
    s.insert(k);
  } 
  cout<<s.size()<<endl;
 
  
  return 0;
}
 
 
 
 
 