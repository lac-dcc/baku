#include <iostream>
#include <vector>
#define ll long long
#include <iterator>
#include <bits/stdc++.h>
#include <map>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;
// struct c1{ll a;ll b;ll co;};
// bool cmp(c1 a1, c1 b1)
// {   if(a1.a!=b1.a)
//     return a1.a<b1.a;
//     else if(a1.a==b1.a)
//     {return a1.b<b1.b;}
//     else
//      return a1.co<b1.co;
// }
int main()
{   long long n;  cin >> n; long long k = n;
   // vector<struct c1>data;
   vector<pair<long long , pair<long long , long long>>>sd;
    for(long long i=0;i<n;i++)
   {
         ll a , b , c;
         cin>>a>>b>>c;
         sd.push_back({b , {a , c}});
    }
  
    sort(sd.begin() , sd.end());
 
    map<long long  , long long>m;
    m[0] = 0 ;
    long long end , st , cost ;
    long long max_till_now = 0 ;
    for(ll i=0  ; i<n; i++)
    {
        end = sd[i].first , st = sd[i].second.first , cost = sd[i].second.second;
        auto it = m.lower_bound(st);
        // worst case lo it = m.end() ayyidi
        it--;
        max_till_now = max( cost + (*it).second , max_till_now );
        m[end] = max_till_now;
    }
    cout<<max_till_now<<endl;
   
    
    
return 0;}
