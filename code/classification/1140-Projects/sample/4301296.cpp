#include <bits/stdc++.h>
#define int long long
using namespace std;
// #include "fkh.cpp"
 
void coordinatecompress(vector<int> &data) {
    int n = data.size();
    vector<pair<int, int> > tempdata(n);
    for (int i = 0; i < n; i++)
        tempdata[i] = {data[i], i};
    sort(tempdata.begin(), tempdata.end());
    data[tempdata[0].second] = 0;
    for (int i = 1; i < n; i++)
        data[tempdata[i].second] = data[tempdata[i - 1].second] + (tempdata[i - 1].first != tempdata[i].first);
}
 
int32_t main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<tuple<int, int, int> > v(n);
    vector<int> points;
    for (int i = 0; i < n; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        v[i] = {a, b, p};
        points.push_back(a);
        points.push_back(b);
        // debug(a, b, p);
    }
    coordinatecompress(points);
    // debug(points);
    vector<vector<int> > en(2 * n);
    for (int i = 0; i < n; i++) {
        get<0>(v[i]) = points[2 * i];
        get<1>(v[i]) = points[2 * i + 1];
        en[get<1>(v[i])].push_back(i);
    }
    // debug(en);
    vector<int> max_before(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        if (i)
            max_before[i] = max_before[i - 1];
        // now do for all en
        for (int id : en[i]) {
            max_before[i] = max(max_before[i], get<2>(v[id]) + (get<0>(v[id]) > 0 ? max_before[get<0>(v[id]) - 1] : 0));
        }
    }
    cout << max_before[2 * n - 1];
    // debug(max_before[2 * n - 1]);
    // for (int i = 0; i < n; i++) {
    //     cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << ' ' << get<2>(v[i]) << endl;
    // }
    return 0;
}
