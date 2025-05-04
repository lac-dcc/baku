#include <bits/stdc++.h>
using namespace std;
 
long long n, x, a;
map<long long, int> h;
 
int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (h[x - a]) {
            cout << h[x - a] << " " << i << "\n";
            return 0;
        }
        if (!h[a]) h[a] = i;
    }
    cout << "IMPOSSIBLE\n";
}
