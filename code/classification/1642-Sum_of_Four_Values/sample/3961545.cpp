#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    map<int, vector < pair<int, int> > > mp;
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    for(int i = 0; i < n; i ++) 
        for(int j = i + 1; j < n; j ++) {
            int rem = k - a[i] - a[j];
            if(mp.count(rem)) 
                for(auto l : mp[rem])
                    if(i != l.first && j != l.first && i != l.second && j != l.second)
                        return cout << i + 1 << ' ' << j + 1 << ' ' << l.first + 1 << ' ' << l.second + 1, 0; 
            mp[a[i] + a[j]].push_back({i, j});
        }
    cout << "IMPOSSIBLE";
}
