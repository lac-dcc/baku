#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
const int maxN = 2e5 + 5;
 
map <int, bool> fr;
 
int v[maxN];
 
signed main() {
 
    int n, Smax; cin >> n >> Smax;
 
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
 
    fr[v[1]+v[2]] = true;
 
    for(int i = 3; i < n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            if(fr[Smax-v[i]-v[j]] == true) {
                for(int k1 = 1; k1 <= i-2; ++k1)
                    for(int k2 = k1+1; k2 <= i-1; ++k2)
                        if(v[i] + v[j] + v[k1] + v[k2] == Smax) {
                            cout << k1 << " " << k2 << " ";
                            k2 = i;
                            k1 = i;
                        }
                cout << i << " " << j;
                return 0;
            }
        }
        for(int j = 1; j < i; ++j)
            fr[v[i] + v[j]] = true;
    }
 
    cout << "IMPOSSIBLE";
 
    return 0;
}
