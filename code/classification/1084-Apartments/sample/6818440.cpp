#include<bits/stdc++.h>
using namespace std;
 
#define long long ll
 
 
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int a[n], b[m];
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int j = 0; j < m; j++)
		cin >> b[j];
		
	sort(a, a+n);
	sort(b, b+m);
	
	int ans = 0;
	
	int i = 0, j = 0;
	
	while(i < n && j < m){
		if(abs(a[i]-b[j]) <= k){
			ans++;
			i++;
			j++;
		}
		
		else if(a[i] > b[j]) j++;
		
		else i++;
	}
	
	cout << ans;
	
}