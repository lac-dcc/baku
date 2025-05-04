#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i] = x;
        b[i] = y;
    }
    int ans = 0;
    int c = 0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i = 0;
    int j = 0;
    while(i<n){
        if(a[i]<b[j]) {
            c++;
            i++;
        }
        else{
            j++;
            c--;
        }
        ans = max(ans,c);
    }
    cout<<ans;
}
