/*
  Prime Multiples
  Time limit: 1.00 s Memory limit: 512 MB
 
  You are given k distinct prime numbers a1,a2,..,ak and an integer n.
 
  Your task is to calculate how many of the first n positive integers
  are divisible by at least one of the given prime numbers.
 
  Input
 
  The first input line has two integers n and k.
 
  The second line has k prime numbers a1,a2,..,ak.
 
  Output
 
  Print one integer: the number integers within the interval 1,2,..,n
  that are divisible by at least one of the prime numbers.
 
  Constraints
 
  1<=n<=1e18
  1<=k<=20
  2<=ai<=n
 
  Example
 
  Input:
  20 2
  2 5
 
  Output:
  12
 
  Explanation: the 12 numbers are 2,4,5,6,8,10,12,14,15,16,18,20.
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
/* g++ -g -fsanitize=address -lasan -std=c++11 -Dfoo_ */
 
/* freopen("input.txt", "rt", stdin); */
/* freopen("output.txt", "wt", stdout); */
 
#define ALL(c)          (c).begin(), (c).end()
#define ALLR(c)         (c).rbegin(), (c).rend()
#define FOR(i,a,b)      for (int i=(a); i < (b); ++i)
#define FORR(i,a,b)     for (int i=(a); i > (b); --i)
#define FOR_ALL(i,c)    for (__typeof((c).begin()) i=(c).begin();   \
                             i != (c).end(); ++i)
#define FOR_ALLR(i,c)   for (__typeof((c).rbegin()) i=(c).rbegin(); \
                             i != (c).rend(); ++i)
#define SZ(array)       (sizeof(array)/sizeof(array[0]))
#define lc(x)           (x<<1)     /* 2*x */
#define rc(x)           (x<<1 | 1) /* 2*x+1 */
#define lowbit(x)       (x & (-x)) /* 0b10100 -> 0b100 */
 
typedef long long       LL;
typedef map<int,int>    MII;
typedef pair<int,int>   PII;
typedef set<int>        SI;
typedef vector<bool>    VB;
typedef vector<double>  VD;
typedef vector<int>     VI;
typedef vector<string>  VS;
 
/* check if a key is in container C */
template <class C>
inline bool in_(const typename C::key_type& k, const C& A)
{ return A.find(k) != A.end(); }
inline bool in_(const string& s, const string& S)
{ return S.find(s) != string::npos; }
 
int main()
{
#ifdef foo_
    freopen("foo", "rt", stdin);
#endif
    ios::sync_with_stdio(false);
    LL n; int k;
    while (cin >> n >> k) {
        vector<LL> A(k);
        FOR(i,0,k)
            cin >> A[i];
        LL ans = 0;
        FOR(mask,1,(1<<k)) {
            LL lcm = 1; int cnt = 0;
            FOR(i,0,k) if (mask & (1<<i)) {
                if (lcm > n/A[i])
                    lcm = n+1;
                else
                    lcm *= A[i];
                cnt++;
            }
            if (cnt & 1)
                ans += n/lcm;
            else
                ans -= n/lcm;
        }
        cout << ans << endl;
    }
    return 0;
}
