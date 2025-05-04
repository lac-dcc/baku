#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define fast ios_base::sync_with_stdio(false); cin.tie(0);
#define endline "\n"
 
int main(){
	fast
	lli n;
	cin >> n;
	lli a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	lli ans = a[0];
	lli sum = a[0];
	for(int i = 1;i < n;i++){
		sum = max(sum+a[i],a[i]);
		ans = max(ans,sum);
	}
	cout << ans << endline;
	return 0;
}
