#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >>n;
    int a[n];
    for(int i =0;i<n;i++)cin>>a[i];
    int count=1;
    sort(a,a+n);
    int r=a[0];
    for(int i=1;i<n;i++){
        if(a[i]!=r){
            r=a[i];
            count++;
        }
    }
    cout <<count;
    return 0;
}
