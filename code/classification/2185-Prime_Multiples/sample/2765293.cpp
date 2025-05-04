#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long int
 
int32_t main() {
    
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin>>n; cin>>k;
        vector<int>arr;  
    for(int i =0; i < k; i++)
    {
        int a; cin>>a; arr.push_back(a);
    }
    int ans = 0;
    int x = pow(2,k) - 1;
        for(int i = 1; i  <= x; i++)
    {
        int prod = 1; int count = 0;
        for(int j = 0; j < arr.size(); j++)
        {
            if(((i>>j)&1)==1)
            {  int p = n/arr[j];
                 if(prod > p)
                 {count = 0; break;}
                else
                prod = prod*arr[j]; count++;
            }
            
        }
        if(count != 0)
        {
        if(count%2 == 0)
        {
            ans  = ans - n/prod;
        }
        else{ans = ans + n/prod;}
        }
    }
    
   cout<<ans<<endl; 
}