#include <bits/stdc++.h>
 
using namespace std;
long long n[100005],m[100005],kq[100005];
int main ()
	{
		int t;
		cin >> t;
		for (int i=1;i<=t;++i)
			{
				cin >> n[i] >> m[i];
					if (n[i]==m[i] && n[i]==1)
				{
					kq[i] = 1;
				}
			else if (n[i]<m[i])
					{
						if (m[i]%2 == 1)
						{
							kq[i] = m[i]*m[i] -n[i] +1;
						}
						else kq[i] = (m[i]-1)*(m[i]-1) +n[i];
					}
			else 
				{
					if (n[i]%2==0)
						{
							kq[i]= n[i]*n[i] - m[i] +1;
						}
					else kq[i] = (n[i]-1)*(n[i]-1) + m[i];
				}
			}
		for (int i=1;i<=t;++i)
			{	if (i<t)
				cout << kq[i] << endl;
				else cout << kq[i];
			}
	}
