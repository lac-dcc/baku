//
//  main.cpp
//  Lesson 9 Homework
//
//  Created by Hanson Gu on 2024-02-05.
//
 
#include <iostream>
#include <cmath>
#include <set>
#include <vector>
 
using namespace std;
 
void towerOfHanoi(int n, int a, int b, int c) {
    if (n == 0) {
        return;
    }
    
    towerOfHanoi(n - 1, a, c, b);
    cout << a << " " << c << "\n";
    towerOfHanoi(n - 1, b, a, c);
}
 
void concertTickets(int n, int m) {
    int h, t;
    multiset<int> tickets;
    vector<int> price;
    
    for (int i = 1; i <= n; ++i) {
        cin >> h;
        tickets.insert(h);
    }
    
    for (int i = 1; i <= m; ++i) {
        cin >> t;
        price.push_back(t);
    }
    
    for (int i = 0; i < m; ++i) {
        auto afford = tickets.upper_bound(price[i]);
        if (afford == tickets.begin()) {
            cout << -1 << "\n";
        }
        else {
            cout << *(--afford) << "\n";
            tickets.erase(afford);
        }
    }
}
 
int main() {
    // The Tower of Hanoi
    /*
    int n;
    cin >> n;
    
    cout << pow(2, n) - 1 << "\n";
    
    towerOfHanoi(n, 1, 2, 3);
    return 0;
     */
    
    
    // Concert Tickets
    int n, m;
 
    cin >> n >> m;
    concertTickets(n, m);
}
