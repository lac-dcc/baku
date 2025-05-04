#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>v1(n);
    vector<int>v2(m);
    set<pair<int,int>>s;
    for(int i=0;i<n;i++){
        cin>>v1[i];
        s.insert({v1[i],i});
    }
    for(int i=0;i<m;i++){
        cin>>v2[i];
    }
 
    for(int i=0;i<m;i++){
        auto m = s.lower_bound({v2[i]+1,0});
        if(m==s.begin()){
            cout<<"-1"<<"\n";
        }
        else{
            m--;
            cout<<(*m).first<<"\n";
            s.erase(m);
        }
    }
 
    return 0;
}
