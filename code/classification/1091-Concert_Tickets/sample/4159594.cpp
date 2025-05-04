#include<bits/stdc++.h>
using namespace std;
#define fastInput ios_base::sync_with_stdio(0); cin.tie(0);
// #define ll __int128_t
#define ll long long
#define mod int(1e9+7)
//solve today's leetcode
 
int main() {
    int n, m;
    cin >> n >> m;
    multiset<int, greater<int>> ticket;
    //kmultiset is a set which contains duplicate values also
    //in set or multiset we can insert or erase elements in
    // O(logn) time where as insertion or deletion can take O(N)
    // time in vector or array in worst case dus to shifting of
    // elements of array.
    int maxPrice[m];
 
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        ticket.insert(temp);
    }
 
    for (int i = 0; i < m; i++) {
        cin >> maxPrice[i];
    }
 
    for (int i = 0; i < m; i++) {
        auto ans = ticket.lower_bound(maxPrice[i]);
 
        if (ans == ticket.end()) {
            cout << "-1\n";
        } else {
            cout << *ans << "\n";
            ticket.erase(ans);
        }
    }
    return 0;
}
 
 
