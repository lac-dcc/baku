#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
#define MOD 1000000007
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define ff first
#define ss second
 
using namespace std;
 
 
int main() {
 
	fastio
 
 
	int n , m , k;
	cin >> n >> m >> k;
 
	int a[n + 1];
	for (int i = 1; i <= n ; i++)cin >> a[i];
 
	int b[m + 1];
	for (int i = 1; i <= m ; i++)cin >> b[i];
 
	sort(a + 1, a + n + 1);
	sort(b + 1 , b + m + 1);
 
	int i = 1 , j = 1;
	int ans = 0;
	while (i <= n && j <= m) {
 
		if (a[i] + k >= b[j] && a[i] - k <= b[j]) {
			ans++;
			i++ ; j++;
		} else if (b[j] > a[i] + k)i++;
		else if (b[j] < a[i] - k)j++;
 
	}
	cout << ans;
 
	return 0;
}