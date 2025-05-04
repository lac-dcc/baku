#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<int> applicant_sizes(n);
    vector<int> apartment_sizes(m);
 
    for (int i = 0; i < n; ++i) {
        cin >> applicant_sizes[i];
    }
 
    for (int i = 0; i < m; ++i) {
        cin >> apartment_sizes[i];
    }
 
    sort(applicant_sizes.begin(), applicant_sizes.end());
    sort(apartment_sizes.begin(), apartment_sizes.end());
 
    int apt_ptr = 0;
    int app_ptr = 0;
    int count = 0;
 
    while (apt_ptr < n && app_ptr < m) {
        if (abs(applicant_sizes[apt_ptr] - apartment_sizes[app_ptr]) <= k) {
            count++;
            apt_ptr++;
            app_ptr++;
        } else if (applicant_sizes[apt_ptr] - k > apartment_sizes[app_ptr]) {
            app_ptr++;
        } else {
            apt_ptr++;
        }
    }
 
    cout << count << endl;
 
    return 0;
}