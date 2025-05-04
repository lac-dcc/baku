#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k,count=0;
    cin>>n>>m>>k;
    vector<int> a(n),x(m);
    for(int &i:a) cin>>i;
    for(int &i:x) cin>>i;
    sort(a.begin(),a.end());
    sort(x.begin(),x.end());
    for(int s=0,d=0;s<n&&d<m;s++){
        for(;x[d]<a[s]-k&&d<m;d++);
        if(x[d]>=a[s]-k&&x[d]<=a[s]+k) count++,d++;
    }
    cout<<count<<endl;
}