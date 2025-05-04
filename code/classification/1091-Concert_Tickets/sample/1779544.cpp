#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
 
 
using namespace std;
 
multiset<int> h;
 
vector<int> t;
 
 
int main(){
    int n,m,temp;
    cin >> n >> m;
 
    for (int i = 0; i<n;i++){
        cin >> temp;
        h.insert(temp);
    }
    for (int i = 0; i<m;i++){
        cin >> temp;
        auto it = h.upper_bound(temp);
        if(it == h.begin()){
            cout << -1 << "\n";
        }else{
            --it;
            cout << *it << "\n";
            h.erase(it);
        }
    }
 
 
 
}
