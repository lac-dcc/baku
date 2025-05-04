#include <iostream>
#include <set>
using namespace std;
int main(){
    int n, s = 0;
    cin >> n;
    set <int> my_set;
    while (n--) {
       int x;
       cin >> x;
       if (!my_set.count(x)) {
           s++;
           my_set.insert(x);
       }
    }
    cout << s << endl;
    return 0;
}
