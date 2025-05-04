#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).r.end()
 
int IMOD = 1e9+7;
ll LLMOD = 1e18+7;
 
int nxt() {
    int x; cin >> x;
    return x;
}
 
string snxt(){
	string x; cin >> x;
	return x;
}
 
int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a % b);
}
 
int lcm(int a, int b){
	return (a*b)/gcd(a, b);
}
 
void setIO(){
	#ifndef ONLINE_JUDGE
	FILE * stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	#endif
}
 
void solve(){
	int n = nxt();
	vector<int> arr(n);
	vector<int> leav(n);
	for (int i = 0;i < n; i++){
		cin >> arr[i];
		cin >> leav[i];
	}
	sort(all(arr));
	sort(all(leav));
	
	int curr = 0, res = 0;
	int i =0, j = 0;
	while(i < n && j < n){
		if (arr[i] < leav[j]) {
			curr++;
			i++;
		}
		else {
			curr--;
			j++;
		}
		res = max(res, curr);
	}
 
	cout << res << endl;
	
}
 
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	// setIO();
	
	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++){
		//cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}
