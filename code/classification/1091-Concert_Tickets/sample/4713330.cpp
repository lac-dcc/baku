#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int n,m,c;
    cin>>n>>m;
    vector<int> a(m);
    map<int,int> b;
    for(int i=0;i<n;i++){
        cin>>c;
        b[-c]++;
    }
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    map<int,int>::iterator it;
    for(int i=0;i<m;i++){
        it = b.lower_bound(-a[i]);
        if(it == b.end()){
            cout<<-1<<endl;
        }
        else{
            cout<<-(*it).first<<endl;
            (*it).second--;
            if((*it).second==0){
                b.erase((*it).first);
            }
        }
    }
    return 0;
}
