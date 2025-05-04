#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
#define rz resize
#define all(x) x.begin(), x.end()
 
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
 
const long long MOD = 1e9 + 7;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> v(n);
    int ans=0;
    int k1=k;
    set<pair<int,int>> s;
    for(int n1=0;n1<n;n1++){
        cin>>v[n1].second>>v[n1].first;
    }
    sort(v.begin(),v.end());
    for(int n1=0;n1<n;n1++){
        pair<int,int> p={v[n1].second,v[n1].first};
        if(k1>0){
            auto i=s.upper_bound(p);
            if(i!=s.begin()){
                i--;
                s.erase(i);
                k1++;
            }
            s.insert(v[n1]);
            k1--;
            ans++;
        }else{
            auto i=s.upper_bound(p);
            if(i!=s.begin()){
                i--;
                s.erase(i);
                s.insert(v[n1]);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
 
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}