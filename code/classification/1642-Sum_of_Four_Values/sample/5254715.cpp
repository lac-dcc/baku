#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
 
using namespace std;
 
 
void two_sum(int ind, int ind2, vector<pair<int, int>>& a, int x){
 
    int le = ind2 + 1, ri = a.size() - 1;
 
    while(le < ri){
        
        auto [v1, i] = a[le];
        auto [v2, j] = a[ri];
 
        if(v1 + v2 + a[ind].first + a[ind2].first > x){
            ri--;
        }
        else if(v1 + v2 + a[ind].first + a[ind2].first < x){
            le++;
        }
        else{
            cout << a[ind].second + 1 << " " << a[ind2].second + 1 << " " << i + 1 << " " << j + 1 << "\n";
            exit(0);
        }
 
    }
 
}
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
 
    sort(a.begin(), a.end());
 
    for(int i = 0; i < n - 3; ++i){
        for(int j = i + 1; j < n - 2; ++j)
            two_sum(i, j, a, x);
    }
 
    
 
    cout << "IMPOSSIBLE\n";
    
}