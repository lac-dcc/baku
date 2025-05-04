#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int N = 1e9 + 7;
    int n, x;
    cin>>n>>x;
    vector<int> num(n), count(x+1);
    for(int i=0; i<n; i++){
        cin>>num[i];
    }
    count[0] = 1;
    for(int i = 1; i<=x; i++){
    for(int c:num){
        if(i-c>=0){
            count[i] += count[i-c];
            count[i] %= N;
        }
    }
    }
    cout<<count[x];
}
