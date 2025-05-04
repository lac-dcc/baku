/* By Lakshit Somani */
// clang-format off
// #pragma GCC optimize("Ofast")
// #pragma GCC target("fma")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef unsigned long long ull;
typedef long long       ll;
typedef long double     lld;
#define mod             1000000007
#define inf             1000000000000000001
#define endl            "\n"
#define vi              vector<int>
#define vs              vector<string>
#define vll             vector<ll>
#define vvi             vector<vi>
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vpii            vector<pii>
#define ump             unordered_map
#define mp              map
#define eb              emplace_back
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff              first
#define ss              second
#define bit(n)          (1<<(n))
#define bit64(n)        ((LL(1))<<(n))
#define fill(ar,val)    memset((ar),(val),sizeof (ar))
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)
#define loopt(t,i,a,b)  for((t) i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
#define pray(arr,a,b)   for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define fio             ios_base::sync_with_stdio(false);cin.tie(nullptr)
ll expo(ll a,ll b,ll c){ll res=1;while(b>0){if(b&1)res=(res*a)%c;a=(a*a)%c;b=b>>1;}return res;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
// clang-format on
 
int main(int argc, char const *argv[])
{
    fio;
 
    string a, b;
    cin >> a >> b;
    int m = a.length();
    int n = b.length();
 
    int dp[m+1][n+1];
    loop(i, 0, m)
    {
        loop(j, 0, n)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
        }
    }
    cout << dp[m][n];
 
    return 0;
}
