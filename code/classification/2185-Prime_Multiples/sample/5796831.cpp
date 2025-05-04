#include<bits/stdc++.h>
#define ll long long
#define fi first
#define ld long double
#define se second
#define pii pair<int,int>
#define pb push_back
#define bit(n,i) (n>>i&1)
#define off_bit(n,i) (n^(1<<i))
using namespace std;
 
const int MOD = 1e9 + 7;
const int N = 1e6 + 1;
const ll INF = 1e15;
const ld eps = 1e-3;
 
ll n,cnt,k,a[22];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i = 0; i < k; i++) cin>>a[i];
    double EPS = log(n) + eps;
    for(int mask = 0; mask < (1<<k); mask++)
    {
        int bits = __builtin_popcount(mask);
        if(bits == 0) continue;
        ll prod = 1;
        double EPS_2 = 0.0;
        for(int i = 0; i < k; i++) if(bit(mask,i)) 
        {
            EPS_2 += log(a[i]);
            prod*=a[i];
        }
        if(EPS_2 < EPS) cnt += (bits&1?1:-1)*n/prod;
    }
    cout<<cnt;
    return 0;
}