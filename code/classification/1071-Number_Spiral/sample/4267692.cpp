#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        ll y, x;
        cin>>y>>x;
        if(y < x){
            if(x%2 == 1){
                cout<<((x*x) - y + 1)<<endl;
            }else{
                cout<<(((x-1)*(x-1) + 1) + y - 1)<<endl;
            }
        }else{
            if(y%2 == 0){
                cout<<((y*y) - x + 1)<<endl;
            }else{
                cout<<(((y-1)*(y-1) + 1) + x - 1)<<endl;
            }
        }
    }
    return 0;
}
