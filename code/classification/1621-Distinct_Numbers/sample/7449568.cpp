#include<bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
// bool cmp(pair<int,int>a,pair<int,int>b)
// {
//     if(a.first != b.first)
//     return a.first<b.first;
 
//     return a.second>b.second;
// }
 
// float distance(int x1, int y1, int x2, int y2) 
// { 
    
//     return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0); 
// } 
 
int main()
{
    ll n;cin>>n;
    set<ll>s;
    while(n--)
    {
        int x;cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
 
}
