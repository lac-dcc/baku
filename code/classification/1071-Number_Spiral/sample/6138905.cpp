#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define all(vr) vr.begin(), vr.end()
#define rall(vr) vr.rbegin(), vr.rend()
#define ll long long
#define int long long
#define ld long double
#define tc int t; cin>>t; while(t--)
#define vi vector<int>
#define superspeed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz(a) ((int)a.size())
#define pb push_back
#define VEC(type, name, size) \
  vector<type> name(size);    \
  for(int i = 0; i < size; i++) cin >> name[i];
const char nl = '\n';
const int maxN = 2e5 + 5;
const int mod = 1e9 + 7;
const int INF = 1e18;
 
 
// adj 8 
int x8[9]={0,1,1,0,-1,-1,-1,0,1};
int y8[9]={0,0,1,1,1,0,-1,-1,-1};
// adj 4
int x4[4]={1,0,-1,0};
int y4[4]={0,1,0,-1};
// adj i = j
int xx[4] = {1,1,-1,-1};
int yy[4] = {1,-1,1,-1};
void yes(bool op, string yes, string no) { cout << (op ? yes : no); }
void file() { freopen("input.txt","r",stdin);freopen("output.txt","w",stdout); }
 
struct DSU
{
	vector<int> sz;
	vector<int> parent;
	DSU (int n)
	{
		parent.resize(n);
		sz.resize(n);
		for (int i = 0; i < n; i++) make_set(i);
	}
	void make_set(int v) {
		parent[v] = v;
		sz[v] = 1;
	}
 
	int find_set(int v) {
		if (v == parent[v])
			return v;
		return find_set(parent[v]);
	}
 
	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
 
		if (a != b) {
			if (sz[a] < sz[b])
				swap(a, b);
			parent[b] = a;
			sz[a] += sz[b];
		}
	}
 
	int size(int x) {
		return sz[find_set(x)];
	}
 
	
};
void sive(vi &prime, int n) {
	prime[1] = 0;
	prime[0] = 0;
	for(int i = 2; i*i <= n*n; i++) {
		if(prime[i]) {
			for(int j = i*i; j * j <= n*n; j += i) {
				prime[j] = 0;
			}
		}
	}
}
int snt(int n) {
	if(n < 2) return 0;
	for(int i = 2; i*i <= n; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}
int toNum(char a, char b) {
	return (a - '0') + (b - '0');
}
void solve() {
	int x,y; cin >> x >> y;
	int re = abs(x-y);
	int num = max(x,y);
	num = num * ( num-1) + 1;
	if(x > y) {
		if(x % 2 == 0) {
			cout << num + re;
		} else cout << num - re;
		
	} else {
		if(y % 2 == 0) {
			cout << num - re;
		} else cout << num + re;
	}
} 
	
 
 
signed main(){
	superspeed
	tc{solve(); cout << nl;}
//	solve();
 
	return 0;
}
