#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long ma=INT_MIN,b{};
    for(int i=0,a;i<n;i++)
    {
        cin>>a;
        b+=a;
        ma=max(ma,b);
        b=max(0LL,b);
    }
    cout<<ma;
}