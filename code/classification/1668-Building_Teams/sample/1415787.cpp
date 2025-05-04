#include <bits/stdc++.h>
using namespace std;
 
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define big __int_128_t
#define v vector
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
#define pb push_back
#define q 1000000007
 
pair<bool, int> ch[100005];
v<int> a[100005];
int c = 0;
 
void dfs(int x, int y)
{
    ch[x] = {true, !y};
    for(auto i : a[x])
        if(!ch[i].F)
        {
            dfs(i, ch[x].S);
        }
        else
        {
            if(ch[x].S == ch[i].S)
            {
                c = 1;
                return;
            }
        }
}
 
int main()
{
    fast
 
    int n, m;
    cin >> n >> m;
 
    for(int i = 0; i < m ; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
 
    dfs(1, 1);
    for(int i = 1; i <= n; i++)
        if(!ch[i].F)
            dfs(i, 1);
 
    if(c)
        cout << "IMPOSSIBLE";
    else
    {
        for(int i = 1; i <= n; i++)
            cout << ch[i].S + 1 << " ";
    }
 
    return 0;
}
