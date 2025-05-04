#include <bits/stdc++.h>
#define check(a, b, c, d) a != b && a != c && a != d && b != c && b != d && c != d
using namespace std;
 
map <int, vector <pair <int, int>>> Hash;
int main() {
    int n, k;
    cin >> n >> k;
 
    vector <int> v(n);
    for (auto &it: v)
        cin >> it;
 
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            Hash[v[i] + v[j]].emplace_back(i, j);
 
    for (auto it: Hash)
        for (auto unu: it.second)
            for (auto doi: Hash[k - it.first])
                if (check(unu.first, unu.second, doi.first, doi.second)) {
                    cout << unu.first + 1 << ' ' << unu.second + 1 << ' ' << doi.first + 1 << ' ' << doi.second + 1 << endl;
                    return 0;
                }
 
    cout << "IMPOSSIBLE" << endl;
    return 0;
}