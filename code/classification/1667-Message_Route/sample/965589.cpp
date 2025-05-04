#include <bits/stdc++.h>  // This will work only for g++ compiler. 
 
 
#define loop(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define floop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)
 
//short hand for usual tokens
#define pb push_back
 
// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
 
// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
 
using namespace std;
 
// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    list<int> G[n+1];
    int a,b;
    loop(i,0,m) {
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    if (n==1) {
        cout<<"1";
        return 0;
    }
    // for (int i=1; i<=n; i++) {
    //     cout<<i<<':';
    //     for (int u:G[i]) cout<<u<<" ";
    //     cout<<endl;
    // }
    //shortest path using bfs
    list<int> cur;
    int dis = 1;
    cur.push_back(1);
    bool visited[n+1];
    memset(visited,false,sizeof visited);
    int prev[n+1];
    prev[1] = 1;
    visited[1] = true;
    bool find=false;
    while(!cur.empty()) {
        dis++;
        list<int> temp;
        for (int u:cur) {
            for (int p:G[u]) {
                if (visited[p]) continue;
                prev[p] = u;
                visited[p] = true;
                // cout<<"Pushing ";
                // cout<<p<<'\n';
                temp.push_back(p);
                if (p==n) {
                    find = true;
                    break;
                }
            }
            if (find) break;
        }
        swap(cur,temp);
        // cout<<"cur: ";
        // tr(cur,it) {
        //     cout<<*it<<" ";
        // }
        cout<<'\n';
    }
    if (!find) {
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    int cr = n;
    list<int> ans;
    while(cr!=1) {
        ans.pb(cr);
        cr = prev[cr];
    }
    ans.pb(1);
    cout<<ans.size()<<"\n";
    for (auto itr=ans.rbegin(); itr!=ans.rend(); itr++) {
        cout<<*itr<<" ";
    }
    return 0;
}
