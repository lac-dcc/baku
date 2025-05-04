#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n,m;cin>>n>>m;
    multiset<int> ms;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        ms.insert(a);
    }
    for(int i=0;i<m;i++){
        int maxp;cin>>maxp;
        if(ms.empty()){
            cout<<-1<<endl;
            continue;
        }
        auto lb = ms.lower_bound(maxp);
        if(*lb == maxp){
            cout<<maxp<<endl;
            ms.erase(lb);
        }
        else if(lb == ms.begin()){
            cout<<-1<<endl;
        }
        else{
            lb--;
            cout<<*lb<<endl;
            ms.erase(lb);
        }
    }
    return 0;
}
