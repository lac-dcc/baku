#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x,f=0;
    cin>>n;
    set<long long int>s;
     set<long long int>::iterator it;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        s.insert(x);
    }
    for(it =s.begin(); it!=s.end();it++)
    {
        f++;
    }
    cout<<f;
    return 0;
}
