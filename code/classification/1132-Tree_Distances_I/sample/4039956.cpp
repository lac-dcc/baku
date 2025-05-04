#include <iostream>
#include <vector>
 
using namespace std;
using pii = pair<int,int>;
using ppi = pair<pii,pii>;
 
const int MAXN = 2*1e5+1;
 
vector<int>grafinho[MAXN];
int visited[MAXN];
ppi f[MAXN];
int g[MAXN];
 
void F(int x) {
    visited[x] = 1;
    for(int i=0; i<grafinho[x].size(); i++) {
        int y = grafinho[x][i];
        if(!visited[y]) {
            F(y);
            if(f[y].first.first + 1 >= f[x].first.first) {
                f[x].second.first = f[x].first.first;
                f[x].second.second = f[x].first.second;
                f[x].first.first = f[y].first.first+1;
                f[x].first.second = y;
            }
            else if(f[y].first.first + 1 >= f[x].second.first) {
                f[x].second.first = f[y].first.first+1;
                f[x].second.second = y;
            }
        }
    }
    visited[x] = 0;
}
 
void G(int x) {
    visited[x] = 1;
    for(int i=0; i<grafinho[x].size(); i++) {
        int y = grafinho[x][i];
        if(!visited[y]) {
            if(f[x].first.second != y) 
                g[y] = max(g[x]+1,f[x].first.first+1);
            else g[y] = max(g[x]+1,f[x].second.first+1);
            G(y);
        }
    }
    visited[x] = 0;
}
 
int main() {
    int n;
    int x,y;
 
    cin >> n;
 
    for(int i=1; i<n; i++) {
        cin >> x >> y;
        grafinho[x].push_back(y);
        grafinho[y].push_back(x);
    }
 
    F(1);
    G(1);
 
    for(int i=1; i<n; i++) {
        cout << max(f[i].first.first, g[i]) << " ";
    } cout << max(f[n].first.first, g[n]) << endl;
 
    return 0;
}
