#include<bits/stdc++.h>
#define int long long
using namespace std;
 
bool comp(pair<int,int> x,pair<int,int> y)
{
    if(x.second==y.second)
    {
        return x.first<y.first;
    }
    return x.second<y.second;
}
 
int32_t main()
{
    
    int n,k;
    cin>>n>>k;
 
    vector<pair<int,int>> movies;
 
    for(int e=0;e<n;e++)
    {
        int a,b;
        cin>>a>>b;
        movies.push_back({a,b});
    }
 
    sort(movies.begin(),movies.end(),comp);
 
    multiset<int> s;
 
    int count=0;
 
    for(int e=0;e<n;e++)
    {
        if(s.size()<k)
        {
            if(s.upper_bound(movies[e].first)!=s.begin())
            {
                s.erase(--s.upper_bound(movies[e].first));
            }
            s.insert(movies[e].second);
            count++;
        }
        else
        {
            if(s.upper_bound(movies[e].first)!=s.begin())
            {
                s.erase(--s.upper_bound(movies[e].first));
                s.insert(movies[e].second);
                count++;
            }
        }
    }
 
    cout<<count;
    
    return 0;
}
