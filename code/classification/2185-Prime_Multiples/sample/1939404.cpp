#include <bits/stdc++.h>
 
using namespace std;
 
void generate(int k, vector<long long>& s, vector<long long>& primes, vector<vector<long long>>& result) {
    if (k == primes.size()) {
        long long mul = 1;
        vector<long long> tmpR;
        for (long long i : s)
            tmpR.push_back(i);
        if (tmpR.size() > 0)
            result.push_back(tmpR);
    } else {
        s.push_back(primes[k]);
        generate(k + 1, s, primes, result);
        s.pop_back();
        generate(k + 1, s, primes, result);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    long long n, k;
    cin >> n >> k;
 
    vector<long long> primes;
    for (int i = 0; i < k; i ++) {
        long long prime;
        cin >> prime;
        primes.push_back(prime);
    }
    sort(primes.begin(), primes.end());
    vector<long long> s;
    // vector<long long> res;
    vector<vector<long long>> res;
    generate(0, s, primes, res);
 
    long long cnt = 0;
 
    for (int i = 0; i < res.size(); i ++) {
        if (res[i].size() % 2 == 1) {
            long long mul = 1;
            bool f = false;
            for (long long ii : res[i]) {
                __int128_t a = mul;
                __int128_t b = ii;
                __int128_t c = a * b;
                
                
                if (c > LONG_LONG_MAX) {
                    f = true;
                    break;
                }
                mul *= ii;
            }
            if (!f)
                cnt += n / mul;
        } else {
            long long mul = 1;
            bool f = false;
            for (long long ii : res[i]) {
                __int128_t a = mul;
                __int128_t b = ii;
                __int128_t c = a * b;
                
                
                if (c > LONG_LONG_MAX) {
                        f = true;
                    break;
                }
                mul *= ii;
            }
            if (!f)
                cnt -= n / mul;
        }
    }
 
    cout << cnt;
    return 0;
}