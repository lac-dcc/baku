#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    int x, total;
 
    cin >> n >> x;
 
    pair<int,int> values[n];
 
    for(int i{0}; i < n; ++i){
        cin >> values[i].first;
        values[i].second = i;
    }
 
    sort(values, values + n);
 
    int first{0}, last{n-1};
 
    while (last > first){
        if(values[first].first + values[last].first == x){
            cout << values[first].second + 1 << " " << values[last].second + 1;
            return 0;
        }
        if(values[first].first + values[last].first > x)--last;
        if(values[first].first + values[last].first < x)++first;
    }
    
    cout << "IMPOSSIBLE";
 
 
    return 0;
}