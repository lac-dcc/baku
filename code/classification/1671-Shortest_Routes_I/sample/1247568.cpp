#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define sz sizeof
#define inf 3000000000000000007ll
#define pii pair<int,int>
template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }
vector<ll> dijkstra(vector<pii> G[], int v, int n) {
    vector<ll> ans(n, inf);
    ans[v] = 0;
    auto cmp = [&](int i, int j) { return ans[i] > ans[j]; };
    priority_queue<int, vector<int>, decltype(cmp)> que(cmp);
    vector<bool> flag(n);
    que.push(v);
    while (!que.empty()) {
        auto f = que.top();
        que.pop();
        if (flag[f]) continue;
        flag[f] = true;
        for (auto i : G[f])
            if (chmin(ans[i.f], ans[f] + i.s)) {
                que.push(i.f);
                flag[i.f] = false;
            }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int i,n,m,w,x,y;
    cin>>n>>m;
    vector<pii> G[n];
    for(i=0;i<m;++i){
        cin>>x>>y>>w;
        G[x-1].push_back({y-1,w});
    }
    auto ans = dijkstra(G, 0, n);
    for(int i=0;i<n;++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}