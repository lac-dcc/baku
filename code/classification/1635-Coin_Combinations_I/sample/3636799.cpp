#include <algorithm>
#include <cstring>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAX=1e6+1;
const ll MOD = 1e9+7;
 
void oh_shit_here_we_go_again() {
    int sz,n;
    cin>>sz>>n;
    vector<ll>v(sz),dp(n+1,0);
    for(auto &x:v) cin>>x;
    dp[0]=1;
    for(ll i=0;i<=n;++i) {
        for(ll j=0;j<sz;++j) {
            if(i>=v[j]) {
                dp[i]+=dp[i-v[j]];
                dp[i]%=MOD;
            }
        }
    }
    cout<<dp[n];
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt=1;
    // cin>>tt;
    while(tt--) {
        oh_shit_here_we_go_again();
    }
}