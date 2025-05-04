#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <unordered_set>
#include <climits>
#include <utility>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
 
int decision_x[] = { 0, 1, 0, -1 , -1, -1, 1, 1 };
int decision_y[] = { 1, 0, -1, 0 , 1, -1, -1, 1 };
 
 
 
 
int main()
{
 
	cin.tie(0); cin.sync_with_stdio(0);
 
	
	int n;
	cin >> n;
 
	vector<pair<int, int>> v;
 
	int a, b;
 
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a, 1 });
		v.push_back({ b, -1 });
	}
 
	sort(v.begin(), v.end());
 
	int curr = 0, max_people = 0;
 
	for (auto a : v) {
		curr += a.second;
		max_people = max(max_people, curr);
	}
 
	cout << max_people << "\n";
 
	return 0;
 
}
 
