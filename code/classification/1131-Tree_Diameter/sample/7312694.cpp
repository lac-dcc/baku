/**
    "If you have an apple and I have an apple and
    we exchange apples then you and I will still
    each have one apple. But if you have an idea
    and I have an idea and we exchange these
    ideas, then each of us will have two ideas."
                        -George Bernard Shaw
*/
#include<bits/stdc++.h>
using namespace std;
 
#define ALL(v) v.begin(),v.end()
#define clean(x,y) memset(x,y,sizeof(x));
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 200005
 
typedef long long ll;
 
vector<int> adj[MAX];
int d = -1, A = -1, B = -1; //length of diameter is d (A--->B)
pair<int,int> diameter(int u = 1, int p = -1) { //dis, node
    int mx1 = 0, mx2 = 0, n1 = u, n2 = u;
    for(int v : adj[u]) {
        if(v == p) continue;
        auto now = diameter(v, u);
        int dis = 1 + now.first;
        int who = now.second;
        if(dis >= mx1) {
            mx2 = mx1; n2 = n1;
            mx1 = dis; n1 = who;
        }
        else if(dis >= mx2) {
            mx2 = dis; n2 = who;
        }
    }
    
    if(d <= (mx1 + mx2)) {
        d = mx1 + mx2;
        A = n1; B = n2;
    }
    return {mx1, n1};
}
 
void solve() {
    int n, x, y;
 
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    diameter();
    cout << d << "\n";
}
 
int32_t main() {
    FAST
 
    // int TC = 1;
 
    //cin>>TC;
 
    // for(int cs = 1; cs <= TC; cs++) {
        //cout << "Case " << cs << ": ";
        solve();
    // }
 
    return 0;
}
