#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxn= 4e5;
int n,ans=0;
 
int main() {
    cin >>n;
    ll cs=-1e10, ans=-1e10;
    for(int i=0; i<n; i++) {
        int a;
        cin >>a;
        cs =max(cs+a,0ll+a);
        ans =max(cs,ans);
    }
    cout <<ans;
}