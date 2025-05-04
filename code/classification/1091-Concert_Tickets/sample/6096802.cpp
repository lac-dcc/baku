#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
 
signed main(){
    int n,q;
    cin>>n>>q;
    multiset<int> s;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        s.insert(tmp);
    }
    for(int i=0;i<q;i++){
        int w;
        cin>>w;
        auto it = s.upper_bound(w);
        if(it==s.begin())cout<<-1<<endl;
        else {cout<<*(--it)<<endl;
        s.erase(it);}
    }
}
