#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#define ll long long
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	multiset<ll> tickets;
	vector<ll> customers(m);
	ll inp;
	for(int i = 0; i < n; i++) {
		cin >> inp;
		tickets.insert(inp);
	}
 
	for(int i = 0; i < m; i++) cin >> customers[i];
	
	for(int i = 0; i < m; i++) {
		// Find the number closest to the client's ticket
		// from below
 
		// lower_bound(2)
		// 1, 1, 2, 2, 3, 3, 5, 5
		//      lb    ub
 
		//lower_bound(4)
		//1, 1, 2, 2, 3, 3, 5, 5
		//                 lb  
		
 
		//lower_bound(1)
		//1, 1, 2, 2, 3, 3, 5, 5
		
		//Find the ticket that is at least the customer's offer + 1
		//The lower bound - 1 will be the pointer which will
		//at most cost the customer's offer
		auto it = tickets.lower_bound(customers[i]+1);
		// If no lower bound exists, then there's no ticket available
		// In the case that lower_bound == tickets.end(), 
		// the last element will be the one considered
		if(it == tickets.begin()) {
			cout << -1 << "\n";
		}
		else {
			it--;
			cout << *it << "\n";
			tickets.erase(tickets.find(*it));
		}
	}
	return 0;
}
