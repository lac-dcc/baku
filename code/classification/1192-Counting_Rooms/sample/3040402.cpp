#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define lop(i,a,b,c) for(int i=a;i<b;i+=c)
#define rlop(i,a,b,c) for(int i=a-1;i>=b;i-=c)
#define f(i,n) lop(i,0,n,1)
#define rf(i,n) rlop(i,n,0,1)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define endl "\n"
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#define fastread() ios::sync_with_stdio(false);cin.tie(0)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MAX = 1e7+10;
const int intmax = INT_MAX;
const int intmin = INT_MIN;
 
void _print(int t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(string t) {cerr << t;}
 
template <class T> void _print(vector<T> v) {cerr << "[ "; for(T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set<T> v) {cerr << "[ "; for(T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset<T> v) {cerr << "[ "; for(T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(pair<T,V> p) {cerr << "{"; _print(p.S); cerr << ","; _print(p.F); cerr << "}";}
template <class T, class V> void _print(map<T,V> v) {cerr << "[ "; for(auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
/* ---------------------------------------------------------------------------------- */
 
int a[1000][1000];
int n,m;
void dfs(int i,int j)
{
    a[i][j] = 1;
    if(i>0 && !a[i-1][j]) dfs(i-1,j);
    if(j>0 && !a[i][j-1]) dfs(i,j-1);
    if(i<n-1 && !a[i+1][j]) dfs(i+1,j);
    if(j<m-1 && !a[i][j+1]) dfs(i,j+1);
}
int32_t main()
{
    fastread();
    cin >> n >> m;
    f(i,n) f(j,m)
    {
        char x; cin >> x;
        a[i][j] = (x=='#');
    }
    int cnt = 0;
    f(i,n) f(j,m)
    {
        if(!a[i][j])
        {
            dfs(i,j);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
