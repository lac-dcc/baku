#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,x;
    cin>>n>>m;
    set<pair<int,int>> s;
    for(int i=0;i<n;i++){
        cin>>x;
        s.insert({x,i});
    }
    while(m--){
        cin>>x;
        auto itr=s.upper_bound({x,2e5});
        if(itr==s.begin())
        cout<<-1<<endl;
        else{
 
            //cout<<"here";
            --itr;
            cout<<(*itr).first<<endl;
            s.erase(itr);
        }
    }
}
