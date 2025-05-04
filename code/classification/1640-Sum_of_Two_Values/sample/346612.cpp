#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
int main() {
	int n, target;
	cin >> n >> target;
	
	map<int, int> numToIndex;
	map<int, int>::iterator it;
	vector<int> numbers;
 
	for (int i = 0; i < n; i++) {
		int numb;
		cin >> numb;
 
		it = numToIndex.find(numb);
		
		if (it != numToIndex.end()) {
			numToIndex.at(numb) = i;
		}
 
		numbers.push_back(numb);
		numToIndex.insert(pair<int, int>(numb, i));
	}
	
	map<int, int>::iterator myIt;
	bool found = false;
	int count = 0;
 
	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter) {
		int numb = *iter;
		int index = count;
		int search = target - numb;
 
		if (search > 0) {
			myIt = numToIndex.find(search);
 
			if (myIt != numToIndex.end()) {
				if (index != myIt->second) {
					cout << index + 1 << " " << myIt->second + 1;
					found = true;
					break;
				}
			}
		}
 
		count++;
	}
 
	if (!found) {
		cout << "IMPOSSIBLE" << endl;
	}
	
}
