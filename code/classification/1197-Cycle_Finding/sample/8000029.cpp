/*Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.
When you use the discount coupon for a flight whose price is x, its price becomes \lfloor x/2 \rfloor (it is rounded down to an integer).
Input
The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,\ldots,n. City 1 is Syrjälä, and city n is Metsälä.
After this there are m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. Each flight is unidirectional.
You can assume that it is always possible to get from Syrjälä to Metsälä.
Output
Print one integer: the price of the cheapest route from Syrjälä to Metsälä.
Constraints
 
2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n
1 \le c \le 10^9
https://cses.fi/problemset/task/1195/*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define INF 1000000000000000000ll
#define all(x) x.begin(), x.end()
#define rep(i, x, n) for (int(i) = (x); (i) < (n); (i)++)
#define endl "\n"
#define nl cout << endl
 
//-------------------------------------------------------------------------------
// print helper
int _nested = 0;
template <typename Primitive>
void print(Primitive &&P)
{
    cout << P << " ";
    if (!_nested)
        nl;
}
template <typename Complex>
void print(vector<Complex> &Vector)
{
    _nested = 1;
    for (Complex &C : Vector)
        print(C);
    nl;
    _nested = 0;
}
template <typename Complex, typename... ComplexObjects>
void print(Complex &&C, ComplexObjects &&...list)
{
    _nested = 1;
    print(C);
    _nested = 0;
    print(list...);
}
 
// scan helper
template <typename Primitive>
void scan(Primitive &P) { cin >> P; }
template <typename Complex>
void scan(vector<Complex> &Vector)
{
    for (Complex &C : Vector)
        scan(C);
}
template <typename Complex, typename... ComplexObjects>
void scan(Complex &C, ComplexObjects &...list)
{
    scan(C);
    scan(list...);
}
 
// fill bulk data
template <typename Primitive>
void fill(Primitive Value, Primitive &P) { P = Value; }
template <typename Primitive, typename Complex>
void fill(Primitive Value, vector<Complex> &Vector)
{
    for (Complex &C : Vector)
        fill(Value, C);
}
template <typename Primitive, typename Complex, typename... ComplexObjects>
void fill(Primitive Value, Complex &C, ComplexObjects &...list)
{
    fill(Value, C), fill(Value, list...);
}
//-------------------------------------------------------------------------------
 
const int N = 2502;
int n, m;
vector<int> dis(N, INF), par(N, -1);
vector<vector<int>> edges;
vector<vector<vector<int>>> adj(N);
 
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
 
    for (int node = 1; node <= n; node++)
    {
        fill(INF, dis), fill(-1ll, par);
        dis[node] = 0;
 
        int cnt = 0;
        while (++cnt)
        {
            int flag = 0, changed;
 
            for (auto i : edges)
            {
                if (dis[i[0]] + i[2] < dis[i[1]])
                {
                    flag = 1;
                    dis[i[1]] = dis[i[0]] + i[2];
                    par[i[1]] = i[0], changed = i[1];
 
                    if(cnt==n)break;
                }
            }
            if (!flag)
            {
                break;
            }
 
            if (cnt == n)
            {
                map<int, int> seen;
 
                int temp = changed;
                vector<int> path;
                while (!seen.count(temp))
                {
                    path.push_back(temp);
                    seen[temp]++;
                    temp = par[temp];
                }
 
                path.push_back(temp);
 
                reverse(all(path));
 
                while (path[path.size() - 1] != temp)
                {
                    path.pop_back();
                }
 
                //reverse(all(path));
                print("YES"), print(path), exit(0);
            }
        }
    }
 
    print("NO");
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _t = 1;
    // cin >> _t;
    while (_t--)
        solve();
}
// cin does not move the input cursor to the next line, use cin.ignore() to move it to the next line
