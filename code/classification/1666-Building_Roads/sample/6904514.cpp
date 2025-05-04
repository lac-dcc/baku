#include <bits/stdc++.h>
 
using namespace std;
using i64 = long long;
using ld = long double;
 
#define F first
#define S second
 
const int N = 1e5 + 5;
 
 
vector < int > g[N];
int color[N];
 
 
void dfs(int from){
        color[from] = 1;
        for(int to : g[from]){
                if(color[to] == 0)
                        dfs(to);
        }
        color[from] = 2;
}
 
 
 
 
 
 
 
 
 
 
vector < pair < int , int > > edge_list;
 
int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        while(m--){
                int i , j;
                cin >> i >> j;
                g[i].push_back(j);
                g[j].push_back(i);
        }
        vector < int > ans;
        for(int i = 1 ; i <= n ; ++i){
                if(color[i] == 0){
                        ans.push_back(i);
                        dfs(i);
                }
        }
        cout << (int) ans.size() - 1 << '\n';
        for(int i = 0 ; i + 1 < ans.size() ; ++i){
                cout << ans[i] << ' ' << ans[i + 1] << '\n';
        }
        return 0;
}
