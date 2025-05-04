#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {char c; bool neg = false; while (!isdigit(c = getchar())) if (c == '-') neg = true; x = c - 48; while (isdigit(c = getchar()))x = (x << 3) + (x << 1) + c - 48; if (neg) x = -x;}
template <typename T> inline void print(T x) {if (x < 0) {putchar('-'); print((-x));} else {if (x >= 10) print(x / 10); putchar(x % 10 + 48);}}
template <typename T> inline void write(T x) {print(x); putchar(' ');}
template <typename T> inline void writeln(T x) {print(x); putchar('\n');}
const int mxn = 1e6 + 5;
const long long mod = 1e9 + 7;
long long dp[mxn];
int a[mxn], n, X;
signed main()
{
	read(n); read(X);
	for (int i = 1; i <= n; i++) read(a[i]);
	dp[0] = 1;
	for (int i = 1; i <= X; i++)
		for (int j = 1; j <= n; j++)
			if (i - a[j] >= 0)
			{
 
				dp[i] += dp[i - a[j]];
				if (dp[i] >= mod) dp[i] -= mod;
			}
	print(dp[X]);
}
