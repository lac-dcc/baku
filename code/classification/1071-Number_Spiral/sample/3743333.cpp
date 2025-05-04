#include<iostream>
using namespace std;
int main(){
    long int t,i,j,s,e;
    cin>>t;
    while (t--){
        cin>>i>>j;
        if (i>j){
            if (i%2==0){
               s=i*i;
               e=(s-j)+1;
            }
            else{
                s=(i-1)*(i-1)+1;
                e=(s+j)-1;
            }
        }
        else{
            if (j%2==0){
                s=(j-1)*(j-1)+1;
                e=(s+i)-1;
            }
            else{
                s=j*j;
                e=(s-i)+1;
            }
        }
        cout<<e<<"\n";
    }
    return 0;
}