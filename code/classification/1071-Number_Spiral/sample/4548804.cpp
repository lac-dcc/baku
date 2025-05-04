// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser
 
#include<bits/stdc++.h>
using namespace std;
 
 
 
 
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long long x,y;
        cin>>x>>y;
        long long h=max(x,y);
        long long z=h*h-(h-1);
        if(x==y)
        cout<<z<<endl;
        else {
            if(h%2==0)
            {
            if(x<y)
            {
                cout<<z-(y-x)<<endl;
            }
            else {
            cout<<z+(x-y)<<endl;
            }
            }
            else {
            if(x<y)
            {
                cout<<z+(y-x)<<endl;
            }
            else {
            cout<<z-(x-y)<<endl;
            }
            }
        }
    }
 
return 0;}
