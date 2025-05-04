#include<bits/stdc++.h>
using namespace std;
 
#define max(a, b)         (a < b ? b : a)
#define min(a, b)         ((a > b) ? b : a)
#define FOR(a, c)         for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c)     for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c)     for (int(a) = (b); (a) >= (c); (a)--)
#define INF             1000000000000000003
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
 
 
 
int32_t main()
{
    w(n) {
        int x, y;
        cin >> x >> y;
        if (x >= y) {
            if (x % 2 == 0)
                cout << x*x - y + 1 << endl;
            else
                cout << (x - 1)*(x - 1) + y << endl;
        }
        else {
            if (y % 2 == 0)
                cout << (y - 1)*(y - 1) + x << endl;
            else
                cout << y*y - x + 1 << endl;
        }
    }
    return 0;
}
