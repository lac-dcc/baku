#include <bits/stdc++.h>
 
using namespace std;
const double EPS = 0.001;
const int maxK = 20;
#define ll long long int
int main(){
    ll K, N, cnt;
    ll a[maxK];
    cin>>N>>K;
   
    for(ll i = 0; i < K; i++){
        cin>>a[i];
        }
    cnt = N;
    double r = log(N) + EPS;
    for(ll mask = 0; mask < (1<<K); mask++){
        bool flag = (__builtin_popcount(mask)&1);
 
        ll p = 1;
        double l = 0.0;
        for(ll i = 0; i < K; i++){
            if(mask&(1<<i)){
                l += log(a[i]);
                p *= a[i];
            }
        }
 
        if(l < r)
            cnt += (flag ? 1 : -1) * (N/p);
    }
    cout<<cnt<<endl;
}