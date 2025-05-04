#define ll long long int
#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;
void solve()
{
	ll r,c;
	cin >> r >> c;
	if(c >= r && c%2!=0)
		cout  << c*c  - r + 1 << "\n";
	else if(c>=r && c%2==0)
		cout << (c-1)*(c-1) + r << "\n";
	else if(r%2==0)
		cout << r*r  - c + 1 << "\n";
	else
		cout << ((r/2)*2)*((r/2)*2) + c << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    int t=1;
    cin >> t;
    while(t--)
    {
     solve();      
    }
    return 0;
}