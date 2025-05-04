#include <bits/stdc++.h>
using namespace std;
 
int n;
set <int> s;
 
int main(){
    cin >> n; 
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << '\n';
}