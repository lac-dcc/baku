#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	vector<int> arrival(n);
	vector<int> departure(n);
 
	for (int i=0; i<n; i++) {
		cin >> arrival[i] >> departure[i];
	}
 
	sort(arrival.begin(), arrival.end());
	sort(departure.begin(), departure.end());
 
 
	int i = 0;
	int j = 0;
	int customers = 0;
	int max_customers = 0;
 
	while (i < n && j < n) {
		if (arrival[i] < departure[j]) {
			customers++;
			i++;
		} else {
			customers--;
			j++;
		}
		max_customers = max(max_customers, customers);
	}
 
	cout << max_customers << '\n';
}
