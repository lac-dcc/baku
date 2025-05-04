#include <bits/stdc++.h>
 
using namespace std;
 
using ull = unsigned long long;
 
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
 
    int cases; cin >> cases;
    while(cases--){
        ull l, c; cin >> l >> c; 
 
        if(l==c) cout << (l*l) - (l-1) << endl;
 
        else if(c>l){
            // caso coluna impar
            if(c%2) cout << (c*c) - (l-1) << endl; 
            // caso coluna par
            else cout << (c-1) * (c-1) + l << endl;
       } else {
           // caso linha impar 
           if (l%2) cout << (l-1) * (l-1) + c << endl;
           // caso linha par 
           else cout << (l*l) - (c-1) << endl;
       }         
    }
}
