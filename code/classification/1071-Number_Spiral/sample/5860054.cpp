//author : Rohanbiswas
#include <bits/stdc++.h>
using namespace std;
 
 
void solve()
{
 
    long long x,y;
    cin>>x>>y;
    long long  m = max(x,y);
    long long p = pow(-1,m);
    cout<< m*(m-1) + 1 + p * (x-y) <<'\n';
 
}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;  cin>>t;  for(int i=1;i<=t;i++)
    {
        solve();
    }
 
    return 0;
}
 