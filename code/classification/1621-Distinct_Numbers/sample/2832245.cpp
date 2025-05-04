#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,x,n,c=0;
    cin>>n;
    vector<int>v(n);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;i++)
    {
        if(v[i]!=v[i-1])
        {
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}
