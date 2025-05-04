#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int,int>;
using pi3 = pair<int,pii>;
 
#define ON(n , k) ( (n) | ( 1 << (k) ))
#define OFF(n ,k) ( (n) & ( ~( 1 << (k))))
#define ISON(n ,k) ( ( (n)>>(k) ) & (1) )
#define F first
#define S second
 
 
 
const int N = 2e5+5;
const int mod = 1e9+7;
const int INF = 1e9+9;
const double PI = 3.1415926536;
int dx[10] = {0,  0, 1, -1, 1,  1, -1, -1, 0};
int dy[10] = {1, -1, 0,  0, 1, -1,  1, -1, 0};
 
 
 
int n, k;
vector<pii>v;
int ans;
set<pii>s;
 
bool cmp(pii a, pii b)
{
    return a.S < b.S;
}
 
void solve()
{
 
    scanf("%d%d", &n, &k);
 
    for(int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
 
        v.push_back({l, r});
    }
 
    sort(v.begin(), v.end(), cmp);
 
    for(int i = 0; i < n; i++)
    {
        if(s.size() == 0)
        {
            s.insert({-v[i].S, i});
            ans++;
        }
        else
        {
            auto idx = s.lower_bound({-v[i].F, -1});
            if(idx == s.end() && s.size() != k)
            {
                s.insert({-v[i].S, i});
                ans++;
            }
            else if(idx != s.end())
            {
                s.erase(idx);
                s.insert({-v[i].S, i});
                ans++;
            }
        }
    }
 
    printf("%d\n", ans);
 
 
}
 
int main()
{
 
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
 
    /*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    */
    int T;
    T = 1 ;
    //scanf("%d" , &T);
 
    while(T--)
    {
        // init();
        solve();
    }
 
    return 0;
}
 
 
