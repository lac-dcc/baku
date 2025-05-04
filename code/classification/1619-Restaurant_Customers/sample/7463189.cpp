#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
 
using namespace std;
using ll = long long;
 
int main(){
    int n, a, b;
    scanf("%d", &n);
    vector<pair<int, int>> times;
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &a, &b);
        times.push_back({a, 1});
        times.push_back({b, -1});
    }
    sort(times.begin(), times.end());
    int cur = 0;
    int max = 0;
    for(auto pair : times){
        cur += pair.second;
        if(cur > max) max = cur;
    }
    printf("%d", max);
}
