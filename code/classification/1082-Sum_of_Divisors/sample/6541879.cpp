#include <iostream> 
#include <math.h> 
const long long mod = 1000000007LL; 
long long n; 
long long ans = 0LL;
 
long long sum(long long l, long long r) {
  if (l >= r) {
    return 0LL; 
  }
  long long ret = ((long long) (r % mod) * ((r + 1) % mod) / 2) % mod; 
  ret -= ((long long) (l % mod) * ((l + 1) % mod) / 2) % mod;
  (ret += mod) %= mod;
  return ret; 
} 
 
int main () {
  std::cin >> n;
  long long sqrtValue = (long long) std::sqrt(n);  
  for (long long i = 1; i <= sqrtValue; i++) {
    ans += ((long long) i * (n / i)) % mod;
    ans %= mod;   
    ans += ((long long) i * sum(std::max(sqrtValue, n / (i + 1)), n / i)) % mod;
    ans %= mod; 
  }  
  std::cout << ans; 
  return 0; 
}
