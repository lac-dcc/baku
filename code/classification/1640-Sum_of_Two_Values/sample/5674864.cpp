// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> v;
    for(int i=1;i<=n;++i){
        int e;
        cin>>e;
        v.push_back(make_pair(e,i));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i){
        //cout<<"hi"<<endl;
        if(x-v[i].first>0){
            int l,r,mid,s=x-v[i].first;
            r=i-1;
            l=-1;
            while(r-l>1){
                mid=(r+l)/2;
                if(v[mid].first>=s) r=mid;
                else l=mid;
            }
            if(v[r].first==s){
                cout<<v[i].second<<" "<<v[r].second;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    
    return 0;
}