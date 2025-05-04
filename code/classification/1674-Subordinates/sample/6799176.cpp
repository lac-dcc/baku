#include <bits/stdc++.h>
#define ss second
#define ff first
#define endl "\n"
#define sp ' '
#define pback push_back
 
using namespace std;
typedef long long ll;   typedef string str;
const int MOD = 1e9+7, N = 1e5+7, J = 1e3+7;
//chetmeorroiroiorr
int cnt[2*N];
vector<int> vc[2*N];
void dfs(int parent, int node) {
    cnt[parent] = 1;
    for(int i : vc[parent]) {
        if(i == node) continue;
        dfs(i, parent);
        cnt[parent] += cnt[i];
    }
}
void solve(int n) {
    int p;
    for(int i = 2; i <= n; i++) {
        cin >> p;   vc[p].pback(i);
        vc[i].pback(p);
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++) cout << cnt[i]-1 << sp;
 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);     cout.tie(0);
 
    int n;  cin >> n;
    solve(n);
    return 0;
}
