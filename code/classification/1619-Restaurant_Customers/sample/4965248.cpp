#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
    vector<pair<int,int>> vec;
    int n,a,b;
    cin>>n;
    _for(i,0,n){
        cin>>a>>b;
        vec.push_back({a,1});
        vec.push_back({b,-1});
    }
    sort(vec.begin(),vec.end());
    int sum=0,maxa=-1;
    for(auto &u:vec){
        sum+=u.second;
        maxa=max(maxa,sum);
    }
    cout<<maxa;
    return 0;
}
