#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define fre(A) freopen(A".inp","r",stdin); freopen(A".out","w",stdout);
#define ii pair<int,int>
#define vt vector
const int N = 2e5 + 1;
const ll mod = 1e9 + 7;
 
int a[N], b[N];
 
bool InRange(int val, int k, int v){
    if(val - k > v) return 0;
    if(val + k < v) return 0;
    return 1;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //fre("t");
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int pos = 1, ans = 0;
    for(int i = 1; i <= n; ++i){
        while(pos <= m && b[pos] + k < a[i]) pos++;
        if(InRange(a[i], k, b[pos]) ){
            ans++;
            pos++;
        }
    }
    cout << ans;
 
    return 0;
}