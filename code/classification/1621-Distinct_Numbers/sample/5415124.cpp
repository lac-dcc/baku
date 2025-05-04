#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    vector<int> ar(n);
    for(int i=0;i<ar.size();i++)
    {
        cin>>ar[i];
    }
    sort(ar.begin(),ar.end());
    for(int i=0;i<ar.size();i++)
    {
        if(ar[i+1] != ar[i])
            ans++;
    }
    cout<<ans;
    
    return 0;
}