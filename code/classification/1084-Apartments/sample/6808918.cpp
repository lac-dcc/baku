#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define all(a) a.begin(), a.end()
#define forr(a, k, n) for (long long a = k; a < n; a++)
#define llmin_queue priority_queue<ll, vector<ll>, greater<ll>>
#define min_queue priority_queue<int, vector<int>, greater<int>>
#define Yes cout << "Yes\n";
#define YES cout << "YES\n";
#define No cout << "No\n";
#define NO cout << "NO\n";
#define f first
#define s second
#define endl "\n"
#define debug(x) cout << #x << " is " << x << endl
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double
const int N=1e7+10;
int n, m, k, a[N], b[N], ans;
 
void ak_(){
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	int i = 0, j = 0;
	while (i < n && j < m) {
 
		if (abs(a[i] - b[j]) <= k) {
			++i;
			++j;
			++ans;
		} else {
            if (a[i] - b[j] > k) {
				++j;
			}
 
			else {
				++i;
			}
		}
	}
	cout << ans << "\n";
    }
 
 
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        ak_();
    }
}
