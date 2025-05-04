#include<bits/stdc++.h>
using namespace std;
 
#define ar array
#define ll long long
 
const int maxn=2e5;
int n;
array<int, 3> a[maxn];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i][1]>>a[i][0]>>a[i][2];
    }
    sort(a,a+n);
    set<ar<ll,2> >dp;
    dp.insert({0,0});
    ll ldp=0;
    for(int i=0;i<n;i++)
    {
        auto it= dp.lower_bound({a[i][1]});
        --it;
        ldp=max(ldp,(*it)[1]+a[i][2]);
        dp.insert({a[i][0],ldp});
    }
    cout<<ldp<<endl;
}
