#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,req,x,f=0;
    cin>>n>>x;
    long long int a[n+1];
    vector<long long int>v;
    map<long long int,long long int>mp;
    //multiset<long long int>ms;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(x%2==0 && a[i]==x/2)
        {
            v.push_back(i);
        }
        //ms.insert(a[i]);
        mp[a[i]]=i;
    }
    if(n==1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    else if(v.size()>=2)
    {
        cout << v[0] << " " << v[1] << endl;
        return 0;
    }
    v.clear();
    for(i=1;i<=n;i++)
    {
        req=x-a[i];
        //v.push_back(i);
        if(mp.find(req)!=mp.end() && mp[req]!=i)
        {
            f++;
            v.push_back(i);
            v.push_back(mp[req]);
            break;
        }
    }
    if(f==1)
    {
        cout << v[0] << " " << v[1] << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
