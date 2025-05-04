#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x,y,z,i,j,s,k=0,f=0;
    vector <pair<long long int,long long int>> v;
    cin>>n>>z;
    for(i=0;i<n;i++)
    {
        cin>>j;
        v.push_back(make_pair(j,i+1));
    }
    sort(v.begin(),v.end());
    if(v.size() > 3)
    {
    for(x = 0;x < n-3;x++)
    {
      for(y=x+1;y<n-2;y++)
      {
         i=k+2;
         j=v.size()-1;
         s=z-(v[x].first + v[y].first);
         i=y+1;
         j=v.size()-1;
         while(i < j)
         {
           if(s == (v[i].first + v[j].first))
           {
               cout<<v[x].second<<" "<<v[y].second<<" "<<v[i].second<<" "<<v[j].second;
               f=1;
               break;
           }
           else if(s > (v[i].first + v[j].first))
           {
               i++;
           }
           else
           {
               j--;
           }
         }
         if(f == 1)
          break;
        }
        if(f == 1)
          break;
        }
    if(f == 0)
        cout<<"IMPOSSIBLE";
    }
    else
        cout<<"IMPOSSIBLE";
}