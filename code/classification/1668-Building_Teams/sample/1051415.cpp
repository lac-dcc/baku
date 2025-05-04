#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = int64_t;
 
int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> G(n+1, vector<ll>{});
    vector<ll> ANS(n+1,0);
    vector<bool> SEEN(n+1, false);
    for (ll i=0; i<m; i++){
        ll a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    deque<ll> Q;
    for (auto i=1; i<=n; i++){
        if (!SEEN[i]) {
            Q.push_front(i);
            ANS[i] = 1;
            while(!Q.empty()){
                ll p = Q.front();
                Q.pop_front();
                for (auto f : G[p]){
                    if (SEEN[f]) { continue; }
                    if (ANS[f] == ANS[p]) {
                        cout << "IMPOSSIBLE" << endl;
                        exit(0);
                    }
                    ANS[f] = 3 - ANS[p];
                    Q.push_back(f);
                }
                SEEN[p] = true;
            }
        }
    }
 
    for (auto i=1; i<=n; i++){
        cout << ANS[i] << " ";
    }
    cout << endl;
}
