#include <iostream>
#include <string>
#include <utility>
#include <tuple>
#include <iterator>
#include <stdexcept>   
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <array>
#include <vector>
#include <cstring>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define INF RAND_MAX
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define all(item) item.begin(), item.end()
#define rall(item) item.rbegin(), item.rend()
#define MOD 1000000007
#define ln '\n'
#define tc ll t;cin >> t;while(t--) 
typedef long long ll;
typedef unsigned long long ull;
//-----------------------------------------------------------
 
int main(){
    ll n,m,k;   
    cin >> n >> m >> k;
    deque<ll> a;
    deque<ll> b;
    for(ll i = 0;i < n;i++){
        ll temp; cin >> temp;
        a.push_back(temp);
    }
    for(ll i = 0;i < m;i++){
        ll temp; cin >> temp;
        b.push_back(temp);
    }
    sort(all(a)); sort(all(b));
    ll ans = 0;
    while(!b.empty() && !a.empty()){
        if(b.front() >= a.front()-k && b.front() <= a.front()+k){
            b.pop_front();
            a.pop_front();
            ans++;
        }else if(b.front() < a.front()-k){
            b.pop_front();
        }else if(b.front() > a.front()+k){
            a.pop_front();
        }
    }
    cout << ans;
    return 0;
}