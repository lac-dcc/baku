#include <bits/stdc++.h>
using namespace std;
set <int> st;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a[200005], cnt=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    for (int i=1; i<=st.size(); i++){
        cnt++;
    }
    cout << cnt;
}
