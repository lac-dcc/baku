#include<iostream>
#include<stdlib.h>
using namespace std;
typedef long long llu;
int main()
{
    llu n,ans;
    cin>>n;
    llu x,y;
    while (n--)
    {
    
    cin>>x>>y;
    if(x<y){
        if(y%2!=0)
            ans=(y*y)-x+1;
        else
        {
            ans=(y-1)*(y-1)+x;
        }
        cout<<ans<<endl;        
    }
    else
    {
        if(x%2!=0)
        {
            ans=(x-1)*(x-1)+y;
        }
        else
        {
            ans=(x*x)-y+1;
        }
        cout<<ans<<endl;
        
    }
    }   
    return 0;
    
}
