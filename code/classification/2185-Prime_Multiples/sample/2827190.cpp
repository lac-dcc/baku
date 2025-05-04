#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, ans = 0;
    int k;
    cin>>n>>k;
    ll a[k];
    for(int i = 0; i < k; i++){
        cin>>a[i];
    }
    for(int i = 1; i < 1<<k; i++){
        int m = i, b = 0, j, q;
        ll p = 1;
        for(j = 0; j < k; j++){
            q = m%2;
            if(q == 1){
                b++;
                if(a[j] <= n/p){
                    p *= a[j];
                }
                else{
                    break;
                }
            }
            m = m/2;
        }
        if(j == k){
            if(b%2 == 1){
                ans += n/p;
            }
            else{
                ans -= n/p;
            }
        }
    }
    cout<<ans<<endl;
}
