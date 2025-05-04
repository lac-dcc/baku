#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl
 
using namespace std;
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<p(3)> edges;
    vi d(n);
    vi parents(n, -1);
 
    forn(i, m){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--, v2--;
        if(v1 == v2 && w < 0){
            out("YES");
            cout << v1+1 << " " << v1+1;
            return;
        }
        edges.pb({v1, v2, w});
    }
    
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (auto [v1, v2, w] : edges) {
            if (d[v1] + w < d[v2]) {
                d[v2] = d[v1] + w;
                parents[v2] = v1;
                x = v2;
            }
        }
    }
 
    if (x == -1) {
        cout << "NO";
    }
    else {
        for (int i = 0; i < n; ++i) x = parents[x];
 
        vi cycle;
        for (int v = x;; v = parents[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
 
        out("YES");
        for (int v : cycle)
            cout << v+1 << ' ';
        cout << endl;
    }
}
 
int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
 
/*
* When you get WA:
    - Check for integer overflows
    - Bugs
    - Arrays with uninitialized values
*/
