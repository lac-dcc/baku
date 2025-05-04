#include <bits/stdc++.h>
using namespace std;
int main(){
long long n, i, ans;
cin >> n;
long long x[n], y[n+1], z[n];
for(i=0; i<n; i++){
    cin >> x[i];
}
y[0]=0;
ans=x[0];
for(i=1; i<=n; i++){
    y[i]=y[i-1]+x[i-1];
}
z[0]=0;
for(i=1; i<n; i++){
    z[i]=min(z[i-1], y[i]);
}
for(i=n; i>0; i--){
    ans=max(ans, y[i]-z[i-1]);
}
cout << ans;
}
