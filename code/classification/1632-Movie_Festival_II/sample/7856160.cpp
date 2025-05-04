#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int) (x).size()
#define pb push_back
#define nl "\n"
#define F first
#define S second
using namespace std;
using ll = long long;
 
#if defined(END39_WIN)
#include "C:\debug.h"
#elif defined(END39_MAC)
#include "/Users/Shared/debug.h"
#else
#define dbg(...)
#endif
 
//----------------------------------------------------//
 
void setIO() {
#ifdef END39_FILE_INPUT
    freopen(pathToInput, "r", stdin);
#endif
#ifdef END39_FILE_OUTPUT
    freopen(pathToOutput, "w", stdout);
    freopen(pathToDebug, "w", stderr);
 
    time_t cur_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
    string cur_time_and_date = ctime(&cur_time);
    string time_text = "Time: " + cur_time_and_date.substr(11, 8);
    cout << time_text << nl;
    cerr << time_text << nl;
#endif
}
 
//----------------------------------------------------//
 
typedef vector<int> vi;
const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo_,int hi_):lo(lo_),hi(hi_){} // Large interval of -inf
    Node(vi& v, int lo_, int hi_) : lo(lo_), hi(hi_) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
    void prnt() {
        push();
        if (lo + 1 < hi) {
            l->prnt();
            r->prnt();
        }
        else {
            cout << val << " ";
        }
    }
};
 
void testCase() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    vector<int> nums;
 
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
        nums.pb(a);
        nums.pb(b);
    }
 
    /*
    coordinate compression, then linear time
    sort by end time
 
    new approach (still with two above things):
    keep max lazy segment tree
    only add movie if mx(range) < k
    increment range in segtree
 
    O(n log n) time, O(n) space
    */
 
    sort(all(nums));
    nums.resize(unique(all(nums)) - nums.begin());
 
    for (auto& [a, b] : v) {
        a = int(lower_bound(all(nums), a) - nums.begin());
        b = int(lower_bound(all(nums), b) - nums.begin());
    }
 
    sort(all(v), [](pair<int, int> p1, pair<int, int> p2) {
        return p1.S < p2.S; // start time doesn't matter
        // return p1.S < p2.S || (p1.S == p2.S && p1.F < p2.F);
    });
 
    vector<int> empt(sz(nums)+5);
    Node* segtree = new Node(empt, 0, sz(empt));
    int ans = 0;
    // dbg(v);
 
    for (auto [start, end] : v) {
        // end time EXCLUDED
        if (segtree->query(start, end) < k) {
            ans++;
            segtree->add(start, end, 1);
            // segtree->prnt(), cout << nl;
        }
    }
 
    cout << ans;
 
    /*
    queue<int> end_times;
    int ans = 0;
 
    for (auto [a, b] : v) {
        if (k) {
            k--, ans++;
            end_times.push(b);
        }
        else if (end_times.front() <= a) {
            end_times.pop();
            ans++;
            end_times.push(b);
        }
    }
 
    cout << ans;
    */
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    setIO();
    int t = 1;
    // cin >> t;
 
    while (t--) {
        testCase();
    }
}
 
/*
edge cases?
time complexity?
overflow? - what is min and max values for variables?
indexing in-bounds?
0-index or 1-index?
*/
