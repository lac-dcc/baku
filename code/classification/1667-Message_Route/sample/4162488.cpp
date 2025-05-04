#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
 
using namespace std ;
 
const int N = 1e5+5 ;
int ans[N] ;
vector <int> g[N] ;
queue <pair<int,int>> q ;
 
signed main ()
{
    fastio ;
    int n , m , x , y ;
    cin >> n >> m ;
    while ( m-- )
    {
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }
    q.push({1,0}) ;
    ans[1] = 0 ;
    while ( !q.empty() )
    {
        int x = q.front().first ;
        int y = q.front().second ;
        q.pop() ;
        for ( auto it : g[x] )
        {
            if ( it != y && !ans[it] )
            {
                ans[it] = x ;
                q.push({it,x}) ;
            }
        }
    }
    if ( !ans[n] ) cout << "IMPOSSIBLE" ;
    else
    {
        vector <int> v ;
        for ( int i = n ; i != 0 ; i = ans[i] )
            v.push_back(i) ;
        n = v.size() ;
        cout << n << "\n" ;
        for ( int i = n-1 ; i >= 0 ; i-- )
            cout << v[i] << " " ;
    }
    return 0 ;
}
