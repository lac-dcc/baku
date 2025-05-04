#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "/Users/gaurav/Desktop/cppvscode/debug.h"
#else
#define dbg(...); 
#define debug(...);
//#define crndl;
#endif
 
#define ll long long
 
#define int ll
 
#define read(n) int n; cin>>n;
#define          all(v)              v.begin(), v.end()
#define ll long long
const ll MOD = 1e9+1;
const ll MAX = 1e5 + 13;
#define int ll
#define printArr(arr) for(auto &i: arr){cout<<i<<" ";}cout<<endl;
#define inp(n, v) for(int i = 0; i < n; i++){ int a; cin >> a; v.push_back(a); }
 
vector<bool> Primes(MOD, 1);
int fact[MAX + 1];  
 
int GCD(int a, int b) {
    while(b) {
        int t = a;
        a = b;
        b = t % b;
    }
    return a;
}
 
void sieve_func(int n) {
    Primes[0] = Primes[1] = false;
    for (int i = 2; i <= n; i++) {
        if (Primes[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                Primes[j] = false;
        }
    }
}
 
int power(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) 
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
 
int powerMOD(int a, int b) {
    a %= MOD;
    int res = 1;
    while(b) {
        if(b & 1) 
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
 
int inverse(int n) {
    return power(n, MOD - 2); // Fermet's Little Theorem
}
 
void fac() {
    fact[0] = 1;
    for(int i = 1; i <= MAX; i++) 
        fact[i] = fact[i - 1] * i % MOD;
}
 
int ncr(int n, int r) {
    return fact[n] * inverse(fact[r] * fact[n - r]) % MOD;
}
 
int npr(int n, int r) {
    return fact[n] * inverse(fact[n - r]);
}
 
int lcm(int x,int y){
    int res = x * y / (GCD(x,y));
    return res;
}
 
int log2Bit(int n) {
    int i = 0;
    int ans = -1;
    while(n > 0) {
        if(n & 1) 
            ans = i;
        n = n >> 1;
        i++;
    }
    return ans;
}
 
double sqrtb(double n) {
    double i = 1;
    double j = n;
    while(j - i > 1e-10) {
        double mid = i + (j - i) / 2;
        if(mid * mid <= n) 
            i = mid;
        else 
            j = mid;
    }
    return i;
}
 
//--------------------Code Here-------------------------------//
 
void solve() {
 
    int n, x;
    cin >> n >> x;
 
    vector<int> values(n);
    for (int i = 0; i < n; i++) { cin >> values[i]; }
 
    // use a map to avoid using a very large array
    map<int, int> val_to_ind;
    for (int i = 0; i < n; i++) {
        // target minus a number is the other number
        if (val_to_ind.count(x - values[i])) {
            cout << i + 1 << " " << val_to_ind[x - values[i]] << endl;
            return ;
        }
        val_to_ind[values[i]] = i + 1;
    }
 
    cout << "IMPOSSIBLE" << endl;
 
 
}
 
 
 
//______________________ End .__________________________________//
// Important things.  //
// check you took the right test case
// dont stay on one method or approach for long
// check the value of T below sometimes they don't give it;
// always check if the vector size is defined v(n);
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("/Users/gaurav/Desktop/cppvscode/error.txt", "w", stderr);
    #endif
 
    int T = 1;
    //cin >> T;
    for(int i = 0; i < T; i++) {
        debug(testCase, i + 1);
        solve();
    }
    return 0;
}
