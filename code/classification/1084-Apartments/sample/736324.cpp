//#include"bits/stdc++.h"
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <random>
#include <cassert>
 
#define ll long long int
 
using namespace std;
 
 
 
 
 
int main()
{
 
    int n,m,k;
    cin>>n>>m>>k;
    
    int a[n],b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
 
    }
    for(int i=0;i<m;i++)
        cin>>b[i];
    
    sort(a,a+n);
    sort(b,b+m);
    
    int ans=0;
    
    for(int i=0,j=0;i<n;i++)
    {
        
        while(j<m && b[j]<-k+a[i])
         ++j;
        if(j<m && b[j]<=k+a[i])
        ans++,j++;
        
            
        
        
        
    }
 
    cout<<ans<<endl;
 
}