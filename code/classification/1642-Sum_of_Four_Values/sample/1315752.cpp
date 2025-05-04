#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <array>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int M = 1e9 + 7;
 
int main() {
    int n; ll x;
    cin >> n >> x;
 
    vll a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    map<int, array<int, 2>> map;
 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (map.find(x - a[i] - a[j]) != map.end()) {
                array<int, 2> pair = map[x - a[i] - a[j]];
 
                cout << i + 1 << " " << j + 1 << " " << pair[0] + 1 << " " << pair[1] + 1;
                cout << endl;
                return 0;
            }
        }
 
        for (int j = 0; j < i; j++)
            map[a[i] + a[j]] = {i, j};
    }
 
    cout << "IMPOSSIBLE\n";
}