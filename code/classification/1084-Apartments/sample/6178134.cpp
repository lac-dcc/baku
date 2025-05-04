#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<int> DS(n);
    for (int i = 0; i < n; i++){
        cin >> DS[i];
    }
 
    vector<int> AS(m);
    for (int i = 0; i < m; i++){
        cin >> AS[i];
    }
 
    sort(DS.begin(), DS.end());
    sort(AS.begin(), AS.end());
 
    int i = 0, j = 0, count = 0;
 
    while (i < n && j < m) {
        if (abs(DS[i] - AS[j]) <= k) {
            count++;
            i++;
            j++;
        } else if (DS[i] < AS[j]) {
            i++;
        } else {
            j++;
        }
    }
 
    cout << count;
    return 0;
}
