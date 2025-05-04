#include <cstdio>
using namespace std;
const int mod = 1e9 + 7;
long long int n, a[21], p;
long long int s = 0;
int k, c;
bool sw;
int pow(int a, int b){
    if(b == 0){
        return 1;
    }
    long long int s = a;
    int p = 0;
    bool o[100001];
    while(b > 1){
        if(b % 2){
            b--;
            o[p] = 1;
        } else {
            b /= 2;
            o[p] = 0;
        }
        p++;
    }
    for(int j = p - 1; j >= 0; j--){
        if(o[j]){
            s *= a;
        } else {
            s *= s;
        }
        s %= mod;
    }
    return s;
}
int main(){
    scanf("%lld%d", &n, &k);
    for(int i = 0; i < k; i++){
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i < (1 << k); i++){
        sw = 1;
        c = 0;
        p = 1;
        for(int j = 0; j < k; j++){
            if((i >> j) & 1){
                c++;
                if(p > (1e18 / a[j])){
                    sw = 0;
                    break;
                } else {
                    p *= a[j];
                }
            }
        }
        if(sw){
            s -= (n / p) * pow(-1, c);
        }
    }
    printf("%lld\n", s);
}