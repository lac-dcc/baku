#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <deque>
#include <queue>
#include <tuple>
#include <cmath>
#include <cctype>
#include <stack>
#include <cassert>
using namespace std;
using ll = long long;
 
int n, m, n2;
ll segs[800001]={}, segm[800001]={}, pref[800001]={}, suff[800001]={};
 
void setv(int i, int v) {
    i += n2;
    segs[i] = v;
    segm[i] = pref[i] = suff[i] = max(0, v);
    for (i = i/2; i >= 1; i /= 2) {
        segs[i] = segs[2*i]+segs[2*i+1];
        segm[i] = max(max(segm[2*i], segm[2*i+1]), suff[2*i]+pref[2*i+1]);
        pref[i] = max(pref[2*i], segs[2*i]+pref[2*i+1]);
        suff[i] = max(suff[2*i+1], segs[2*i+1]+suff[2*i]);
    }
}
 
 
 
int main() {
    cin >> n >> m;
    n2 = 1; while (n2 <= n) n2 *= 2;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        setv(i, x);
    }
    while (m--) {
        int k, x; cin >> k >> x;
        setv(k, x);
        cout << segm[1] << endl;
    }
 
    return 0;
}
