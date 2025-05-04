#include<iostream>
#include<fstream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <map>
#include <bitset>
#include <iomanip>  
#include <numeric>
#define forn(i, n) for (long long i = 0; i < (n); i++)
#define forx(i,x,n) for (long long i = x; i < (n); i++)
#define form(i, n) for (int i = n-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(a) int(a.size())
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define summ(b,k) int(accumulate(b.begin(), b.begin() + k, 0))
#define ll long long
#define srt(a) sort(a.begin(), a.end());
#define fi first
#define pl pair<long long,long long>
#define se second
#define PI 3.14159265358979323846
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
const ll N = 1e6 + 3;
const ll md = 1e9 + 7;
 
int b[101][N];
 
int main()
{
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	fast_io;
	ll m, i, j, qq, w, r = 0, x, l, R = 0, k, q, n, B, C;
	cin >> n >> x; vl a(n);
	forn(i, n) cin >> a[i];
	forn(i, n + 1) b[i][0] = 1;
	forx(i, 1, x + 1) b[0][i] = 0;
	forx(i, 1, n + 1) {
		forx(j, 1, x + 1) {
			if (j >= a[i - 1]) { b[i][j] = (b[i][j - a[i - 1]] + b[i - 1][j]) % md; }
			else b[i][j] = b[i - 1][j];
 
		}
	}
	cout << b[n][x];
 
 
 
 
 
}
