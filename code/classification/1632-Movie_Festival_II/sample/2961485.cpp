#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> pii;
 
bool cmp(const pii& x, const pii& y) {
    if (x.second == y.second) {
        return x.first < y.first;
    }
    return x.second < y.second;
}
 
int main() {
    multiset<pii, bool(*)(const pii&, const pii&)> movies(cmp);
    multiset<int> curr_endings;
    int n, k, total = 0; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        pii a; cin >> a.first >> a.second;
        movies.insert(a);
    }
    for (int i = 0; i < k; i++) curr_endings.insert(0);
    
    multiset<int>::iterator watcher;   
    // multiset<int>::iterator begin = ;
    for (pii m : movies) {
        int start = m.first, end=m.second;
        watcher = curr_endings.upper_bound(start);
        if (watcher == curr_endings.begin()) continue;
        --watcher;
        // cout << "Ending " << *watcher << " is watching " << start << " " << end;
        curr_endings.erase(watcher);
        curr_endings.insert(end);
        ++total;
        // cout << "; Endings now "; for (int i : curr_endings) cout << i << " "; cout << endl;
    }
    cout << total << "\n";
}