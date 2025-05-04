#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue> 
 
using namespace std;
 
typedef long long ll;
 
 
// ----- Graph Algorithms ----- //
 
// #1 Counting Rooms - done
/*
struct node {
	int i, j;
};
 
vector<vector<int>> matrix;
vector<vector<int>> colored;
vector<node> nodes;
 
 
void fillNeighs(vector<node>& res, node point, int n, int m) {
	int i = point.i, j = point.j;
 
	if (n == 1 && m == 1) res = {};
	
	else if (n == 1 && m == 2) {
		if (j == 0) res = { {i, j + 1} };
		else if (j == 1) res = { {i, j - 1} };
	}
 
	else if (n == 2 && m == 1) {
		if (i == 0) res = { {i + 1, j} };
		else if (i == 1) res = { {i - 1, j} };
	}
 
	else if (n == 1) {
		if (j == 0) res = { {i, j + 1} };
		else if (j == m - 1) res = { {i, j - 1} };
		else res = { {i, j + 1}, {i, j - 1} };
	}
 
	else if (m == 1) {
		if (i == 0) res = { {i + 1, j} };
		else if (i == n - 1) res = { {i - 1, j} };
		else res = { {i + 1, j}, {i - 1, j} };
	}
 
	else if (i == 0) {
		if (j == 0) res = { {i + 1, j}, {i , j + 1} };
		else if (j == m - 1) res = { {i + 1, j}, {i, j - 1} };
		else res = { {i, j + 1}, {i, j - 1}, {i + 1, j} };
	}
 
	else if (i == n - 1) {
		if (j == 0) res = { {i, j + 1}, {i - 1, j} };
		else if (j == m - 1) res = { {i, j - 1}, {i - 1, j} };
		else res = { {i, j + 1}, {i, j - 1}, {i - 1, j} };
	}
 
	else if (j == 0) {
		res = { {i + 1, j}, {i - 1, j}, {i , j + 1} };
	}
 
	else if (j == m - 1) {
		res = { {i + 1, j}, {i - 1, j}, {i, j - 1} };
	}
 
	else
		res = { {i, j + 1}, {i, j - 1}, {i + 1, j}, {i - 1, j} };
 
	return;
}
 
 
void bfs(node point, int n, int m) {
	queue<node> q;
	
	q.push(point);
	colored[point.i][point.j] = 1;
 
	while ( !q.empty() ) {
		node item = q.front();
		q.pop();
 
		vector<node> neighs;
		fillNeighs(neighs, item, n, m);
 
		for (int i = 0; i < neighs.size(); i++) {
			if (colored[neighs[i].i][neighs[i].j] == 0 && matrix[neighs[i].i][neighs[i].j] == 1) {
				colored[neighs[i].i][neighs[i].j] = 1;
				q.push(neighs[i]);
			}
		}
 
	}
 
	return;
}
 
 
int main() {
	int n, m; 
	cin >> n >> m;
 
	matrix.resize(n, vector<int>(m));
	colored.resize(n, vector<int>(m));
 
	nodes.reserve(n*m);
 
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char elem;
			cin >> elem;
 
			if (elem == '.') {
				matrix[i][j] = 1;
				nodes.push_back({i, j});
			}
			else {
				matrix[i][j] = 0;
			}
 
		}
	}
 
	int res = 0;
	for (int i = 0; i < nodes.size(); i++) {
		if (colored[nodes[i].i][nodes[i].j] == 0) {
			bfs(nodes[i], n, m);
			res++;
		}
	}
 
	cout << res << endl;
 
	return 0;
}
*/
 
 
// #2 Labyrinth
/*
struct node {
	int i, j;
};
 
vector<vector<int>> matrix;
vector<vector<int>> colored;
vector<vector<int>> dist;
 
vector<vector<node>> parents;
 
 
void fillNeighs(vector<node>& res, node point, int n, int m) {
	int i = point.i, j = point.j;
 
	if (n == 1 && m == 1) res = {};
 
	else if (n == 1 && m == 2) {
		if (j == 0) res = { {i, j + 1} };
		else if (j == 1) res = { {i, j - 1} };
	}
 
	else if (n == 2 && m == 1) {
		if (i == 0) res = { {i + 1, j} };
		else if (i == 1) res = { {i - 1, j} };
	}
 
	else if (n == 1) {
		if (j == 0) res = { {i, j + 1} };
		else if (j == m - 1) res = { {i, j - 1} };
		else res = { {i, j + 1}, {i, j - 1} };
	}
 
	else if (m == 1) {
		if (i == 0) res = { {i + 1, j} };
		else if (i == n - 1) res = { {i - 1, j} };
		else res = { {i + 1, j}, {i - 1, j} };
	}
 
	else if (i == 0) {
		if (j == 0) res = { {i + 1, j}, {i , j + 1} };
		else if (j == m - 1) res = { {i + 1, j}, {i, j - 1} };
		else res = { {i, j + 1}, {i, j - 1}, {i + 1, j} };
	}
 
	else if (i == n - 1) {
		if (j == 0) res = { {i, j + 1}, {i - 1, j} };
		else if (j == m - 1) res = { {i, j - 1}, {i - 1, j} };
		else res = { {i, j + 1}, {i, j - 1}, {i - 1, j} };
	}
 
	else if (j == 0) {
		res = { {i + 1, j}, {i - 1, j}, {i , j + 1} };
	}
 
	else if (j == m - 1) {
		res = { {i + 1, j}, {i - 1, j}, {i, j - 1} };
	}
 
	else
		res = { {i, j + 1}, {i, j - 1}, {i + 1, j}, {i - 1, j} };
 
	return;
}
 
 
char printDirection(int i, int j, int parent_i, int parent_j) {
	if (i < parent_i) return 'U';
	if (i > parent_i) return 'D';
	if (j < parent_j) return 'L';
	if (j > parent_j) return 'R';
}
 
 
void bfs(node start, node finish, int n, int m) {
	queue<node> q;
 
	q.push(start);
	colored[start.i][start.j] = 1;
	dist[start.i][start.j] = 0;
 
	while ( !q.empty() ) {
		node point = q.front();
		q.pop();
 
		vector<node> neighs;
		fillNeighs(neighs, point, n, m);
 
		for (int i = 0; i < neighs.size(); i++) {
 
			if (colored[neighs[i].i][neighs[i].j] == 0 &&  matrix[neighs[i].i][neighs[i].j] == 1) {
				
				colored[neighs[i].i][neighs[i].j] = 1;
				dist[neighs[i].i][neighs[i].j] = dist[point.i][point.j] + 1;
				parents[neighs[i].i][neighs[i].j] = {point.i, point.j};
 
				q.push(neighs[i]);
 
				if (neighs[i].i == finish.i && neighs[i].j == finish.j) return;
			}
		}
	}
 
}
 
 
 
int main() {
	int n, m; 
	cin >> n >> m;
 
	matrix.resize(n, vector<int>(m));
	colored.resize(n, vector<int>(m));
	dist.resize(n, vector<int>(m, -1));
	parents.resize(n, vector<node>(m, {-1, -1}));
 
	node start, finish;
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
 
			char elem; cin >> elem;
 
			if (elem == 'A') {
				start = { i, j };
				matrix[i][j] = 1;
			}
			else if (elem == 'B') {
				finish = { i, j };
				matrix[i][j] = 1;
			}
			else if (elem == '.') {
				matrix[i][j] = 1;
			}
			else
				matrix[i][j] = 0;
		}
	}
 
	bfs(start, finish, n, m);
 
	if (colored[finish.i][finish.j] == 0) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		cout << dist[finish.i][finish.j] << endl;
 
		// print the path
		int cur_i = finish.i, cur_j = finish.j;
		
		string res = "";
		while (true) {
 
			res += printDirection(cur_i, cur_j, parents[cur_i][cur_j].i, parents[cur_i][cur_j].j);
 
			if (cur_i == start.i && cur_j == start.j) break;
 
			int cur_i_copy = cur_i, cur_j_copy = cur_j;
 
			cur_i = parents[cur_i_copy][cur_j_copy].i;
			cur_j = parents[cur_i_copy][cur_j_copy].j;
 
		}
		res.erase(res.end() - 1);
		reverse(res.begin(), res.end());
		cout << res << endl;
	}
 
	return 0;
}*/
 
 
// #3 Building Roads
/*
vector<vector<ll>> graph;
vector<ll> colored;
vector<ll> unconnected;
 
 
void dfs(ll start) {
	colored[start] = 1;
 
	for (ll i = 0; i < graph[start].size(); i++) {
		if (colored[ graph[start][i] ] == 0) {
			colored[ graph[start][i] ] = 1;
			dfs( graph[start][i] );
		}
	}
}
 
 
int main() {
	ll n, m; 
	cin >> n >> m;
 
	graph.resize(n);
	colored.resize(n, 0);
	unconnected.reserve(n);
 
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
 
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
 
	ll res = -1;
	for (ll i = 0; i < n; i++) {
		if (colored[i] == 0) {
			dfs(i);
			unconnected.push_back(i);
			res++;
		}
	}
 
	cout << res << endl;
	for (ll i = 1; i < unconnected.size(); i++) {
		cout << unconnected[0] + 1 << " " << unconnected[i] + 1 << endl;
	}
 
	return 0;
}*/
 
 
// #4 Message Route
vector<vector<ll>> graph;
vector<ll> colored;
vector<ll> path;
vector<ll> dist;
 
 
void bfs(int start) {
	queue<int> q;
 
	colored[start] = 1;
	dist[start] = 1;
 
	q.push(start);
 
	while ( !q.empty() ) {
		int point = q.front();
		q.pop();
 
		for (int i = 0; i < graph[point].size(); i++) {
			if (colored[ graph[point][i] ] == 0) {
				colored[graph[point][i]] = 1;
				dist[graph[point][i]] = dist[point] + 1;
				path[graph[point][i]] = point;
 
				q.push(graph[point][i]);
			}
		}
	}
 
}
 
 
int main() {
	int n, m;
	cin >> n >> m;
 
	graph.resize(n);
	colored.resize(n, 0);
	path.resize(n);
	dist.resize(n, 10000000);
 
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
 
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
 
	bfs(0);
 
	if (colored[n - 1] == 0) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
 
	cout << dist[n - 1] << endl;
 
	vector<int> res;
	res.reserve(n);
	int cur_point = n - 1;
	while (cur_point != 0) {
		res.push_back(cur_point+1);
 
		cur_point = path[cur_point];
	}
	
	res.push_back(1);
 
	reverse(res.begin(), res.end());
 
	for (int item : res) cout << item << " ";
 
	return 0;
}
 
 
 
 
// ----- Sorting and Searching ----- //
// #1 Distinct Numbers
/*
int main() {
	long n; cin >> n;
	map<int, int> map;
 
	long count = 0;
	for (long i = 0; i < n; i++) {
		long a; cin >> a;
		if (map[a] == 0) {
			map[a] = 1;
			count++;
		}
	}
 
	cout << count << endl;
 
	return 0;
}
*/
 
 
 
 
 
// ----- Introductory Problems ----- //
 
// #8 Two Sets
/*
int main() {
	int n; cin >> n;
 
	vector<int> set1;
	vector<int> set2;
 
	if (n % 4 == 0) {
		cout << "YES" << endl;
 
		for (int i = 1; i < n - 2; i+=4) {
			set1.push_back(i);
			set1.push_back((i + 3));
 
			set2.push_back((i + 1));
			set2.push_back((i + 2));
		}
 
		cout << set1.size() << endl;
		for (int i = 0; i < set1.size(); i++) {
			cout << set1[i] << " ";
		}
 
 
		cout << endl << set2.size() << endl;
		for (int i = 0; i < set2.size(); i++) {
			cout << set2[i] << " ";
		}
 
 
		return 0;
	}
 
 
	if ((n - 3) % 4 != 0) {
		cout << "NO";
		return 0;
	}
 
	cout << "YES" << endl;
 
	set1.push_back(1);
	set1.push_back(2);
 
	set2.push_back(3);
 
	for (int i = 4; i < n - 2; i+=4) {
		set1.push_back(i);
		set1.push_back((i + 3));
 
		set2.push_back((i + 1));
		set2.push_back((i + 2));
	}
 
	cout << set1.size() << endl;
	for (int i = 0; i < set1.size(); i++) {
		cout << set1[i] << " ";
	}
 
 
	cout << endl << set2.size() << endl;
	for (int i = 0; i < set2.size(); i++) {
		cout << set2[i] << " ";
	}
 
 
	return 0;
}
*/
 
 
// #5 Permutation - done
/*
int main() {
	long n; cin >> n;
 
	if (n == 1) {
		cout << n << endl;
		return 0;
	}
 
	if (n == 2 || n == 3) {
		cout << "NO SOLUTION";
		return 0;
	}
 
	vector<int> res(n);
 
	for (int i = 1; i < n + 1; i++) {
		res[i - 1] = i;
	}
 
	for (int i = 0; i < n - 1; i+=2) {
		int next = res[i + 1];
		res[i + 1] = res[i];
		res[i] = next;
	}
 
	for (int i = 1; i < n - 1; i+=2) {
		int next = res[i + 1];
		res[i + 1] = res[i];
		res[i] = next;
	}
 
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
 
	cout << endl;
 
	return 0;
}
*/
 
 
// #4 Increasing Array - done
/*
int main() {
	long n; cin >> n;
	vector<long> arr(n);
 
	for (long i = 0; i < n; i++) {
		cin >> arr[i];
	}
 
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
 
	long count = 0;
	for (long i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			count += arr[i - 1] - arr[i];
			arr[i] += arr[i - 1] - arr[i];
		}
	}
 
	cout << count << endl;
 
	return 0;
}
*/
 
 
// #3 Repetitions - done
/*
int main() {
	string str;
	cin >> str;
 
	if (str.length() == 1) {
		cout << 1 << endl;
		return 0;
	}
 
	int count = 1, res = 1;
	for (int i = 1; i < str.length(); i++) {
		if (str[i] == str[i - 1]) {
			count++;
		}
		else {
			if (count > res) res = count;
			count = 1;
		}
	}
 
	if (res < count)
		res = count;
 
	cout << res << endl;
 
	return 0;
}
*/
 
 
// #2 Missing number - done
/*
int main() {
	int n; cin >> n;
 
	vector<int> v(n+1, 0);
 
	for (int i = 0; i < n - 1; i++) {
		int a; cin >> a;
		v[a] = 1;
	}
 
	for (int i = 1; i <= n; i++) {
		if (v[i] == 0) {
			cout << i << endl;
			break;
		}
	}
 
 
	return 0;
}
*/
 
 
// #1 Weird Algorithm - done
/*
int main() {
	long long n; cin >> n;
 
	while (true) {
		cout << n << " ";
		if (n == 1) break;
		if (!(n % 2)) n /= 2;
		else n = n * 3 + 1;
	}
 
	system("pause");
	return 0;
}
*/
