#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
multiset<int> tickets;
vector<int> requests(m);
for(int i=0;i<n;i++)
{
    int t;
    cin>>t;
    tickets.insert(t*-1);
}
for(int i=0;i<m;i++){
    cin>>requests[i];
}
for(auto request : requests){
    auto search = tickets.lower_bound(request*-1);
    if(search==tickets.end())
    cout<<(-1)<<"\n";
    else
    {cout<<(*search)*-1<<"\n";
    tickets.erase(search);
    }
}
// cout<<endl;
    return 0;
}
