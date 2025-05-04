#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <bitset>
#include <iomanip>
#include <string>
#include <numeric>
#include <stdio.h>
#include <typeinfo>
#include <iterator>
#include <random>
using namespace std;
 
//random_shuffle(v.begin(),v.end()); перемешка
 
#define ve vector
#define F first
#define endl '\n'
#define S second
#define PB push_back
#define MP make_pair
#define EN cout << '\n';
typedef vector<long long> vl;
typedef vector<int> vi;
typedef pair<long long, long long> pl;
typedef pair<int, int> pi;
typedef long long ll;
 
const double PI = acos(-1.0);
 
bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) return (a.first < b.first);
	return (a.second < b.second);
}
 
int main()
{
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	const int IN = 9999999;
	long long mi = 1e12, ma = -1e12,mi1;
	long long a, b, c, d, n, ex, m, k, sum = 0, no = 0, s = 0, tt, mod = 1e9 + 7,x,y,p,u;
	char ch;
	string C;
	vl B(2000000,IN), A;
	set<ll> St;
	cin >> n>> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> tt;
		A.push_back(tt);
	}
	B[0] = 0;
	for (int i = 1; i <= x; i++)
	{
		for (auto e : A)
		{
			if (i - e >= 0)B[i] =min(B[i - e] + 1,B[i]);
		}
	}
	if (B[x] < IN) cout << B[x];
	else cout << -1;
	
}
