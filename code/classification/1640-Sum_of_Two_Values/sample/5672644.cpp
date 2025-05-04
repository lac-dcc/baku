//Sum of Two Values
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long int n,m;
    cin>>n>>m;
    vector<long long int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    map<long long int ,long long int> mp;
    map<long long int ,long long int> mpd;
    for(int i=0; i<n; i++){
        if (mp[v[i]]==0)mp[v[i]]=i+1;
        else mpd[v[i]]=i+1;
    }
    
    sort(v.begin(),v.end());
    bool flag=false;
    for(int i=0; i<n; i++){
        int l=i+1, r=n-1,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(v[i]+v[mid]<m) l=mid+1;
            else if(v[i]+v[mid]>m) r=mid-1;
            else{
                flag=true;
                if(v[i]!=v[mid])cout<<mp[v[i]]<<" "<<mp[v[mid]];
                else cout<<mpd[v[mid]]<<" "<<mp[v[mid]];
		    break;
            }
        }
        if(flag==true) break;
    }
    if(flag!=true) cout<<"IMPOSSIBLE";
}