#include <bits/stdc++.h>
using namespace std;
 
#define TASK "CANHO"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
#define ll long long
#define foup(i,a,b) for(int i=(a); i<=(b); i++)
#define fown(i,a,b) for(int i=(a); i>=(b); i--)
#define pb push_back
#define pf push_front
#define pk pop_back
#define pt pop_front
#define el '\n'
const int K=200003, inf=1000000007;
 
int n,m,k;
int a[K],b[K];
 
void read()
{
	cin >> n >> m >> k;
	foup(i,1,n) cin >> a[i];
	foup(i,1,m) cin >> b[i];
}
 
void base()
{
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	int i = 1, j = 1, res = 0;
	while(i <= n && j <= m)
	{
		if(a[i] == b[j])
		{
			res++; i++; j++;
		}
		else if(a[i] > b[j])
		{
			if(b[j] + k >= a[i])
			{
				res++; i++; j++;
			}
			else j++;
		}
		else
		{
			if(b[j] - k <= a[i])
			{
				res++; i++; j++;
			}
			else i++;
		}
	}
	cout << res;
}
 
void hard()
{
 
}
 
int main()
{
	fast
	if(fopen(TASK".INP","r"))
	{
 		freopen (TASK".INP","r",stdin);
		freopen (TASK".OUT","w",stdout);
	}
	read();
	base();
	hard();
	return 0;
}