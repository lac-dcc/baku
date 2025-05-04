// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int a, b, x, y, cv;
	// a = Anzahl Zahlen, b = Zielzahl, x = Pointer 1, y = Pointer 2, cv = current value
	cin >> a >> b;
	pair<int,int> values [a];
	for (int i = 0; i < a; i++){
		cin >> values[i].first;
		values[i].second = i+1;
	}
	sort(values, values+a);
	x = 0;
	y = a-1;
	cv = 0;
	while (x != y){
		cv = values[x].first + values[y].first;
		if (cv < b){
			x = x+1;
		}else if (cv > b){
			y = y-1;
		}else if (cv == b){
			if (values[x].second < values[y].second){
				cout << values[x].second << " " << values[y].second;
			}else if (values[x].second > values[y].second){
				cout << values[y].second << " " << values[x].second;
			}
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
