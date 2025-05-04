#include <iostream>
#include <vector>
#include <algorithm>
#define long long l l
#define l l int
using namespace std;
 
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ap;
    vector<int> house;
    for (int i = 0, a; i < n; ++i) {
        cin >> a;
        ap.push_back(a);
    }
    for (int i = 0, a; i < m; ++i) {
        cin >> a;
        house.push_back(a);
    }
    sort(ap.begin(), ap.end());
    sort(house.begin(), house.end());
    int iter = 0, j = 0, count = 0;
    while (iter < m && j < n) {
        if (house[iter] > ap[j] + k)
            j++;
        else if (house[iter] < ap[j] - k)
            iter++;
        else {
            count ++;
            j++;
            iter++;
        }
    }
    cout << count << endl;
    return 0;
}