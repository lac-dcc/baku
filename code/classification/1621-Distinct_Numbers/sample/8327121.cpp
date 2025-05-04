#include <iostream>
#include <set>
using namespace std;
 
int main () {
    //This is a cses problem
    int n; cin >> n;
    set<int> input;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        input.insert(temp);
    }
    cout << input.size();
}
