#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int r;cin>>r;
    for (long long int i = 0; i < r; ++i) {
        long long int x,y;
        cin>>x>>y;
        if(x>=y && ((x%2==0 && y%2==0) || (x%2==0 && y%2!=0))){
            cout<<x*x-y+1<<'\n';
        }
        else if(x>=y && ((x%2!=0 && y%2==0) || (x%2!=0 && y%2!=0))){
            cout<<x*x-2*x+y+1<<'\n';
        }
        else if(y>x && ((x%2==0 && y%2==0) || (x%2!=0 && y%2==0))){
            cout<<y*y-2*y+1+x<<'\n';
        }
        else if(y>x && ((x%2==0 && y%2!=0) || (x%2!=0 && y%2!=0))){
            cout<<y*y+1-x<<'\n';
        }
    }
}
