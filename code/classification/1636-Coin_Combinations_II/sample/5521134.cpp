#include<bits/stdc++.h>
using namespace std;
#define ll  long long
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    /*  freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);*/
    //ll t;
   // cin >> t;
    //while (t--)
    int mod = 1000000007;
    vector<long long int> arr(1000001, 0);
    vector <long long int>coins;
    long long int n, x,c;
    cin >> n >> x;
    
    for (int i = 0; i < n; i++)
    {
        cin >> c;
            coins.push_back(c);
    }
    arr[0] = 1;
    for (long long int i = 0; i < n; i++) {
        for (long long int weight = 0; weight <= x; weight++) {
                if (weight - coins[i] >= 0) {
                    arr[weight] += arr[weight - coins[i]];
                    arr[weight] %= mod;
                }
        }
    }
    cout << arr[x];
 
 
}