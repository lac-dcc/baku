#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define INT int32_t
#define int ll
#define vct vector
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sum(v) accumulate(all(v), 0LL)
#define pb push_back
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define umap unordered_map
#define F first
#define S second
#define ln "\n"
#define f(i, a, b)  for(int i = a; i < b; i++)
#define sz(x) (int)(x).size()
#define yes cout<<"YES"<<ln
#define no cout<<"NO"<<ln
#define precision(num,after) fixed<<setprecision(after)<<num
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define PI 3.141592653589793238462643383279502884197
const ld EPS = 1e-8;
vct<bool>primes;
vct<int>facts;
bool prime(int num)
{
    if (num <= 1) return false;
    int ch = 2;
    while (ch * ch <= num)
    {
        if (!(num % ch)) return false;
        ch++;
    }
    return true;
}
vct<int>prm;
void sieve(int N)
{
    primes = vct<bool>(N + 1, 1);
    for (int p = 2; p * p < N; p++)
        if (primes[p])
            for (int i = p * 2; i < N; i += p)
                primes[i] = 0;
    for(int i =2; i<N; i++) if(primes[i]) prm.push_back(i);
}
vct<int>bs;
int bsfindfirst(int start,int en,int val)
{
    while(start<en)
    {
        int mid= start+(en-start)/2;
        if(bs[mid]<val)
        {
            start=mid+1;
        }
        else if(bs[mid]>val)
        {
            en=mid-1;
        }
        else
        {
            en=mid;
        }
    }
    return start;
}
int bsfindlast(int start,int en,int val)
{
    while(start<en)
    {
        // int mid= start+(en-start+1)/2;
        int mid= start+(en-start)/2;
        if(bs[mid]<val)
        {
            start=mid+1;
        }
        else if(bs[mid]>val)
        {
            en=mid-1;
        }
        else
        {
            start=mid;
        }
    }
    return start;
}
ld bsdouble(ld start,ld en,ld val)
{
    while(fabs(en-start)>EPS)
    {
        ld mid= start+(en-start)/2;
        if(bs[mid]<val)
            start=mid;
        else
            en=mid;
    }
    return start;
}
const int mod = 1e9 + 7;
int countOdd(int L, int R)
{
    int N = (R - L) / 2;
    if (R % 2 || L % 2)
        N += 1;
    return N;
}
int countDivisibles(int A, int B, int M)
{
    if (A % M == 0)
        return (B / M) - (A / M) + 1;
    return (B / M) - (A / M);
}
bool isPalindrome(string S)
{
    string P = S;
    reverse(P.begin(), P.end());
    if (S == P)
    {
        return true;
    }
    else
    {
        return false;
    }
}
vct<int>spf;
void factor(int n)
{
    spf.resize(n+1);
    spf[1] = 1;
    for (int i=2; i<n; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<n ; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<n; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<n; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
vct<int> factors(int x)
{
    vct<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
int fact(int n)
{
    if (n == 0) return 1;
    return n * fact(n - 1);
}
int nPr(int n, int r)
{
    int val = 1;
    for (int i = n - r + 1; i <= n; i++) val *= i;
    return val;
}
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
int biPow(int x, int y)
{
    int val = 1;
    while (y)
    {
        if (y % 2)
        {
            val *= x;
            y--;
        }
        else
        {
            x *= x;
            y /= 2;
        }
    }
    return val;
}
int modPow(int x, int y, int m)
{
    int val = 1;
    x %= m;
    while (y)
    {
        if (y % 2)
        {
            val *= x;
            val %= m;
            y--;
        }
        else
        {
            x *= x;
            x %= m;
            y /= 2;
        }
    }
    return val % m;
}
int inv(int val)
{
    return modPow(val, mod - 2, mod) % mod;
}
int invC(int n, int r)
{
    return ((facts[n] * inv(facts[r])) % mod * inv(facts[n - r])) % mod;
}
int countDivisiblesByTwoNumbers(int N, int A, int B)
{
    return ceil((N / lcm(A, B)));
}
int di[8] = { -1,0,1, 0, -1, -1, 1, 1 };
int dj[8] = { 0,1,0,-1, 1, -1, 1, -1 };
//freopen("input.in", "r", stdin);
//freopen("output.out", "w", stdout);
//*******************************************************************
 
map<int,int> visited;
int ans=0;
bool please = true;
void scan(int node,vct<vct<int>>&graph,vct<int>&answer)
{
    visited[node]=1;
    for(auto child:graph[node])
    {
        if(!visited[child])
        {
           if(answer[node]==1)
           {
               answer[child]=2;
           }
           else
            answer[child]=1;
            scan(child,graph,answer);
 
        }
        else if(answer[node]==answer[child])
            please = false;
 
    }
}
 
void solve()
{
 
    int n,m,x,y;
    bool check =false;
    cin>>n>>m;
    vct<vct<int>>v(n+1);
    vct<int>answer(n+1);
    f(i,0,m)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    f(i,1,n+1)
    {
        if(visited[i]==false)
        {
            answer[i]=1;
            scan(i,v,answer);
        }
 
    }
   
    if(!please)
        cout<<"IMPOSSIBLE";
    else
    {
        f(i,1,answer.size())
        {
            if(i==answer.size()-1)
              cout<<answer[i];
            else
            cout<<answer[i]<<" ";
        }
 
    }
 
 
 
}
 
INT main()
{
    fastio;
    int t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
 
    return 0;
}
