#include <bits/stdc++.h>
using namespace std;
 
int n, m, k, x;
 
int main(){
    cin >> n;
    int a[n], d[n];
    for(int i = 0 ;  i < n ; i++) cin >> a[i] >> d[i];
    sort(a, a + n);
    sort(d, d + n);
    int i = 0, j = 0;
    int ans = 0;
    while(i < n) {
        while(i < n && a[i] < d[j]) i++;
        ans = max(ans, i - j);
        j++;
    }
    cout << ans;
}
