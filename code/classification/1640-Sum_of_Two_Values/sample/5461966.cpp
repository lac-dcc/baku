#include <bits/stdc++.h>
#define  sz(a)  (int) a.size() 
typedef long long ll;
 
using namespace std;
int32_t main() {
    int n,x;
    cin>>n>>x;
    vector< pair<int,int> >v;
    for (int i = 0; i < n; i++) {
        int a;cin>>a;
        v. push_back({a,i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
            int g=v[i].first;
            int fd=x-g;
            // binsr
            ll l=i+1,r=n-1,f=0;
            while(l<=r)
            {
                ll m=(l+r)/2;
                if(v[m].first==fd )
                {
                    f=1;
                    cout<<v[i].second+1<<" "<<v[m].second+1<<'\n';
                    return 0;
                    break;
                }
                else if(fd<v[m].first)
                    r=m-1;
                else
                    l=m+1;
            }
            // if(f==1)
    }
    cout<<"IMPOSSIBLE"<<'\n';
}