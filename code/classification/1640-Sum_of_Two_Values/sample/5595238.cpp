#include <bits/stdc++.h>
 
using namespace std;
int main() {
    int n, x;
    cin>>n>>x;
    vector<pair<int, int>> v(n);
    int tmp;
    for (int i = 0; i<n; i++){
        cin>>tmp;
        v[i] = {tmp, i};
    }
 
    sort(v.begin(), v.end());
    int lo = 0, hi = n-1;
    while(lo < hi){
        if (v[lo].first + v[hi].first > x) hi--;
        else if (v[lo].first + v[hi].first < x) lo++;
        else if (v[lo].first + v[hi].first == x) {
            cout<<v[lo].second + 1<<" "<<v[hi].second + 1<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
 
    return 0;
 
}
