#include <bits/stdc++.h>
using namespace std;
#define pushback push_back
#define pushfront push_front
#define popback pop_back
#define popfront pop_front
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin>>n>>m;
    multiset <int> ms;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ms.insert(x);
    }
    //auto k=ms.upper_bound(1);
    //cout<<*(k)<<endl;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        auto it=ms.upper_bound(a);
        if(it==ms.begin()) cout<<-1<<endl;
        else cout<<*(--it)<<endl, ms.erase(it);
    }
}
