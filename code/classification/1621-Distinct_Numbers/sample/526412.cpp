#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vl vector<ll>
#define all(x) x.begin(),x.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repll(i, a, b) for(ll i = a; i < b; i++)
 
int main() {
	int n;
	cin >> n;
	set<int> st;
	rep(i, 0, n) {
		int x;
		cin >> x;
		st.insert(x);
	}
 
	cout << st.size() << "\n";
 
	return 0;
}