#include <bits/stdc++.h>
using namespace std;
#define fp(file) freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
#define newl "\n"
#define ms(a,v) memset(a,v,sizeof(a))
#define ar array
#define sz(x) ((int)x.size())
#define r1(a) (a).begin(), (a).end()
#define r2(a,start,end) a + start,a + end + 1
#define PI 3.1415926535897932384626433832795l
#define ft first
#define sd second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int MaxN = 2e5;
const int MaxV = 1e7;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;
 
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(r) shuffle(r, RNG);
 
pair<int,int> a[MaxN + 1];
int n,k;
istream& operator >> (istream &in,pair<int,int> &t)
{
    in >> t.first;
    in >> t.second;
    return in;
}
bool cpm(const pair<int,int> &h,const pair<int,int> &h1)
{
    return (h.second < h1.second || (h.second == h1.second && h.first < h1.first));
}
void rd()
{
    cin >> n >> k;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
}
//int pivot()
//{
//    int mx = a[n].first,piv = n;
//    for(int i = n - 1;i >= 1;--i)
//    {
//        mx = max(mx,a[i].first);
//        if(a[i].second > mx)
//            piv = i;
//    }
//    return piv;
//}
//int solve()
//{
//    queue<int> q;
//    for(int i = 1;i <= k;++i)
//        q.push(0);
//    int ans = 0,limit = pivot();
//    for(int i = 1;i < limit;++i)
//        if(q.front() <= a[i].first)
//            q.pop(),q.push(a[i].second),++ans;
//    sort(a + limit,a + n + 1);
//
//    for(int i = limit;i <= n;++i)
//        if(q.front() <= a[i].first)
//            q.pop(),++ans;
//    return ans;
//}
int solve()
{
    int ans = 0;
    multiset<int> s;
    for(int i = 1;i <= k;++i)
        s.insert(0);
    for(int i = 1;i <= n;++i)
    {
        multiset<int>::iterator it = s.upper_bound(a[i].ft);
        if(it != s.begin())
        {
            --it;
            s.erase(it);
            s.insert(a[i].sd);
            ++ans;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
//    int tc;
//    cin >> tc;
//    for(int i = 1;i <= tc;++i)
//    {
//
//    }
    rd();
    sort(a + 1,a + n + 1,cpm);
    cout << solve();
    return 0;
}