#include <bits/stdc++.h>
 
using namespace std;
 
const long long N = 1e3 + 5;
 
long long n, x, l, r, a, b, c, d;
 
pair<long long, long long> arr[N];
 
map<long long, vector<pair<long long, long long>>> pairs;
 
vector<pair<long long, pair<long long, long long>>> pairsv;
 
int main(){    
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> n >> x;
 
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
 
    sort(arr + 1, arr + n + 1);
 
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            pairs[arr[i].first + arr[j].first].push_back({arr[i].second, arr[j].second});
        }
    }
 
    for(auto it : pairs){
        for(auto j : it.second){
            pairsv.push_back({it.first, j});
        }
    }
 
    l = 0, r = pairsv.size() - 1;
 
    while(l < r){
        a = pairsv[l].second.first, b = pairsv[l].second.second, c = pairsv[r].second.first, d = pairsv[r].second.second;
        
        if(pairsv[l].first + pairsv[r].first == x){
            if(a != c && a != d && b != c && b != d){
                cout << a << " " << b << " " << c << " " << d;
                return 0;
            }
        }
 
        if(pairsv[l].first + pairsv[r].first > x) r--;
        else l++;
    }
 
    cout << "IMPOSSIBLE";
}
