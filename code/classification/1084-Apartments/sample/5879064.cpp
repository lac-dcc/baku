#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long 
 
 
 
string printValueOfPi(int N)
{
 
    // Find value of pi upto
    // using acos() function
    double pi = 2 * acos(0.0);
 
    // Print value of pi upto
    // N decimal places
    string s1;
    s1=to_string(pi);
    return s1;
    
}
int getSum(int n)
    {
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }
    
 
 
 
 
 
 
int main(){
    
        ll n,m,k;
        cin>>n>>m>>k;
        ll a[n];
        
        ll count=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            
            
        }
        sort(a,a+n);
        ll b[m];
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(b,b+m);
        ll i=0;
        ll j=0;
        while(i<n and j<m){
            if(b[j]<a[i]-k ){
                j++;
            }
            else if(b[j]>a[i]+k){
                i++;
            }
            else{
                count++;
                i++;
                j++;
            }
        }
        cout<<count<<endl;
        
        
        
        
 
        
       
       
       
       
       
       
    
    
 
    
        
        
    
    
    
    
    
    
    
    
    return 0;
}