#include <bits/stdc++.h>
 
using namespace std;
 
const int c=6e5;
 
long n, po=1<<18, q, f[c], p[c], s[c], v[c], a, i, e, o, b, j;
void u() {
    cin >> e,
    a=i+po-1;
    f[a]=e, p[a]=s[a]=v[a]=max(e, o);
    while (a>>=1)
        b=j=2*a,
        f[a]=f[b]+f[++j],
        p[a]=max(p[b], f[b]+p[j]),
        s[a]=max(s[j], f[j]+s[b]),
        v[a]=max({v[b], v[j], s[b]+p[j]});
 
}
int main()
{
    cin >> n >> q;
 
    while (++i<=n)
        u();
 
    while (q--)
        cin >> i,
        u(),
        cout << v[1] << " ";
 return 0;
}
