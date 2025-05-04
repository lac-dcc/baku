#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<string>
#include<cmath>
#include<climits>
#include<vector>
#include<bitset>
using namespace std;
 
// 2147483647
 
typedef long long int ll;
 
void solve(){
    int n, m;
    ll k;
 
    cin >> n >> m >> k;
 
    vector<ll> a(n);
    vector<ll> b(m);
 
    for(int i = 0; i < n; i++){
        cin >> a[i];
    } 
 
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    int pa = 0;
    int pb = 0;
    int count = 0;
 
    while(pa < n){
        while(pb < m && b[pb] < a[pa] - k)
            pb++;
        
        if (pb == m)
            break;
 
        if (abs(b[pb] - a[pa] <= k)){
            pa++;
            pb++;
            count++;
        }
        else{
            pa++;
        }
    }
    
    cout << count << "\n";
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
 
    while(t--){
        solve();
    }
 
    return 0;
}