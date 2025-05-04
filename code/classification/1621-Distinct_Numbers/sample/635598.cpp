#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
 
int main(){
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
 
	int n;
	cin >> n;
	set <int> s;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		s.insert(a);
	}
 
	cout << s.size();
 
 
	
	
 
	return 0;
}
