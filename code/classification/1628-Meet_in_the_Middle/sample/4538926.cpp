#include<bits/stdc++.h>
using namespace std;
 
int n , x , a[40] ;
 
signed main(){
    cin >> n >> x ;
    for(int i = 0;i < n;i ++)
        cin >> a[i] ;
    int n1 = n / 2 , n2 = n - n1  ;
    long long ans = 0;
    vector<int> v ;
    vector<pair<int , int> > v1 , v2 ;
    if(n1 > 0) {
         for(int i = 1;i < (1 << n1);i ++) {
            int s = 0 ; bool ok = 1 ;
            for(int j = 0;j < n1 ;j ++) {
                if((i >> j) & 1) {
                    if(s > x - a[j]) ok = 0;
                    else s += a[j] ;
                }
            }
            if(ok) {
                if(s == x) ans ++ ;
                else v.push_back(s) ;
            }
         }
         if(v.size()) {
             sort(v.begin() , v.end()) ;
             int id = 0 ;
             while(id < v.size()) {
                int id2 = id ;
                while(id2 < v.size() && v[id2] == v[id]) id2 ++ ;
                v1.push_back(make_pair(v[id] , id2 - id)) ;
                id = id2 ;
             }
             v.clear() ;
         }
    }
    if(n2 > 0) {
        for(int i = 1;i < (1 << n2);i ++) {
            int s = 0 ; bool ok = 1 ;
            for(int j = 0;j < n2 ;j ++) {
                if((i >> j) & 1) {
                    if(s > x - a[n1 + j]) ok = 0;
                    else s += a[n1 + j] ;
                }
            }
            if(ok) {
                if(s == x) ans ++ ;
                else v.push_back(s) ;
            }
         }
         if(v.size()) {
             sort(v.begin() , v.end()) ;
             int id = 0 ;
             while(id < v.size()) {
                int id2 = id ;
                while(id2 < v.size() && v[id2] == v[id]) id2 ++ ;
                v2.push_back(make_pair(v[id] , id2 - id)) ;
                id = id2 ;
             }
         }
    }
    if(v2.size())
        for(pair<int, int> i : v1) {
            pair<int , int> j = make_pair(x - i.first , 0) ;
            auto it = lower_bound(v2.begin() , v2.end() , j) ;
            if(it != v2.end() && it->first == j.first)
                ans += 1ll * it->second * i.second ;
        }
    cout << ans ;
}
