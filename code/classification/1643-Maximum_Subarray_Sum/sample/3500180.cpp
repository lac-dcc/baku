#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
int main()
{
    ll n, max_so_far, curr_max;
    cin >> n;
    ll a[n];
 
    for (ll i=0;i<n;i++) {
        cin >> a[i];
    }
 
    max_so_far = a[0];
    curr_max = a[0];
 
    for (ll i = 1; i < n; i++) {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(curr_max, max_so_far);
    }
 
    cout << max_so_far << endl;
}