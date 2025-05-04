#include<bits/stdc++.h>
 
using namespace std;
  
#define pli pair<long long, int> 
#define pii pair<int, int>
#define ll long long
#define ln '\n'
#define ar array
 
const int M = 1e9 + 7;
const int mxN=1e5;
int n, m;
ll d[mxN];
vector<ar<ll, 2>> adj[mxN];
 
void solve() {  
    memset(d, 0x3f, sizeof(d));
 
    priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
    pq.push({0, 0});
    d[0]=0;
 
    while (!pq.empty()) {
        ar<ll, 2> u=pq.top();
        pq.pop();
        if (u[0]>d[u[1]])
            continue;
 
        for (ar<ll, 2> &v: adj[u[1]]) {
            if (u[0]+v[1]<d[v[0]]) {
                d[v[0]]=u[0]+v[1];
                pq.push({d[v[0]], v[0]});
            }
        }  
    }
 
    for (int i=0; i<n; ++i) {
        cout << d[i] << " ";
    }
}   
 
int main() {
    cin >> n >> m;
    for (int i=0, a, b, c; i<m; ++i) {
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1, c});
    }
 
    solve();
}
 
