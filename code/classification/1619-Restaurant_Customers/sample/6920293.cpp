#include <bits/stdc++.h>
#define ll long long 
#define li long int
#define ld long double
using namespace std;
const ll mod = 1e9 + 7;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a,b;
    map<int,int> m;
    while(n--)
    {
     cin>>a>>b;
     m[a]++;
     m[b+1]--;
    }
    int max =0,sum=0 ;
   for(auto it = m.begin();it!=m.end();it++)
   {
 
    sum+=it->second;
    if(sum>max)
    {
      max = sum;
    }
   }
    cout<<max<<endl;
    
    return 0;
}
