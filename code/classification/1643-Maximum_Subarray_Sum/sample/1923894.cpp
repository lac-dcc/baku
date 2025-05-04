#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define MOD 1000000007
 
/* ______________________RADIX SORT_______________________
// C++ implementation of Radix Sort
 
// A utility function to get maximum value in arr[]
int getMax(int arr[], int n){
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp){
	int output[n]; // output array
	int i, count[10] = { 0 };
 
	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
 
	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
 
	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
 
	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n){
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);
 
	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}
 
// A utility function to print an array
void print(int arr[], int n){
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
 
*/
 
int n;
int prefix[200005];
int dp[200005];
int a[200005];
 
void solve(){
	cin >> n;
	int cnt = 0;
	int res1 = (-1) * MOD;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		res1 = max(res1, a[i]);
		if(a[i] < 0) cnt++;
		prefix[i] = prefix[i - 1] + a[i]; 
		if(prefix[i] < 0) prefix[i] = 0;
	}
	if(cnt == n) cout << res1;
	else{
		int res = 0;
		for(int i = 1; i <= n; i++){
			res = max(res, max(a[i], prefix[i]));
		}
		cout << res;
	}
}
 
signed main(){
	//freopen(".inp", "r", stdin);
	//freopen(".out", "w", stdout);
 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
	return 0;
}
 