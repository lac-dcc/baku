#include <bits/stdc++.h>
 
using namespace std;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ld long double
#define vi vector<ll>
#define vii vector<vi>
#define pb push_back
#define pii pair<ll,ll>
#define fr(i,n) for(int i=0;i<n;i++)
#define fr1(i,n) for(int i=1;i<=n;i++)
#define posmod(v,m) ((v%m)+m)%m
#define all(v) (v.begin(),v.end())
#define ELROSHDY ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
const ll mod = 1e9 + 7;
const int N = 1e6 + 7;
 
 
 
bool hope = false;
int xr[] = { -1,1,0,0,1,1,-1,-1 };
int yr[] = { 0,0,1,-1 ,1,-1,-1,1 };
//int xr[] = { 2,1,-2,2,-2,-1,1,-1 };
//int yr[] = { 1,2,1,-1 ,-1,-2,-2,2 };
const int inf = 1e9;
 
bool valid(int nx, int ny, int n, int m)
{
    return (nx >= 1 && nx <= n && ny >= 1 && ny <= m);
}
 
bool isprime(int num)// 
{
    if ((!(num & 1) && num != 2) || num == 1 || num == 0)
        return false;
    for (int i = 3; i <= num / i; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
int flipbit(int num, int ind)
{
    return num ^ (1 << ind);
}
int getbit(int index, int num)
{
    return ((num >> index) & 1);
}
int makebit1(int num, int index)
{
 
    return (num | (1 << index));
}
ll power(ll a, ll b, ll minu)  /// binary exponentiation  logb
{
 
    ll mod2 = mod - minu;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod2;
        a = (a * a) % mod2;
        b >>= 1;
    }
    return ans;
}
void modifiedsieve(int n, vector<int>& v)//knows primes in a range and least prime factor of each non prime number--- nloglogn
{
    iota(v.begin(), v.end(), 0);// fr(i,n)v[i]=i;
    v[0] = v[1] = -1;
    for (int i = 2; i <= n / i; i++)
    {
        if (v[i] == i)
        {
            v[i] = i;
            for (int j = i * i; j <= n; j += i)
            {
                if (v[j] == j)
                    v[j] = i;
            }
        }
    }
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void factorize3(map<int, int>& sol, int num, vector<int>& sieve)// should be applied after modified sieve function--> logn
{
 
    while (num != 1)
    {
        int cur = sieve[num];
        int cnt = 0;
        while (num % cur == 0)
        {
            cnt++;
            num /= cur;
        }
        sol[cur]++;
 
    }
 
}
void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll nex = 0;
    ll i = 1;
    while (i <= n)
    {
        ll temp = n / i;
        nex = n / temp + 1;
        ll sum1 = (((nex%mod) * ((nex - 1) %mod))%mod*(power(2,mod-2,0)%mod))%mod;
        ll sum2 = (((i %mod)* ((i - 1)%mod))%mod* (power(2, mod-2, 0)%mod))%mod;
        ll temp2 = (sum1 - sum2 + mod) % mod;
        ans = (ans%mod + ((temp2*(temp%mod))%mod))%mod;
        i = nex;
    }
    cout << ans << endl;
}
int main()
{
    //freopen("ideal.in", "r", stdin);
   // freopen("ideal.out", "w", stdout);
    ELROSHDY
        int  t = 1;
 
    //cin >> t;
    while (t--)
        solve();
}
