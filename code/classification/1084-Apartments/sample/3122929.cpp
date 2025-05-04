#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
void readInput(int& n, int& m, int& k, vector<int>& applicants, vector<int>& apartments) {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        applicants.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        apartments.push_back(b);
    }
}
 
int main() {
    int n, m, k;
    vector<int> applicants;
    vector<int> apartments;
    readInput(n, m, k, applicants, apartments);
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    size_t i = 0;
    size_t j = 0;
    size_t count = 0;
    while (i < applicants.size() && j < apartments.size()) {
        int applicant = applicants[i];
        int apartment = apartments[j];
        if (applicant >= apartment - k && applicant <= apartment + k) {
            i++;
            j++;
            count++;
        } else if (applicant > apartment + k) {
            j++;
        } else {
            i++;
        }
    }
    cout << count << endl;
    return 0;
}
