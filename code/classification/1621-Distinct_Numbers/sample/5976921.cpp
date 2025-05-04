#include <bits/stdc++.h>
#include <set>
 
 
int main() {
    std::set<int> distinct_numbers;
    int n;
    std::cin >> n;
 
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        distinct_numbers.insert(x);
    }
 
    std::cout << distinct_numbers.size() << std::endl;
    return 0;
}