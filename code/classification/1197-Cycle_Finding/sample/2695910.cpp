#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define rep(i, a, n) for (lli i = a; i < n; i++)
#define rrep(i, n, a) for (lli i = n; i >= a; i--)
#define vlli vector<lli>
#define mii map<int, int>
#define umii unordered_map<int, int>
lli mod = 1e9 + 9;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
lli maxd = INT32_MAX;
lli midn = INT32_MIN;
struct edge
{
    int a, b;
    lli w;
};
int n, m;
vector<edge> arr;
lli dis[100001], par[100001];
void bfa()
{
    dis[1] = 0;
    int f = -1;
    rep(j, 0, n)
    {
        rep(i, 0, m)
        {
            int x = arr[i].a, y = arr[i].b;
            lli c = arr[i].w;
            if (dis[y] > dis[x] + c)
            {
                if (j != n - 1)
                {
                    dis[y] = dis[x] + c;
                    par[y] = x;
                }
                else
                {
                    par[y] = x;
                    f = y;
                }
            }
        }
    }
    if (f == -1)
    {
        cout << "NO";
    }
    else
    {
        // cout << f << endl;
        cout << "YES" << endl;
        rep(i, 0, n - 1)
            f = par[f];
        // cout << f << endl;
        vector<int> ans;
        ans.push_back(f);
        int d = par[f];
        while (d != f)
        {
            ans.push_back(d);
            d = par[d];
        }
        ans.push_back(f);
        reverse(ans.begin(), ans.end());
        // cout<<ans.size()<<endl;
        rep(i, 0, ans.size())
                cout
            << ans[i] << " ";
    }
}
int main()
{
    fastio();
    cin >> n >> m;
    rep(i, 1, n + 1)
    {
        dis[i] = 0;
    }
    rep(i, 0, m)
    {
        edge e1;
        cin >> e1.a >> e1.b >> e1.w;
        arr.push_back(e1);
    }
    bfa();
    return 0;
}
