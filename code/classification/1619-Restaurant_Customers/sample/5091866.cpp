#include <bits/stdc++.h>
using namespace std;
 
int main (){
    int n, a, b;
    cin >> n;
    map <int, int> m;
    map <int, int>::iterator itr;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        m[a]++;
        m[b]--;
    }
    int cnt = 0, max = 0;
    for(itr = m.begin(); itr != m.end(); itr++){
        cnt += itr -> second;
        if(cnt>max) max = cnt;
    }
    cout << max << endl;
    return 0;
}
