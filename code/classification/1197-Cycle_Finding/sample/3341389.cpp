// #include<bits/stdc++.h>
// #define int long long
 
// using namespace std;
 
// int check(int a[] , int n , int mid)
// {
//   int idx =(n-1)/2;
 
// int sum =0;
// for(int i=0;i<n;i++)
// sum+=a[i];
 
// int meanop = mid*n-sum;
// if(meanop <0)
// return -1;
// int medianop=0;
// for(int i = idx;i<n;i++)
// {
  
//   medianop+=(max(mid-a[i],(long long)0));
// }
 
// if( meanop< medianop)
// return -1;
 
// return meanop;
 
    
// }
// signed main()
// {
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
 
 
// int t;
// cin>>t;
// while(t--)
//   {
//       int n;
//       cin>>n;
//       int a[n];
 
//       int sum =0;
//       for(int i=0;i<n;i++)
//       {
//         cin>>a[i];
      
//       }
//       sort(a,a+n);
 
//       int l = a[(n-1)/2],r=1e9+10;
//       int ans = -1;
      
//       while(l<=r)
//       {
//         int mid = l+(r-l)/2;
//          int x = check(a,n,mid);
//         if(x != -1)
//         {
//           ans = x;
//           r = mid-1;
//         }
//         else
//         l = mid+1;
 
//       }
//       cout<<ans<<endl;
 
//   }
 
 
// }
 
 
//////////////////////////////////// print 
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define range(i, n) for (int i = 0; i < n; i++)
#define range1(i, n) for (int i = 1; i <= n; i++)
#define mod9 1000000009
#define mod7 1000000007
#define INF 1e18
#define sp(y) fixed << setprecision(y)
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define test(x) \
    int x;      \
    cin >> x;   \
    while (x--)
#define ff first
#define ss second
#define pii pair<int, int>
#define mii map<int, int>
#define mp make_pair
#define append push_back
#define pb pop_back
#define fast_io std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define input(x) cin >> (x)
struct triplet
{
    int first;
    int second;
    int third;
};
 
int n, m;
vector<triplet> edges;
vector<int> dist;
vector<int> parent;
 
void bellman_ford()
{
    int x;
    for (int i = 1; i <= n; ++i)
    {
        x = -1;
        for (auto e : edges)
        {
 
            int u = e.first;
            int v = e.second;
            int d = e.third;
            if (dist[u] + d < dist[v])
            {
                dist[v] = d + dist[u];
                parent[v] = u;
                x = v;
            }
        }
    } // n relaxations
    if (x == -1)
        cout << "NO" << endl;
 
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            x = parent[x];
        }
 
        vector<int> cycle;
 
        for (int v = x;; v = parent[v])
        {
            cycle.push_back(v);
            if (v == x and cycle.size() > 1)
                break;
        }
 
        reverse(cycle.begin(), cycle.end());
 
        cout << "YES" << endl;
        for (auto v : cycle)
        {
            cout << v << " ";
        }
 
        cout << endl;
    }
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    dist.resize(n + 1);
    parent.resize(n + 1);
    edges.resize(m);
 
    for (int i = 0; i < m; ++i)
    {
        struct triplet inp;
        cin >> inp.first >> inp.second >> inp.third;
        edges[i] = inp;
    }
 
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = -1;
    }
    bellman_ford();
}
