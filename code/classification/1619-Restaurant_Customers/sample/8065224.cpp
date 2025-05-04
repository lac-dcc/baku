#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(400001,0);
    vector<pair<int,bool>> p; 
    for(int i = 0;i<2*n;++i){
        ll x;
        cin >> x;
        p.push_back({x,i%2 == 0});
    }
    sort(p.begin(),p.end());
    for(int i = 0;i<p.size();++i){
        if(p[i].second) a[i] += 1 ;
        else a[i+1] += -1;
    }
    int maxc = 0;
    int prefs = 0;
    for(int i = 0;i<a.size();++i){
        prefs += a[i];
        maxc = max(maxc,prefs);
    }
    cout << maxc << endl;
    return 0;
}
