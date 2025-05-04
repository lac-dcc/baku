//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()
 
const int MOD = 1e9+7;
 
void solve()
{
    int n,x;
    cin>>n>>x;
    
    vector<int> vec;
    vector<pair<int,int>> v;
 
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back({x,i+1});
    }
 
    sort(all(v));
 
    for(auto it:v) vec.push_back(it.first);
 
    for(int i=0;i<n;i++){
        if(vec[i] > x) break;
        for(int j=i+1;j<n;j++){
            int target = x - (vec[i] + vec[j]);
            if(target < 0) break;
            int st = j+1;
            int en = n-1;
            while(st<en){
                if(target == vec[st] + vec[en]){
                    vector<int> ans = {v[i].second,v[j].second,v[st].second,v[en].second};
                    sort(all(ans));
                    for(auto it:ans) cout<<it<<" ";
                    return;
                }else if(target < vec[st] + vec[en]){
                    en--;
                }else st++;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}
 
signed main(){
    IOS
    solve();
    return 0;
}