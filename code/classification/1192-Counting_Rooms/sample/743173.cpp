#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define mid(l, h) ((l+h)/2)
#define pb push_back
const int mod = 1e9 + 7, size = 1e6 + 1;
 
bool prime(int n, int a)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p*p <= n; ++p)
    {
        if (prime[p])
        {
            for (int i = p*p; i <= n; i += p) prime[i] = false;
        }
    }
 
    if (prime[a]) return true;
    else return false;
}
 
bool check(int n)
{
    if (n % 2 != 0) return false;
    else return true;
}
 
int sumOfDigits(int n, int sum = 0)
{
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
 
    return sum;
}
 
int n, e;
char ar[1001][1001];
bool vis[1001][1001];
 
bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > e) return false;
 
    if (vis[x][y] || ar[x][y] == '#') return false;
 
    return true;
}
 
void dfs(int x, int y)
{
    vis[x][y] = 1;
 
    if (isValid(x-1, y)) dfs(x-1, y);
    if (isValid(x, y+1)) dfs(x, y+1);
    if (isValid(x+1, y)) dfs(x+1, y);
    if (isValid(x, y-1)) dfs(x, y-1);
}
 
int main()
{
    fast
 
    cin >> n >> e;
 
	for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= e; ++j)
    cin >> ar[i][j];
 
	int cc = 0;
 
    for (int i = 1; i <= n; ++i)
    {
         for (int j = 1; j <= e; ++j)
         {
             if (vis[i][j] == false && ar[i][j] == '.') dfs(i, j), ++cc;
         }
    }
 
    cout << cc;
}
// () ! #
