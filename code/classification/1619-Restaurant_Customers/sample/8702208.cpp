#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl '\n'
#define FOR(i,a,n) for(int i=a;i<=n;++i)
#define FOD(i,a,n) for(int i=a;i>=n;--i)
#define REP(i,n) for(int i=0;i<n;++i)
 
const int maxn = 1e6;
int n;
vector<pair<int,int>>a;
 
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
    cin>>n;
    while(n--){
        int x,y;cin>>x>>y;
        a.push_back({x,1});
        a.push_back({y,-1});
    }
    sort(a.begin(),a.end());
    int cnt=0,ans=0;
    for(auto &it:a){
        cnt+=it.second;
        ans=max(ans,cnt);
    }
    cout<<ans;
 
    return 0;
}
