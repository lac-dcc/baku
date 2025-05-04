#include <bits/stdc++.h>
using namespace std;
#define int long long 
 
int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++){cin>>a[i];}
    int mx = a[0],sm = a[0];
    for(int i = 1;i<n;++i)
    {
        sm = max(sm+a[i], a[i]);
        mx = max(mx,sm);
    }
    cout<<mx;   
// 8 -1 3 -2 5 3 -5 2 2 
 
}
