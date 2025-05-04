#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<int>nums;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        nums.insert(x);
    }
    cout<<nums.size();
}
