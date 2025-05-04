#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define migmig cin.tie(NULL);ios_base::sync_with_stdio(false)
#define pb push_back
using namespace std;
const ll mod = 1e9 + 7;
vector <int> a[200001];
bool visited[200001];
int maax = 0;
int maaxy[200001];
void dfs(int r){
    visited[r] = 1;
    int maax1 = 0;
    int maax2 = 0;
    int t = 0;
    for (auto i : a[r]){
        if (visited[i] == 0){
            dfs(i);
            if (maaxy[i] > maax1) maax2 = maax1, maax1 = maaxy[i];
            else if (maaxy[i] > maax2) maax2 = maaxy[i];
            t++;
        }
    }
    maaxy[r] = maax1 + 1;
    maax = max(maax, maax1 + maax2);
}
void solve(){
	memset(visited, 0, sizeof(visited));
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int g, h;
        cin >> g >> h;
        a[g].pb(h);
        a[h].pb(g);
    }
    dfs(1);
    cout << maax << endl;
}
int main(){
    migmig;
    int tc = 1;
    // cin >> tc;
    for (int ti = 0; ti < tc; ti++) solve();
}
