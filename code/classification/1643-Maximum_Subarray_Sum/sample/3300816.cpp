/* Author : VANSH KAPILA */
 
/* "The greatest glory in living lies not in never falling, but in rising every time we fall." -*/
 
#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define int long long
#define ld long double
#define endl "\n";
 
#define f(a,b) for(int i=a;i<b;i++)
#define fr(a,b) for(int i=a;i>b;i--)
 
const int mod = 1000000007;
using namespace std;
 
 
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int test = 1;
	//cin>>test;
	while (test--) {
 
		int n;
		cin >> n;
 
		int arr[n];
		f(0, n)cin >> arr[i];
 
		int sum = -11111111;
		int maxsum = -1111111111111111;
		f(0, n)
		{
			sum = max(sum+arr[i],arr[i]);
			maxsum = max(maxsum,sum);
		}
 
		cout << maxsum << endl;
 
	}
	return 0;
}