#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9
 
 
int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n, x; cin >> n >> x;
    map<int, int> mp;
    bool flag = 0;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
 
        if(mp.find(x-a) != mp.end()) {
            flag = 1;
            cout << mp[x-a]+1 << " " << i+1;
            break;
        }
        mp[a] = i;
    }
    if(!flag) {
        cout << "IMPOSSIBLE";
    }
    
}