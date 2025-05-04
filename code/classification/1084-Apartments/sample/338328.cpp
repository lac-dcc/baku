#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char const *argv[])
{
	int n, m, k;
	
 
	cin >> n >> m >> k;
 
	int a[n], b[m];
 
	for (int i = 0; i < n; ++i)	
		cin >> a[i];
	
	for (int i = 0; i < m; ++i)	
		cin >> b[i];
 
	sort(a, a + n);
	sort(b, b + m);
 
	int a_ptr = 0, b_ptr = 0;
	int c = 0;
 
	while(a_ptr < n && b_ptr < m)
	{		
		if (abs(a[a_ptr]- b[b_ptr]) <= k) a_ptr++, b_ptr++, c++;
		else if (a[a_ptr] + k < b[b_ptr]) a_ptr++;
		else b_ptr++;
	}
	cout << c << "\n";
 
	return 0;
}