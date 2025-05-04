#include<bits/stdc++.h>
using namespace std;
#define ll long long;
int  main()
{
    long long n,x;
    cin>>n;
 
    long long maxi=-1e18;
    long long currsum=0;
    for(int i=0;i<n;i++){
        cin>>x;
        currsum+=x;
        maxi = max(maxi,currsum);
        if(currsum < 0) currsum = 0;
    }
    cout<<maxi;
    return 0;
    
 
}