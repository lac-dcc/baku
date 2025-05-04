#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<long long int,long long int> mp;
    long long int n;
    cin>>n;
    for (long long int i=0;i<n;i++)
    {
        long long int a;
        cin>>a;
        mp[a]++;
    }
    cout<<mp.size();
}
