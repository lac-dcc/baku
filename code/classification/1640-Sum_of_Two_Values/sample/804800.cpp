#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
struct Item {
    int value;
    int index;
};
 
bool CmpItem(Item& i1, Item& i2) {
    return i1.value < i2.value;
}
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, target;
    cin >> n >> target;
 
    vector<Item> digits;
 
    for (int i = 0; i < n; i++) {
 
        Item item;
        cin >> item.value;
        item.index = i + 1;
        digits.push_back(item);
    }
 
    sort(digits.begin(), digits.end(), CmpItem);
    //    
    //    for( int i=0 ; i<digits.size() ; i++){
    //        cout<< digits[i].value << " " << digits[i].index<<endl;
    //    }
 
 
    int len = digits.size();
    int front = 0;
    int tail = len - 1;
    while (front < tail) {
        int sum = digits[front].value + digits[tail].value;
        if (sum == target) {
            cout << digits[front].index << " " << digits[tail].index;
            return 0;
        } else if (sum < target) {
            front++;
        } else {
            tail--;
        }
 
    }
 
    cout << "IMPOSSIBLE";
 
    return 0;
}
