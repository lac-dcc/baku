#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> desireSize(n);
    vector<int> availableSize(m);
    for(int i = 0;i < n;i++){
        cin >> desireSize[i];
    }
 
    for(int i = 0;i < m;i++){
        cin >> availableSize[i];
    }
 
    sort(availableSize.begin(),availableSize.end());
    sort(desireSize.begin(),desireSize.end());
    
    int i = 0;
    int j = 0;
    int ans = 0;
    while(i < n && j < m){
        if(abs(desireSize[i] - availableSize[j]) <= k){
            ans++;
            i++;
            j++;
        }
        else{
            if(desireSize[i] - availableSize[j] > k){
                j++;
            }
            else{
                i++;
            }
        }
    }
    cout << ans << endl;
}
 
int main()
{
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
