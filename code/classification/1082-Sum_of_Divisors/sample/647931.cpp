# 1 "sum-of-divisors.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "sum-of-divisors.cpp"
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 1
       
# 12 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/bits/stdc++.h" 1
 #include <bits/stdc++.h>
# 13 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/assoc_container.hpp" 1
 #include <ext/pb_ds/assoc_container.hpp>
# 14 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/tree_policy.hpp" 1
 #include <ext/pb_ds/tree_policy.hpp>
# 15 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
 
 
 
 
 
 
 
using namespace std;
using namespace __gnu_pbds;
 
using ii = pair<int64_t, int64_t>;
using vi = vector<int64_t>;
using vd = vector<long double>;
using vb = vector<bool>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vvd = vector<vd>;
using vvb = vector<vb>;
using vvii = vector<vii>;
# 2 "sum-of-divisors.cpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/number-theory/modular-arithmetic/divisor.hpp" 1
       
 
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/number-theory/modular-arithmetic/operation.hpp" 1
       
 
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/number-theory/euclid.hpp" 1
       
 
 
/**
 * Euclidean GCD.
 *
 * Computes the greatest commom divisor of
 * two integers.
 *
 * Time Complexity: O(log(min(a, b))).
 * Space Complexity: O(1).
 */
uint64_t gcd(uint64_t a, uint64_t b){
    while(a != 0){
        swap(a, b);
        a %= b;
    }
    return b;
}
 
/**
 * Extended Euclidean GCD.
 *
 * Besides computing the GCD it also returns
 * the roots of a*x + b*y = gcd(a, b).
 *
 * Time Complexity: O(log(min(a, b))).
 * Space Complexity: O(1).
 */
tuple<uint64_t, int64_t, int64_t> extended_gcd(uint64_t a, uint64_t b){
    int64_t x = 0, y = 1, x1 = 1, y1 = 0;
    while(a != 0){
        uint64_t q = b/a;
        tie(x, x1) = make_tuple(x1, x - q*x1);
        tie(y, y1) = make_tuple(y1, y - q*y1);
        tie(a, b) = make_tuple(b%a, a);
    }
    return make_tuple(b, x, y);
}
 
/**
 * Euclidean Derivated LCM.
 *
 * Time Complexity: O(log(min(a, b))).
 * Space Complexity: O(1).
 */
uint64_t lcm(const uint64_t a, const uint64_t b){
    // same as a*b/gcd(a, b) but avoiding overflow.
    return a/gcd(a, b)*b;
}
# 4 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/number-theory/modular-arithmetic/operation.hpp" 2
 
/**
 * Modulus.
 *
 * Computes the positive result of a%m.
 *
 * Time Complexity: O(1).
 * Space Complexity: O(1).
 */
template<typename T,
typename enable_if<is_integral<T>::value, uint64_t>::type = 0>
uint64_t mod(const T a, const uint64_t m = ((int64_t)1e9+7)){
    assert(m > 0);
    if(a >= 0)
        return ((uint64_t)a < m? a : (uint64_t)a%m);
    uint64_t abs_a = (-(uint64_t)a)%m;
    return (abs_a == 0? 0 : m - abs_a);
}
 
/**
 * Modular Addition.
 *
 * Computes (a+b)%m.
 *
 * Time Complexity: O(1).
 * Space Complexity: O(1).
 */
template<typename T1, typename T2,
typename enable_if<is_integral<T1>::value and is_integral<T2>::value, uint64_t>::type = 0>
uint64_t modadd(const T1 a, const T2 b, const uint64_t m = ((int64_t)1e9+7)){
    assert(m > 0);
    uint64_t mod_a = mod(a, m), mod_b = mod(b, m);
    if(mod_b >= m - mod_a)
        return mod_b - (m - mod_a);
    return mod_a + mod_b;
}
 
/**
 * Modular Subtraction.
 *
 * Computes (a-b)%m.
 *
 * Time Complexity: O(1).
 * Space Complexity: O(1).
 */
template<typename T1, typename T2,
typename enable_if<is_integral<T1>::value and is_integral<T2>::value, uint64_t>::type = 0>
uint64_t modsub(const T1 a, const T2 b, const uint64_t m = ((int64_t)1e9+7)){
    assert(m > 0);
    uint64_t mod_a = mod(a, m), mod_b = mod(b, m);
    if(mod_b > mod_a)
        return m - (mod_b - mod_a);
    return mod_a - mod_b;
}
 
/**
 * Modular Multiplication.
 *
 * Computes a*b%m.
 *
 * Note: if __uint128_t is not present,
 * mod_a*mod_b may cause overflow before
 * applying % if the multiplication result
 * >= pow(2, 64).
 *
 * Time Complexity: O(1).
 * Space Complexity: O(1).
 */
template<typename T1, typename T2,
typename enable_if<is_integral<T1>::value and is_integral<T2>::value, uint64_t>::type = 0>
uint64_t modmul(const T1 a, const T2 b, const uint64_t m = ((int64_t)1e9+7)){
    assert(m > 0);
    uint64_t mod_a = mod(a, m), mod_b = mod(b, m);
 
        return (__uint128_t)mod_a*mod_b%m;
 
 
 
}
 
/**
 * Modular Multiplicative Inverse.
 *
 * Computes the modular multiplicative
 * inverse of a with mod m.
 *
 * Time Complexity: O(log(mod(a, m))).
 * Space Complexity: O(1).
 */
template<typename T,
typename enable_if<is_integral<T>::value, uint64_t>::type = 0>
uint64_t modinv(const T a, const uint64_t m = ((int64_t)1e9+7)){
    assert(m > 0);
    auto aux = extended_gcd(mod(a, m), m);
    assert(get<0>(aux) == 1); // mod(a, m) and m must be coprimes.
    return mod(get<1>(aux), m);
}
 
/**
 * Modular Division.
 *
 * Computes a/b%m.
 *
 * Time Complexity: O(log(mod(b, m))).
 * Space Complexity: O(1).
 */
template<typename T1, typename T2,
typename enable_if<is_integral<T1>::value and is_integral<T2>::value, uint64_t>::type = 0>
uint64_t moddiv(const T1 a, const T2 b, const uint64_t m = ((int64_t)1e9+7)){
    assert(m > 0);
    return modmul(a, modinv(b, m), m);
}
 
/**
 * Modular Binary Exponentiation.
 *
 * Computes pow(b, e)%m.
 *
 * Time Complexity: O(log(e)).
 * Space Complexity: O(1).
 */
template<typename T,
typename enable_if<is_integral<T>::value, uint64_t>::type = 0>
uint64_t modexp(const T b, uint64_t e, const uint64_t m = ((int64_t)1e9+7)){
    assert(m > 0);
    uint64_t mod_b = mod(b, m), res = 1;
    for(; e > 0; e >>= 1){
        if(e & 1)
            res = modmul(res, mod_b, m);
        mod_b = modmul(mod_b, mod_b, m);
    }
    return res;
}
# 4 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/number-theory/modular-arithmetic/divisor.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/number-theory/modular-arithmetic/progression.hpp" 1
       
 
 
 
/**
 * Modular Sum of Arithmetic Progression.
 *
 * Computes the sum of an arithmetic
 * progression of size n, mod m.
 *
 * Time Complexity: O(1).
 * Space Complexity: O(1).
 */
uint64_t modsum_ap(const int64_t a, const int64_t d, const uint64_t n, const uint64_t m = ((int64_t)1e9+7)){
    assert(n > 0 and m > 0);
    return moddiv(modmul(modadd(modmul(2, a, m), modmul(d, n-1, m), m), n, m), 2, m);
}
 
/**
 * Modular Sum of Geometric Progression.
 *
 * Computes the sum of a geometric
 * progression of size n, mod m.
 *
 * Time Complexity: O(log(n) + log(m)).
 * Space Complexity: O(1).
 */
uint64_t modsum_gp(const int64_t a, const int64_t r, const uint64_t n, const uint64_t m = ((int64_t)1e9+7)){
    assert(n > 0 and m > 0);
    if(r == 1)
        return modmul(a, n, m);
    return moddiv(modmul(a, modsub(1, modexp(r, n, m), m), m), 1 - r, m);
}
# 5 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/number-theory/modular-arithmetic/divisor.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/number-theory/prime-number/wheel.hpp" 1
       
 
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/number-theory/prime-number/miller-rabin.hpp" 1
       
 
 
/**
 * Modular Multiplication.
 *
 * Computes a*b%m.
 *
 * Note: if __uint128_t is present, the time
 * complexity is actually O(1).
 *
 * Time Complexity: O(log(mod(b, m))).
 * Space Complexity: O(1).
 */
static uint64_t modmul(const uint64_t a, const uint64_t b, const uint64_t m = ((int64_t)1e9+7)){
    assert(m > 0);
    uint64_t mod_a = a%m, mod_b = b%m;
 
        return (__uint128_t)mod_a*mod_b%m;
# 30 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/number-theory/prime-number/miller-rabin.hpp"
}
 
/**
 * Modular Binary Exponentiation.
 *
 * Computes pow(b, e)%m.
 *
 * Note: if __uint128_t is present, the time
 * complexity is actually O(log(e)).
 *
 * Time Complexity: O(log(e)*log(m)).
 * Space Complexity: O(1).
 */
static uint64_t modexp(const uint64_t b, uint64_t e, const uint64_t m = ((int64_t)1e9+7)){
    assert(m > 0);
    uint64_t mod_b = b%m, res = 1;
    for(; e > 0; e >>= 1){
        if(e & 1)
            res = modmul(res, mod_b, m);
        mod_b = modmul(mod_b, mod_b, m);
    }
    return res;
}
 
/**
 * Miller-Rabin Deterministic Primality Test.
 *
 * Returns true when x is prime, false
 * otherwise.
 *
 * Note: if __uint128_t is present, the time
 * complexity is actually O(pow(log(x), 2)).
 *
 * Time Complexity: O(pow(log(x), 3)).
 * Space Complexity: O(1).
 */
bool is_prime(const uint64_t x){
    assert(x >= 0);
    if(x < 2)
        return false;
 
    uint64_t r = 0, d = x - 1;
    for(; (d & 1) == 0; d >>= 1)
        r++;
 
    for(uint64_t i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(x == i)
            return true;
 
        uint64_t v = modexp(i, d, x);
        if(v == 1 or v == x - 1)
            continue;
 
        bool check = true;
        for(uint64_t j = 1; j < r and check; ++j){
            v = modmul(v, v, x);
            if(v == x - 1)
                check = false;
        }
        if(check)
            return false;
    }
    return true;
}
# 4 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/number-theory/prime-number/wheel.hpp" 2
 
/**
 * Wheel Prime Factorization.
 *
 * Computes the prime factorization of x.
 *
 * Time Complexity: O(sqrt(x)).
 * Space Complexity: O(log(x)).
 */
vector<pair<uint64_t, uint64_t> > factorization(uint64_t x){
    assert(x > 0);
    vector<pair<uint64_t, uint64_t> > factors;
    for(uint64_t p : {2, 3, 5}){
        while(x%p == 0){
            if(factors.empty() or factors.back().first != p)
                factors.emplace_back(p, 1);
            else
                factors.back().second++;
            x /= p;
        }
    }
    vector<uint64_t> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    for(uint64_t p = 7, i = 0; p*p <= x; p += increments[i++], i %= 8){
        while(x%p == 0){
            if(factors.empty() or factors.back().first != p)
                factors.emplace_back(p, 1);
            else
                factors.back().second++;
            x /= p;
        }
    }
    if(x > 1) // x is prime.
        factors.emplace_back(x, 1);
    return factors;
}
 
/**
 * Count of Prime Factors.
 *
 * Counts the number of prime factors of x.
 *
 * Note: if __uint128_t is present, the time
 * complexity is actually O(cbrt(x) + pow(log(x), 2)).
 *
 * Time Complexity: O(cbrt(x) + pow(log(x), 3)).
 * Space Complexity: O(1).
 */
uint64_t count_prime_factors(uint64_t x){
    assert(x > 0);
 
    uint64_t res = 1;
    for(uint64_t p : {2, 3, 5}){
        if(p*p*p > x)
            break;
        for(; x%p == 0; x /= p)
            res++;
    }
 
    vector<uint64_t> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    for(uint64_t p = 7, i = 0; p*p*p <= x; p += increments[i++], i %= 8){
        for(; x%p == 0; x /= p)
            res++;
    }
    if(x == 1)
        return res;
 
    if(is_prime(x)) // x is prime.
        res++;
    else // sqrt(x) is prime or x is multiple of two other primes.
        res += 2;
    return res;
}
 
/**
 Count of Prime Factors.
 *
 * Counts the number of prime factors of x,
 * given its prime factorization.
 *
 * Time Complexity: O(log(x)).
 * Space Complexity: O(1).
 */
uint64_t count_prime_factors(const vector<pair<uint64_t, uint64_t> > &factors){
    uint64_t res = 0;
    for(auto f : factors)
        res += f.second;
    return res;
}
# 6 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/number-theory/modular-arithmetic/divisor.hpp" 2
 
/**
 * Sum of Divisors.
 *
 * Computes the sum of divisors of x, mod m.
 *
 * Time Complexity: O(sqrt(x) + log(x)*(log(x) + log(m))).
 * Space Complexity: O(log(x)).
 */
uint64_t modsum_divisors(const uint64_t x, const uint64_t m = ((int64_t)1e9+7)){
    assert(x > 0 and m > 0);
    uint64_t res = 1;
    for(auto f : factorization(x))
        res = modmul(res, modsum_gp(1, f.first, f.second+1, m), m);
    return res;
}
 
/**
 * Range Sum of Divisors.
 *
 * Computes the sum of the sum of divisors
 * for each integer in [1, n], mod M.
 *
 * Time Complexity: O(sqrt(n)).
 * Space Complexity: O(1).
 */
uint64_t modrange_sum_divisors(const uint64_t n, const uint64_t m = ((int64_t)1e9+7)){
    assert(n > 0 and m > 0);
    uint64_t ans = 0;
    for(uint64_t d = 1; d*d <= n; ++d){
        uint64_t l = n/(d+1) + 1, r = n/d;
        ans = modadd(ans, modmul(d, modsum_ap(l, 1, r - l + 1, m), m), m);
        if(d != n/d)
            ans = modadd(ans, modmul(n/d, d, m), m);
    }
    return ans;
}
 
/**
 * Range Sum of Divisors.
 *
 * Computes the sum of the sum of divisors
 * for each integer in [l, r], mod M.
 *
 * Time Complexity: O(sqrt(l) + sqrt(r)).
 * Space Complexity: O(1).
 */
uint64_t modrange_sum_divisors(const uint64_t l, const uint64_t r, const uint64_t m){
    assert(l > 0 and l <= r and m > 0);
    int64_t ans = modrange_sum_divisors(r, m);
    if(l > 1)
        ans = modsub(ans, modrange_sum_divisors(l-1, m), m);
    return ans;
}
# 3 "sum-of-divisors.cpp" 2
 
int32_t main(){
    // https://cses.fi/problemset/task/1082
    (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL));
    int64_t n;
    cin >> n;
    cout << modrange_sum_divisors(n) << "\n";
    return 0;
}
