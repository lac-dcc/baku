#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x; cin >> n >> x;
    map<int,int> m;
    for(int i=0; i<n; ++i){
        int a; cin >> a;
        int r=x-a;
        if(m.count(r)){
            cout << i+1 << " " << m[r]+1 << "\n";
            return 0;
        }
        m[a] = i;
    }
    cout << "IMPOSSIBLE\n";
}