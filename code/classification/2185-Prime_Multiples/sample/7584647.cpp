#include<bits/stdc++.h>
using namespace std;
 
 
class Problem {
public:
    void solve() {
        long long n, k;
        scanf("%lld%lld",&n,&k);
 
        long long a[k];
        for(int i=0; i<k; i++) {
            scanf("%lld",a+i);
        }
 
        long long ans = 0;
        for(int i=1; i<(1<<k); i++) {
            long long gcd = 1, cnt = 0;
            for(int j=0; j<k; j++) {
                if(i&(1<<j)) {
                    cnt += 1;
                    if(n/gcd >= a[j]) {
                        gcd *= a[j];
                    } else {
                        gcd = -1;
                        break;
                    }
                }
            }
 
            // printf("%d %lld %lld\n",i,gcd,cnt);
 
            if(gcd == -1) {
                continue;
            } else {
                if(cnt&1) {
                    ans += n/gcd;
                } else {
                    ans -= n/gcd;
                }
            }
        }
 
        printf("%lld\n",ans);
    }
};
 
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int test_case = 1;
    // scanf("%d",&test_case);
 
    for(int test = 1; test<=test_case; test++) {
        Problem problem;
        problem.solve();
    }
 
    return 0;
}