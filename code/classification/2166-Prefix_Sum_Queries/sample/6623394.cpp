#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e5+5;
ll arr[N];
pair<ll, ll> seg[4*N];
 
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
 
void build (ll ind, ll sl, ll sr) {
    if (sl == sr){
        seg[ind].first = max(arr[sl], 0ll);
        seg[ind].second = arr[sl];
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    build(ind*2, sl, mid);
    build(ind*2+1, mid+1, sr);
    seg[ind].first = max(seg[ind*2].first, seg[ind*2].second + seg[ind*2+1].first);
    seg[ind].second = seg[ind*2].second + seg[ind*2+1].second;
}
 
void update(ll ind, ll sl, ll sr, ll ql, ll qr, ll val) {
    if (qr < sl || ql > sr)
        return;
    if (ql <= sl && qr >= sr) {
        seg[ind].first = max(val, 0ll);
        seg[ind].second = val;
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    update(ind*2, sl, mid, ql, qr, val);
    update(ind*2+1, mid+1, sr, ql, qr, val);
    seg[ind].first = max(seg[ind*2].first, seg[ind*2].second + seg[ind*2+1].first);
    seg[ind].second = seg[ind*2].second + seg[ind*2+1].second;
}
 
pair<ll, ll> query(ll ind, ll sl, ll sr, ll ql, ll qr) {
    if (qr < sl || ql > sr)
        return {0, 0};
    if (ql <= sl && qr >= sr)
        return seg[ind];
    ll mid = sl + (sr - sl) / 2;
    pair<ll, ll> o1 = query(ind*2, sl, mid, ql, qr), o2 = query(ind*2+1, mid+1, sr, ql, qr);
    return {max(o1.first, o1.second + o2.first), o1.second + o2.second};
}
 
int main() {
    fast();
    ll n, q, o, ql, qr;
    cin >> n >> q;
 
    for (ll i = 1; i <= n; ++i)
        cin >> arr[i];
 
    build(1, 1, n);
 
    while (q --> 0) {
        cin >> o >> ql >> qr;
        if (o == 1)
            update(1, 1, n, ql, ql, qr);
        else
            cout << query(1, 1, n, ql, qr).first << endl;
    }
 
    return 0;
}
