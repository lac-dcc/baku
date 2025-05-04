// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
 
#include <iostream>
#include <vector>
using namespace std;
 
long long culc(int on, int start, vector <long long>& a, long long so_far) {
    if (on == 0) {
        return so_far;
    }
    if (a.size() - start < on) {
        return 0;
    }
    long long res = 0;
    for (int i = start; i < a.size(); i++) {
        res += culc(on - 1, i + 1, a, so_far / a[i]);
    }
    return res;
}
 
int main()
{
    long long n;
    cin >> n;
    int k;
    cin >> k;
    vector <long long> nums(k);
    for (int i = 0; i < k; i++) {
        cin >> nums[i];
    }
 
    long long res = 0;
    for (int i = 1; i <= k; i++) {
        if (i % 2 == 0) {
            res -= culc(i, 0, nums, n);
        }
        else {
            res += culc(i, 0, nums, n);
        }
    }
    cout << res;
}
