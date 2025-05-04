#include <bits/stdc++.h>
using namespace std;
 
bool customCompare(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(begin(v), end(v), customCompare);
    int count = 1;
    --k;
    multiset<int> st;
    st.insert(v[0].second);
    for(int i = 1; i < n; ++i) {
        auto it = st.upper_bound(v[i].first);
        if(it == st.begin()) {
            if(k > 0) {
                --k;
                st.insert(v[i].second);
                ++count;
            }
        } else {
            --it;
            st.erase(it);
            st.insert(v[i].second);
            ++count;
        }
    }
    cout << count;
    return 0;
}
 