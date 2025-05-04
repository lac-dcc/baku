#include <bits/stdc++.h>
 
 
using namespace std;
 
 
 
int main(){
    // ios::sync_with_stdio(0);
    // ios::sync_with_stdio(0);
    
    int n, x = 1;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
 
    for (int i = 1; i < n; i++)
    {
        if(vec[i] != vec[i-1]) {
            x++;
        }
    }
    
    cout << x;
    
    
    return 0;
}
