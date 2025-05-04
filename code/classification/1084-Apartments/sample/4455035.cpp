#include <iostream>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
const int N_MAX = 2e5+1;
int n, m;
ll k;
ll a[N_MAX], b[N_MAX];
 
int main() {
	cin >> n >> m >> k;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<m; i++) cin >> b[i];
	sort(a, a+n);
	sort(b, b+m);
	int i = 0, j = 0, cnt = 0;
	while(i < n && j < m) {
		if(abs(a[i]-b[j]) <= k) // satisfield
		{
			cnt++, i++, j++;
		} else if(b[j] < a[i]+k) // apart too small
		{
			j++;
		} else {
			i++;
		}
	}
	cout << cnt << endl;
}
