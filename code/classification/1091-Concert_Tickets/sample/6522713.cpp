#include<bits/stdc++.h>
#define ll  long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
// #define mod 1000000007
#include <algorithm>
#include <vector>
#include <iostream>
 
int main()
{
    int n, m;
    cin>>n>>m;
    multiset<int> price;
    int p;
    for(int i=0; i<n; i++)
    {
        cin>>p;
        price.insert(p);
    }
    for(int i=0; i<m; i++)
    {
        cin>>p;
        auto it = price.upper_bound(p);
        if(it == price.begin())
            cout<<"-1"<<endl;
        else
        {
            cout<<*(--it)<<endl;
            price.erase(it);
        }
    }
    return 0;
}
