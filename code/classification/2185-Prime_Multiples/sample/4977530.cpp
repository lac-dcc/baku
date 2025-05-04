#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n';
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const double pi = 3.141592653589793238462643383279502884L;
const ll mod = 1e9 + 1647;
const int INF = 1e8;
 
int main()
{
    ios;
    ll n,k;
    cin >> n >> k;
    vector<ll> primes(k);
    for(auto &x:primes)
        cin >> x;
    ll res = 0;
    for(int msk = 1;msk < (1 << k);msk++){
        ll mult = n;
        int cnt = 0;
        for(int i = 0;i < k;i++){
            if((msk & (1ll << i)) != 0){
                cnt++;
                mult /= primes[i];
            }
        }
        if(cnt % 2 == 1){
            res += mult;
        }else{
            res -= mult;
        }
    }
    cout << res << el;
}