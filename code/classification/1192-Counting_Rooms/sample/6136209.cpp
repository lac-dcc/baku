#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <set>
#include <string>
#include <cctype>
#include <numeric>
#include <string>
#include <climits>
#include <bitset>
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " ";  _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
#define ll long long int
#define vint vector<int>
#define vlong vector<ll>
#define mod1 1000000007
#define mod2  998244353
#define pi 3.141592653589793238462643
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define all(x)  x.begin(), x.end()
#define input1(v,n) for(int i = 0;i < n;i++){int ___; cin >> ___;v.push_back(___);}
#define input2(v,n) for(long i = 0;i < n;i++){long ___; cin >> ___;v.push_back(___);}
#define printArr(arr,n) for (auto i = 0;i < n;i++){ cout << arr[i] << " ";} cout << endl;
#define vsort(vc) sort(all(vc))
#define vrsort(vc) sort(vc.rbegin(),vc.rend())
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define getSet(x) __builtin_popcountll(x)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); 
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
ll power(ll x,ll y,ll m){
    if (y == 0)
        return 1;
    ll temp = power(x,y/2,m);
    if (y & 1)
        return (x*(temp*temp)%m)%m;
    else    
        return (temp*temp)%m;
} 
 
ll modInverse(ll A, ll M){
    ll m0 = M;
    ll y = 0, x = 1;
    if (M == 1)
        return 0;
    while (A > 1) {
        ll q = A / M;
        ll t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
 
void primeFactors(ll n,map<ll,ll> &m){
    while (n%2 == 0){
        m[2]++;
        n /= 2;
    }
    for (ll i = 3;i <= sqrt(n);i+=2){
        while (n%i == 0){
            m[i]++;
            n= n/i;
        }
    }
    if (n > 2)
        m[n]++;
}
 
ll factorial(ll n){
    if (n == 1 || n == 0)
        return 1;
    return (n*factorial(n-1))%mod1;
}
 
ll bs_sqrt(ll x) {
  ll left = 0, right = 2000000123;
  while (right > left) {
      ll mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}
 
bool cmp(pair<string,int> p1,pair<string,int> p2){
    if (p1.ss != p2.ss)
        return p1.ss > p2.ss;
    return p1.ff < p2.ff;
}
 
bool isPrime(int n){
    if (n % 2 == 0)
        return false;
    for (int i = 3;i*i <= n;i+=2){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}
 
int smallestPrime(int n){
    if (n%2 == 0)
        return 2;
    for (int i = 3;i*i <= n;i+=2){
        if (n%i == 0){
            return i;
        }
    }
    return n;
}
 
//set in decreasing order
/*
auto cmp = [](pii const &x, pii const &y) {
            return x > y;
};
set<pii, decltype(cmp)> v(cmp);
*/
 
//-------------------------------------------------------------------------------------------------
 
ll setBit(ll n){
    ll count = 0;
    while (n!= 0){
        if (n&1){
            count++;
        }
        n = n>> 1;
    }
    return count;
}
 
ll highestBit(ll n){
    int count = 0;
    while (n != 0){
        count++;
        n = n>> 1;
    }
    return count;
}
//---------------------------------------------------------------------------------------------------------
 
bool isValid(int x,int y,int n,int m,vector<string> &v){
    if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '.')
        return true;
    return false;
}
 
void dfs(vector<string> &v,int i,int j,int n,int m){
    v[i][j] = '#';
    if (isValid(i+1,j,n,m,v)) dfs(v,i+1,j,n,m);
    if (isValid(i-1,j,n,m,v)) dfs(v,i-1,j,n,m);
    if (isValid(i,j+1,n,m,v)) dfs(v,i,j+1,n,m);
    if (isValid(i,j-1,n,m,v)) dfs(v,i,j-1,n,m);
}
 
void solve(){
    int n,m; cin >> n >> m;
    vector<string> v;
    loop(i,0,n-1){
        string temp; cin >> temp;
        v.pb(temp);
    }
 
    int ans = 0;
    loop(i,0,n-1){
        loop(j,0,m-1){
            if (v[i][j] == '#')
                continue;
            else{
                ans++;
                dfs(v,i,j,n,m);
            }
        }
    }
 
    cout << ans << endl;
}
 
//-------------------------------------------------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt","w",stderr);
#endif   
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}
