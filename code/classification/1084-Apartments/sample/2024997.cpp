#include<bits/stdc++.h>
 
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n, m, res=0;
    long long k;
    cin >> n >> m >> k;
 
    vector<long long> guests(n), apartments(m);
    for (int i = 0; i < n; ++i) cin >> guests[i];
    for (int i = 0; i < m; ++i) cin >> apartments[i];
 
    sort(guests.begin(), guests.end());
    sort(apartments.begin(), apartments.end());
 
 
    int start = 0;
    long long diff;
    for (auto g : guests) {
        if (start==n) break;
        for (int i = start; i < m; ++i) {
            diff = g-apartments[i];
            if (diff > k) ++start;
            else if (-diff > k) break;
            else {
                ++res;
                start = i+1;
                break;
            }
        }
    }
 
    cout << res << '\n';
 
    return 0;
}
