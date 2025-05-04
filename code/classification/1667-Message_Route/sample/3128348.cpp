#include <iostream>
#include <complex>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define REP(n) for (ll _loop = 0; _loop < n; _loop++)
#define RRIP(i,z,n) for(ll i = n-1; i >= z; i--)
#define RIP(i,l,n) for (ll i = l; i < n; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define B begin()
#define E end()
#define ln '\n'
const ll INF64 = 3e18;
const int mod = (int)1e9 + 7;
//const int mod = 998244353;
const int MAX_N = 100000 + 5;
ll binp(ll a, ll b)
{	if (b == 0)
		return 1;
	ll ans = binp(a, b/2);
	ll tmp = (ans * ans);
	if (b % 2)return ((tmp * a));
		return ((tmp));
}
ll mbinp(ll a, ll b)
{
	a %= mod;
	if (b == 0)
		return 1;
	ll ans = mbinp(a, b/2);
	ll tmp = (ans * ans) % mod;
	if (b % 2)
		return ((tmp * a) % mod);
	return ((tmp) % mod);
}
 
void print_bin(int n, int len)
{
    bool start = false;
    int  last_bit  = 0;
    RIP(i, 0, len)
    {
        if (!start)
        {
            cout << ((n & (1 << (len-i-1))) ?  '1' : '0');
            if (((n & (1 << (len-i-1)))))
                start = true;
            last_bit = n & (1 << (len-i-1));
        } else {
            if (!last_bit != !(n & (1 << (len-i-1))))
                cout << '1';
            else
                cout << '0';
 
            last_bit = n & (1 << (len-i-1));
 
        }
        
    }
    cout << endl;
}
 
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector  <vector <int> > graph(n);
 
    RIP(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
 
    const int start = 0;
    int end = n - 1;
 
    vector <int> visited(n, -1);
    queue <int> q;
    q.push(start);
    visited[start] = 0;
    while (!q.empty())
    {
        int que_front = q.front();
        if (que_front == end)
            break ;
        q.pop();
        for (int i = 0; i < graph[que_front].size(); i++)
        {
            if (visited[graph[que_front][i]] == -1)
            {
                visited[graph[que_front][i]] = que_front;
                q.push(graph[que_front][i]);
                    
            }
        }
    }
    if (visited[end] == -1)
        cout << "IMPOSSIBLE" << endl;
    else 
    {
        vector <int> path;
        while (end != start)
        {
            path.push_back(end + 1);
            end = visited[end];
        }
 
        cout << path.size() + 1 << endl;
        cout << "1";
        for (int i = path.size() -1; i >= 0; i--)
            cout << " " << path[i];
        cout << endl;
    }
 
}
