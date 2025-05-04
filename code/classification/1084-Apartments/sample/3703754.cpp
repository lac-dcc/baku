#include "bits/stdc++.h"
#include <iostream>
#include <cmath>
using namespace std;
 
 
int main() {
    long int n, m, count;
    long long int k;
    count = 0;
    cin >> n >> m >> k;
    deque<int> desired_apartment;
    deque<int> avail_apartment;
 
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        desired_apartment.push_back(k);
 
    }
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        avail_apartment.push_back(k);
 
    }
    std::sort(desired_apartment.begin(), desired_apartment.end());
    std::sort(avail_apartment.begin(), avail_apartment.end());
    for (auto item: desired_apartment
            ) {
        auto it =lower_bound(avail_apartment.begin(), avail_apartment.end(), item - k);
 
        if(it!=avail_apartment.end()){
            if (abs(avail_apartment[it - avail_apartment.begin()] - item) <= k) {
//            cout << "yes "<< avail_apartment[it - avail_apartment.begin()] <<"it is"<<it-avail_apartment.begin()<<endl;
                count += 1;
                avail_apartment.erase(it);
 
 
            }
        }
 
//        else
//        {
//        cout << "No"<<endl;
//        cout<<it-avail_apartment.begin()<<endl;
//
//        }
    }
    cout << count;
 
    return 0;
}
 
 