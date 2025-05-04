#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
 
#define f first
#define s second
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
int n, k;
pll movies[200001];
 
bool cmp(pll m1, pll m2){
    if(m1.s != m2.s){
        return m1.s < m2.s;
    }
 
    return m1.f < m2.f;
}
 
int main(){
    cin >> n >> k;
 
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
 
        movies[i] = make_pair(a, b);
    }
 
    sort(movies, movies + n, cmp);
 
    multiset<ll> times;
    for(int i = 0; i < k; i++){
        times.insert(0);
    }
 
    int res = 0;
    for(int i = 0; i < n; i++){
        auto it = times.upper_bound(movies[i].f);
        if(it == begin(times)){
            continue;
        }
 
        times.erase(--it);
        times.insert(movies[i].s);
        res += 1;
    }
 
    cout << res << endl;
}