#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct sum{
    ll sum2;
    int start,end;
};
ll a[1001];
sum ans[1002001];
bool different(sum s1,sum s2){
    return !(s1.start==s2.start || s1.start==s2.end || s1.end==s2.start || s1.end==s2.end);
}
int main()
{
    int n; cin>>n;
    ll x; cin>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n<4) {cout<<"IMPOSSIBLE"; return 0;}
    int idx=1;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
        {
            ans[idx].sum2=a[i]+a[j];
            ans[idx].start=i;
            ans[idx].end=j;
            idx++;
        }
    sort(ans+1,ans+1+n*(n-1)/2,[](sum s1,sum s2){return s1.sum2<s2.sum2;});
    int i=1,j=n*(n-1)/2;
    while (i<=n*(n-1)/2 && j>0) {
        if (ans[i].sum2+ans[j].sum2==x && different(ans[i],ans[j])) {
            cout<<ans[i].start<<" "<<ans[i].end<<" "<<ans[j].start<<" "<<ans[j].end;
            return 0;
        }
        else if (ans[i].sum2+ans[j].sum2>x) j--;
        else i++;
    }
    cout<<"IMPOSSIBLE";
}
