#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
 
 
/****************************** CODE IS HERE ***********************************/
 
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int n; cin >> n;
    vector <pair<int, int>> A;
    for (int i = 0, u, v; i < n; ++i) { 
        cin >> u >> v;
        A.push_back({u, 1});
        A.push_back({v, 2});
    }
    sort(all(A));
 
    int curr = 0, ans = 0;
    for (int i = 0; i < sz(A); ++i) {
        curr += (A[i].second == 1 ? 1 : -1);
        ans = max(ans, curr);
    }
 
    cout << ans;
 
    return 0;
}
 
