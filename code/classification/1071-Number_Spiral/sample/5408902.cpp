#include <cmath>
#include <iostream>
 
using namespace std;
 
int main() {
    long a;
    cin >> a;
 
    long long b, c;
    while (cin >> b && cin >> c) {
        long long level = max(b, c);
        int side = (level % 2 == 0) ? -1 : 1;
        long long total = (level - 1) * (level - 1) + level + (c - b) * side;
        cout << total << "\n";
    }
}
