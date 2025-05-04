#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
#define ld long double
using ii = pair<int, int>;
const int mod = 1e9 + 7;
const int inf = 1e9;
int Amod = 998244353;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int diagx[] = {-1, 1, -1, 1};
int diagy[] = {-1, 1, 1, -1};
int ddx[] = {2, 2, 1, 1, -2, -2, -1, -1}; // knight
int ddy[] = {1, -1, 2, -2, 1, -1, 2, -2}; // knight
const long double PI = (acos(-1));
const int N = 1e5 + 10;
using ull = unsigned long long;
 
int n,m;
vector<ii> g[200200];
int dist[200200];
int vis[200200];
 
void solve() {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        a--,b--;
        g[a].push_back({b,w});
    }
    for(int i=0;i<=n;i++)dist[i]=1e18;
    set<ii> st;
    dist[0]=0;
    st.insert({0,0});
    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.S;
        int dis = it.F;
        st.erase(it);
        for(auto i: g[node]){
            int ng = i.F;
            int wt = i.S;
            if(dist[ng] > dis+wt){
                if(dist[ng]!=1e18){
                    st.erase({dist[ng],ng});
                }
                dist[ng] = dis+wt;
                st.insert({dist[ng],ng});
            }
        }
    }
    for(int i=0;i<n;i++)cout<<dist[i]<<" ";
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
