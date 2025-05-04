#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main()
{
    ll int n;
    cin >> n;
    ll int a[n];
    int i;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        
    }
    int c=1;
    sort(a,a+n);
    
    for(i=1;i<n;i++)
    {
      if(a[i]!=a[i-1])
          c++;
        
    }
    cout << c << endl;
    return 0;
}
