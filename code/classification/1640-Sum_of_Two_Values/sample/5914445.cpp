#include <iostream>
#include <map>
 
using namespace std;
 
int main() {
    int n, s, i_ans, j_ans ;
    bool flag = false ;
    cin >> n >> s;
    int arr [n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    map<int, int> index ;
    for (int i=0; i<n; i++){
        if (index.count(s-arr[i])) {
            i_ans = i ;
            j_ans = index[s-arr[i]] ;
            flag = true;
            break;
        }
        index[arr[i]] = i ;
    }
    if (flag)
        cout << j_ans + 1  << " " << i_ans + 1;
    else cout << "IMPOSSIBLE" ;
}