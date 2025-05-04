#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m,k;cin>>n>>m>>k;
    vector<int> des(n,0);
    vector<int> act(m,0);
    for(int i=0;i<n;i++){
        int desi;cin>>desi;
        des[i]=desi;
    }
    for(int i=0;i<m;i++){
        int acti;cin>>acti;
        act[i]=acti;
    }
    sort(des.begin(),des.end());
    sort(act.begin(),act.end());
    
    int i{0},j{0};
    int ans = 0;
    while(i<n && j<m){
        if(des[i]-k <= act[j] && des[i]+k >= act[j]){
            ans++;i++;j++;
        }
        else if(des[i]-k > act[j]){
            j++;
        }
        else{
            i++;
        }
    }
    cout << ans;
}
