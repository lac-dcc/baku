#include<iostream>
#include<algorithm>
# include <string>
#include <map>
#include<vector>
#include <cmath>
#include<set>
using namespace std;
const int MOD = 1e9 + 7;
bool isprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int nd(int x){
    int ans=0;
    for(int i=1;i*i<x;i++){
        if(x%i==0){
            ans+=2;
        }
    }
    int q=sqrt(x);
    if(q*q==x){
        ans++;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    set<int>s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
}