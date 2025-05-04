#include <iostream>
#include <set>
 
using namespace std;
 
#define ll long long
int main ()
{
// #define int ll
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	set<int>se;
	while (t--)
	{
		int tmp;
		cin >> tmp;
		se.insert(tmp);
	}
	cout << se.size() << '\n';
}
 