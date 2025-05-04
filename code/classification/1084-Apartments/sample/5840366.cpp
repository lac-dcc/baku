#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,a[200005],b[200005],cnt=0;
int main()
{
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    sort(a,a+n);
    sort(b,b+m);
    int x=0,y=0;
    while(x<n && y<m){
        ll dif=abs(a[x]-b[y]);
        if(dif<=k){
            cnt++;
            x++;
            y++;
        }
        else if(a[x]>b[y]) y++;
        else x++;
    }
    cout << cnt;
}
