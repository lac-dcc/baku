#include <iostream>
#include <set>
#include <algorithm>
#define loop(start,end) for (int i=start;i<end;i++)
using namespace std;
 
typedef long long ll;
 
int main() {
    int n,m,k, count = 0;
    cin>>n>>m>>k;
    ll a[n];
    ll b[m];
    loop(0,n)
    {
        cin>>a[i];
    }
    loop(0,m)
    {
        cin>>b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int i=0,j=0;
    while (i<n and j<m) {
        if (a[i]-k>b[j]) j++;
        else if (a[i]+k<b[j]) i++;
        else
        {
            i++;
            j++;
            count++;
        }
    }
 
 
    cout<<count<<endl;
}
