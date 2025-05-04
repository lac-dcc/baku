#include <bits/stdc++.h>
using namespace std;
 
/*
struct Cow {
	int day;
	string cow;
	int change;
};
 
bool comp (Cow c1, Cow c2){
    if (c1.day < c2.day)//it will sort the array by population in decreasing order
        return true;
    return false;
}
*/
 
int main() {
	//freopen("badmilk.in", "r", stdin);
	//freopen("badmilk.out", "w", stdout);
	
	int n;
	cin >> n;
 
	int numbers[n];
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
 
	sort(numbers, numbers+n);
 
 
	int sol = 1;
	for (int i = 1; i < n; i++) {
		if (numbers[i-1] != numbers[i]) sol += 1;
	}
 
	cout << sol;
}
 
 
 
 