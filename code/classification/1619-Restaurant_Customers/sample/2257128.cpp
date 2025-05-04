#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define ll long long
 
ll res[200001];
 
int main(){
    IOS;
    ll N;
    cin >> N;
    vector<pair<ll,bool>> vp;
    for(ll i=0;i<N;i++){
        ll a,b;
        cin >> a >> b;
        vp.push_back({a,true});
        vp.push_back({b,false});
    }
    sort(vp.begin(),vp.end());
    ll max_count=0;
    ll ans = 0;
    for(ll i=0;i<2*N;i++){
        if(vp[i].second == true){
            ans++;
        }   
        else if(vp[i].second == false){
            ans--;
        }
        max_count = max(max_count,ans);
    }
    cout << max_count << endl;
    
 
    
 
    return 0;
}
