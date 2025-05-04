#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    while(n--){
       int l,r;
       cin>>l>>r;
       v.push_back({l,1});
       v.push_back({r,-1});
    }
    sort(v.begin(),v.end());
    int maxelement=0;
    int sum=0;
    for(int i=0;i<(int)v.size();i++){
        sum+=v[i].second;
        maxelement=max(maxelement,sum);
    }
    cout<<maxelement<<"\n";
    
}
