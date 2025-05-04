#include <bits/stdc++.h>
#define _For(i,a,b) for(int i=(a);i<=(b);++i)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
int c[200005],d[200005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    _for(i,0,n) {
        int a,b; cin >> a >> b;
        c[i] = a; d[i] = b;
    }
    sort(c,c+n); sort(d,d+n);
    int p1 = 0, p2 = 0, cnt = 0, ans = 0;
    while (p1 < n && p2 < n) {
        if (c[p1] < d[p2]) ++cnt,++p1;
        else if (c[p1] > d[p2]) --cnt,++p2;
        else ++p1,++p2;
        ans = max(ans,cnt);
    }
    cout << ans << '\n';
    return 0;
}
