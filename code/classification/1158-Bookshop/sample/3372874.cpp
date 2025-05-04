#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
const int MOD = 1e9+7;
 
int pages[100001], p[1001], s[1001];
int best=0;
 
int main() {
    int n, x;
    cin >> n >> x;
    for (int i=0; i<n; i++) cin >> p[i];
    for (int i=0; i<n; i++) cin >> s[i];
    vector<vector<int>> k(n+1, vector<int>(x+1));
    for (int i=0; i<=n; i++) {
        for (int w=0; w<=x; w++) {
            if (i==0 || w==0) k[i][w]=0;
            else if (p[i-1]<=w) {
                k[i][w] = max(s[i-1] + k[i-1][w - p[i-1]], k[i-1][w]); // find the max of either adding this item or not adding it
            }
            else k[i][w] = k[i-1][w];
        }
    }
    cout << k[n][x] << endl;
}
