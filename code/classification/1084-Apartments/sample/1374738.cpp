#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define CASE(t) ll t; cin>>t; while(t--)
#define for(i, m, n) for(int i=m;i<n;i++)
#define modulo 1000000007
 
void FAST(){ // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int main(){
    FAST();
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for(i,0,n) cin >> a[i];
    for(i,0,m) cin >> b[i];
    
    sort(a, a+n);
    sort(b, b+m);
    
    int x = 0, y=0, ans=0;
    
    while(x<n && y<m){
        if(a[x]+k < b[y]) x++;
        else if(a[x]-k > b[y]) y++;
        else { x++; y++; ans++; } 
    }
    
    cout << ans;
    
    return 0;
}