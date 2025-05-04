#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,x; cin >> n >> x;
    vector<int> vals,svals;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        vals.push_back(a);
    }
    svals = vals;
    sort(svals.begin(),svals.end());
    int f = 0; int s = n-1;
    int s1 = -1; int s2 = -1;
    while(true) {
        if(f == s) break;
        if(svals[f]+svals[s] == x) {
            s1 = svals[f]; 
            s2  = svals[s];
            break;
        }
        if(svals[f]+svals[s] > x) {
            s--;
            continue;
        } 
        f++;
    }
    if(s1 == -1) {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    for(int i = 0; i < n; i++) {
        if(vals[i] == s1) {
            cout << i+1 << " ";
            s1=-1;
            continue;
        }
        if(vals[i] == s2) {
            cout << i+1 << " ";
            s2 = -1;
            continue;
        }
    }
}