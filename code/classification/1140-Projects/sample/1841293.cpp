//
//  blank.cpp
//  
//
//  Created by Sagar Singh on 17/12/20.
//
 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#define bug1( x )                   { cerr << (#x) <<"="<< x << endl; }
#define bug2( x , y )               { cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl; }
#define bug3( x , y , z )           { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl; }
#define bug4( x , y , z , w)        { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl; }
#define bug5( x , y , z , w ,p)     { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl; }
#define bug6( x , y , z , w ,p , q) { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl; }
#define bugn( x , n )               { cerr<<(#x)<<":";for(int i=0;i<n;i++)cout<<(#x)<<"["<<i<<"]:"<< x[i] << "    "; cout<<endl; }
#define bugnm( x , n , m )          { cerr<<(#x)<<endl;for(int i=0;i<n;i++){ cout<<"Row #"<<i<<":"; for(int j=0;j<m;j++) cout<<x[i][j]<<"     "; cout << endl;} }
typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;
using namespace std;
 
 
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector< ll > order;
    vector< ll > l(n), r(n), coin(n);
    for(int i=0;i<n;++i){
        cin >> l[i] >> r[i] >> coin[i];
        order.push_back(l[i]);
        order.push_back(r[i]);
    }
    sort(order.begin(),order.end());
    order.erase(unique(order.begin(),order.end()),order.end());
    int m = order.size();
    vector< vector<pair<ll,ll>> > g(m+5);
    vector< ll > dp(m+5);
    for(int i=0;i<n;++i){
        l[i] = lower_bound(order.begin(),order.end(),l[i]) - order.begin() + 1;
        r[i] = lower_bound(order.begin(),order.end(),r[i]) - order.begin() + 1;
       // bug3(i,m,l[i]);
        g[l[i]].push_back({r[i],coin[i]});
    }
    for(int i=1;i<=m+2;++i){
        dp[i] = max(dp[i],dp[i-1]);
        for(auto [r,c]:g[i]){
            dp[r+1] = max(dp[r+1],dp[i]+c);
        }
        //bug2(i,dp[i]);
    }
    cout << dp[m+1] << endl;
    
    
}
 