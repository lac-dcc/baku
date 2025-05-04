#include<iostream>
#include<vector>
#include<iomanip>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
#include<math.h>
using namespace std;
 
 
// #define USACO
// #define interactive
 
 
#ifdef _DEBUG
#include "prepc.h"
#ifndef interactive
#include <fstream>
ifstream myFile("girdi.txt");
#define cin myFile
#endif
#else // _DEBUG
#ifdef USACO
#include <fstream>
const string filename = "rental";
ifstream myFile(filename + ".in");
#define cin myFile
ofstream myFile2(filename + ".out");
#define cout myFile2
#endif // USACO
#endif // _DEBUG
 
 
#define ULL unsigned long long int
#define LL long long int
#define FOR(i, a) for(int i = 0; i < a; i++)
#define EACH(i, a) for(auto &i : a)
#define all(a) a.begin(),a.end()
#define CASES(x) while (x--)
LL md = (ULL)(1e9 + 7);
#define endl '\n'
#define len(x) x.size()
#ifdef _DEBUG
#define debug(x) cerr << endl << "line :" << __LINE__ << " " #x << " = " << x << endl;
#else
#define debug(x) ;
#endif
const pair<int, int> yon[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
const pair<int, int> yonat[] = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };
vector<LL> price;
vector<LL> add;
vector<LL> memo;
 
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << setprecision(9);
	int N;
	LL X;
	cin >> N >> X;
	price.resize(N);
	add.resize(N);
	memo.resize(X + 1);
	EACH(i, price)
		cin >> i;
	EACH(i, add)
		cin >> i;
	FOR(i, N) {
		for (int o = X - price[i]; o >= 0; o--) {
			memo[o + price[i]] = max(memo[o + price[i]], memo[o] + add[i]);
		}
	}
	cout << memo[X];
	return 0;
}
