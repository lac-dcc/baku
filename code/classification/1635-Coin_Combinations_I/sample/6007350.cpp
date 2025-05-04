#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9+7;
 
int main(){
    cin.tie(0)->ios_base::sync_with_stdio(0);
    int n,x;cin>>n>>x;
    vector<int> coin(n);
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }
 
    vector<int> combi(x+1, 0);
    combi[0] = 1;
 
    for(int val=1; val<=x; val++){
        long sum=0;
        for(int j=0; j<n; j++){
            if(val>=coin[j]) sum += combi[val-coin[j]];
        }
        combi[val] = sum%mod;
    }
 
    cout << combi[x];
}
