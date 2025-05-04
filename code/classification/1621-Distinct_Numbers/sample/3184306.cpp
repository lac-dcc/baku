#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n, elem;
vector<int> arr;
 
int main() 
{   
	cin >> n; elem = 0;
	arr.resize(n);
	
	for(int i = 0; i < n; i++)
	    cin >> arr[i];
	
	sort(arr.begin(), arr.end());
	
	for(int i = 1; i < n; i++)
	{
	    if(arr[i] != arr[i-1])
	        elem++;
	}
	elem++;
	
	cout << elem << "\n";
	return 0;
}
