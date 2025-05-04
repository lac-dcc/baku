#include "bits/stdc++.h"
#define ll long long int
#define mod 1000000007
using namespace std;
 
void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
 
void output()
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}
 
string rev(string n) {
	reverse(n.begin(), n.end());
	return n;
}
 
bool palin(string s) {
	for (int i = 0; i < (s.length() / 2) + 1; i++) {
		if (s[i] != s[s.length() - i - 1]) {
			return false;
		}
	}
	return true;
}
 
ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	else {
		gcd(b, a % b);
	}
}
 
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
 
vector<int> seive(int r) {
	bool arr[r + 1];
	vector <int>v;
	memset(arr, false, sizeof(arr));
	for (ll i = 2; i <= r + 1; i++) {
		if (arr[i] == false) {
			for (ll j = i * i; j <= r; j += i) {
				arr[j] = true;
			}
		}
	}
	for (ll i = 2; i <= r; i++) {
		if (arr[i] == false) {
			v.push_back(i);
		}
	}
	return v;
}
bool isprime(ll n) {
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
 
ll prime(ll n) {
	ll i, max = -1;
	while (n % 2 == 0) {
		max = 2;
		n = n / 2;
	}
	for (i = 3; i <= sqrt(n); i = i + 2) {
		while (n % i == 0) {
			max = i;
			n = n / i;
		}
	}
	if (n > 2) {
		max = n;
	}
	return max;
}
 
vector<int> ind(char arr[], int n) {
	vector<int>indices;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'T') {
			indices.push_back(i);
		}
	}
	return indices;
}
 
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
	return (a.second > b.second);
}
 
 
ll bin(ll x, vector<ll>arr, ll r, ll k) {
	ll cnt = 0;
	ll l = 0;
	r = arr.size();
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x) {
			arr.erase(arr.begin() + mid);
			//arr[mid] = 0;
			//sort(arr, arr + r);
			cnt++;
			break;
		}
		else if (x >= arr[mid] - k && x <= arr[mid] + k) {
			arr.erase(arr.begin() + mid);
			//arr[mid] = 0;
			//sort(arr, arr + r);
			cnt++;
			break;
		}
		else if (arr[mid] < x) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	//cout << cnt << " ";
	return cnt;
}
 
int main()
{
	fastio();
 
	ll n, m, k;
	cin >> n >> m >> k;
 
	//ll app[n];
	vector <ll>app;
	for (ll i = 0; i < n; i++) {
		int t;
		cin >> t;
		app.push_back(t);
		//cin >> app[i];
	}
	ll h[m];
	for (ll i = 0; i < m; i++) {
		cin >> h[i];
	}
 
	sort(app.begin(), app.end());
	sort(h, h + m);
	ll cnt = 0;
 
	int i = 0, j = 0;
 
	while (i < m && j < n) {
		if (h[i] >= app[j] - k && h[i] <= app[j] + k) {
			cnt++;
			i++;
			j++;
		}
		else if (h[i] < app[j] - k) {
			i++;
		}
		else {
			j++;
		}
	}
 
	cout << cnt << "\n";
	return 0;
}