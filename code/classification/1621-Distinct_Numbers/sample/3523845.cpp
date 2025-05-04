#include <bits/stdc++.h>
using namespace std;
const int INPUT_SIZE = 1 << 22, OUTPUT_SIZE = 1 << 10; int _i0 = 0, _o0 = 0, fIdx; char _, _n, __[20], _i[INPUT_SIZE], _o[OUTPUT_SIZE], _endChar; bool pEnd = false, ogP;
#define pc(x) _o[_o0++] = x
#define init fread(_i, 1, INPUT_SIZE, stdin)
#define flush fwrite(_o, 1, _o0, stdout)
#define printList(...) pEnd = true, _endChar = ' ', print(__VA_ARGS__), pc('\n'), pEnd = false
#define ll long long
#define nxt _next<int>()
#define next(x) _next<x>()
#define println(x) print(x, '\n')
inline void read(double &), print(double);inline void read(int& x){while((_n=_i[_i0++])<45); x = (_n - 45) ? _n : _i[_i0++]; for (x -= 48; 47 < (_ = _i[_i0++]); x = (x << 3) + (x << 1) + _ - 48); if (_n < 46) x = -x;}inline void read(ll& x){while((_n=_i[_i0++])<45); x = (_n - 45) ? _n : _i[_i0++]; for (x -= 48; 47 < (_ = _i[_i0++]); x = (x << 3) + (x << 1) + _ - 48); if (_n < 46) x = -x;}inline void read(char &x){while (_i[_i0] == ' ' || _i[_i0] == '\n')_i0++; x = _i[_i0++];}inline void read(string &x){while ((_ = _i[_i0]) < 33)_i0++;fIdx = _i0;while ((_ = _i[_i0++]) > 32);x = string(_i + fIdx, _i + _i0 - 1);}inline string nextLine(){while ((_ = _i[_i0]) == '\n')_i0++; fIdx = _i0; while ((_ = _i[_i0++]) != '\n' && _ != 0); return string(_i + fIdx, _i + _i0 - 1);}inline char nextChar(){while (_i[_i0] == ' ' || _i[_i0] == '\n')_i0++;return _i[_i0++];}template <typename T> inline T _next(){T x; read(x); return x;}inline void print(int x){ if (x < 0)pc('-'), x *= -1; _ = 0;do{__[_++] = x % 10;} while (x /= 10); while (_--) pc(__[_] + '0'); if (pEnd) pc(_endChar);}inline void print(ll x){ if (x < 0) pc('-'), x *= -1; _ = 0;do{__[_++] = x % 10;}while (x /= 10);while (_--)pc(__[_] + '0');if (pEnd)pc(_endChar);}inline void print(char c) { pc(c);  if (pEnd) pc(_endChar);}inline void print(string str){ str.copy(_o + _o0, str.length(), 0);_o0 += str.length();  if (pEnd) pc(_endChar);}inline void print (const char *x){print((string)x);}template <typename T, typename... S> void read(T &m, S &...s){ read(m), read(s...);}template <typename T, typename... S> void print(T m, S... s){ print(m), print(s...);}
//End of IO ----------------------------------------------------------------------------------------------------------------//
const int maxN = 0;
 
int main(){
    init;
    set<int> nums;
    int N = nxt;
    while(N--)
        nums.insert(nxt);
    println((int)nums.size());
    flush;
}