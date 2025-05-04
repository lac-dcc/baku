#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multimap<int, int>mm;
    int n, m, h, t;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>h;
        mm.insert(make_pair(h, i));
    }
    while(m--){
        cin>>t;
        if(mm.size() == 0){
            cout<<-1<<endl;
            continue;
        }
        auto i = mm.lower_bound(t);
        if(i == mm.end()){
            i--;
        }
        if(i->first <= t){
            cout<<i->first<<endl;
            mm.erase(i);
        }
        else{
            if(i != mm.begin()){
                i--;
                cout<<i->first<<endl;
                mm.erase(i);
            }
            else{
                cout<<-1<<endl;
            }
        }
    }
}
