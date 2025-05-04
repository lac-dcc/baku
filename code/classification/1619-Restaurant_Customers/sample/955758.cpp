#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,char>> arr;
    while(n--){
        int tmp;
        cin>>tmp;
        arr.push_back({tmp,'a'});
        cin>>tmp;
        arr.push_back({tmp,'d'});
    }
    sort(arr.begin(),arr.end());
    int count=0;
    int ans=0;
    for(auto it:arr){
        if(it.second=='a') count++;
        else count--;
        ans=max(ans,count);
    }
    cout << ans << endl;
}
