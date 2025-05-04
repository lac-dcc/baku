#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
 
int inTickets, inCustomers, inp; multiset<int> tickets;
int maxVal;
 
int main() {
  cin >> inTickets >> inCustomers;
  for (int i = 0; i < inTickets; i++) {
    cin >> inp; tickets.insert(inp);
  }
  for (int i = 0; i < inCustomers; i++) {
    cin >> maxVal;
    auto it = tickets.upper_bound(maxVal);
    if (it == tickets.begin()) {
      cout << -1 << endl;
    }
    else {
      cout << *(--it) << endl;
      tickets.erase(it);
    }
  }
}
