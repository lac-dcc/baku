#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(){
    int n, m , k;
    cin >> n >> m >> k;
 
    priority_queue<int> req, house;
    for(int i = 0 ; i< n ; i++){
        int ele;
        cin >> ele;
        req.push(ele);
    }
    for(int i = 0 ; i< m ; i++){
        int ele;
        cin >> ele;
        house.push(ele);
    }
    int ans = 0;
    while(!house.empty() && !req.empty()){
        int a = house.top();
        int b = req.top();
        if(b+k >= a && b-k <= a){
            req.pop();
            house.pop();
            ans++;
        }
        else if(a > b){
            house.pop();
        }
        else req.pop();
    }
    cout << ans << endl;
}
int main(){
    #ifdef AADITVA_VIJAY_VATS
        freopen("Input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1LL;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
