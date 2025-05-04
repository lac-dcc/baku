#include <iostream>
 
using namespace std;
 
int main()
{
    int x;
    long long int s=0,a=-1000000000;;
    cin>>x;
    int arr[x];
 
    for(int i=0;i<x;i++){
        cin>>arr[i];
        s+=arr[i];
        if(a<s)
            a=s;
        if(s<0)
            s=0;
 
    }
    cout<<a;
    return 0;
}