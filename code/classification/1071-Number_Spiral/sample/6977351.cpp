#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long int t;
    cin>>t;
    while (t--)
    {
        long long int x,y,num = -1;
        cin>>x>>y;
        long long int n = max(x,y);
        if(n == x)
        {
            if(x%2 == 0)
            {
                num = (n*n)-y+1;
            }
            else
            {
                num = (((n-1)*(n-1)) + 1) + y - 1;
            }
        }
        else if (n == y)
        {
            if(y%2 == 0)
            {
                num = (((n-1)*(n-1)) + 1) + x - 1;
            }
            else
            {
                num = (n*n) - x + 1;
            }
        }
        cout<<num<<endl;
    }
    
}
