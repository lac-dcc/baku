#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> tickets(n), customers(m);
    set<pair<int, int>> st;
    for(int i = 0; i < n; ++i) {
        cin >> tickets[i];
        st.insert(make_pair(tickets[i], i));
    }
    for(int i = 0; i < m; ++i) {
        cin >> customers[i];
    }
    // auto : type of variable
    for(int i = 0; i < m; ++i) {
        auto it = st.lower_bound(make_pair(customers[i] + 1, 0));
        if(it == st.begin()) {
            cout << -1 << '\n';
        }
        else {
            --it;
            cout << it->first << endl;
            st.erase(it);
        }
    }
    
    
 
    
    return 0;
}
 
 
 
 
 
 
 
 
/*
 
 5 3
  5, 5, 7, 8 : ticket price
 4 8 3 : maximum price each customer is willing to pay
 
 output:
 3, 8, -1
*/
 
