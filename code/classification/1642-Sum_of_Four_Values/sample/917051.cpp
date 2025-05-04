#include <bits/stdc++.h>
#define super ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
void findFourElements(int arr[], int n, int X)
{
	map<int, pair<int, int> > mp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			mp[arr[i] + arr[j]] = { i, j };
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];
			if (mp.find(X - sum) != mp.end()) {
				pair<int, int> p = mp[X - sum];
				if (p.first != i && p.first != j
					&& p.second != i && p.second != j) {
					cout <<i+1 <<" "
						<<j+1 << " "
						<< p.first+1 << " "
						<< p.second+1;
					return;
				}
			}
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
	return;
}
int main()
{
	super
	int n,x;
	cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(n<=3)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
	findFourElements(arr, n, x);
	return 0;
}