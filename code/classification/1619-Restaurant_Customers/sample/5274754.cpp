#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int n; cin>>n;
    vector<pair<int, int>> a;
    for(int i = 0; i<n; i++){
        int temp1, temp2;
        cin>>temp1>>temp2;
        a.push_back({temp1, 1});
        a.push_back({temp2, -1});
    };
    sort(a.begin(), a.end());
 
    int currentcustomer = 0;
    int maxcustomer = 0;
    for(auto x : a){
        currentcustomer += x.second;
        maxcustomer = max(maxcustomer, currentcustomer);
    };
    cout<<maxcustomer;
    
    return 0;
}
