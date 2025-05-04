#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 0.001;
const int maxK = 20;
 
int K;
ll N, cnt, a[maxK];
 
int main(){
    cin >> N >> K;
    for(int i = 0; i < K; i++)
        cin >> a[i];
 
    cnt = N;
    double RHS = log(N) + EPS;
    for(int m = 0; m < (1<<K); m++){
        bool odd = (__builtin_popcount(m)&1);
 
        ll prod = 1;
        double LHS = 0.0;
        for(int i = 0; i < K; i++){
            if(m&(1<<i)){
                LHS += log(a[i]);
                prod *= a[i];
            }
        }
 
        if(LHS < RHS)
            cnt += (odd ? 1 : -1) * (N/prod);
    }
 
    cout << cnt << endl;
}