#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	int a[n];
	int count = 0;
	set<int> s;
	for(int i=0; i<n; i++)
	{
		int b;
		cin >> b;
		s.insert(b);
	}
 
	cout << s.size();
}
