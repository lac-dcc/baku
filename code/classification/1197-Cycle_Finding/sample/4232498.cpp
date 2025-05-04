#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool visit[2501];
int main(){
    int n,m;cin>>n>>m;
    vector<pair<ll,pair<ll,ll>>> edges;
    for(int i=0;i<m;i++)
        {
            ll a,b,c;cin>>a>>b>>c;
            // if(a==b&&c<0)
            //     {
            //         cout<<"YES"<<endl;
            //         cout<<a<<" "<<" "<<a<<endl;
            //         return 0;
            //     }
            edges.push_back(make_pair(a,make_pair(b,c)));
        }
    vector<int> par(n+1,-1);
    vector<ll> dis(n+1,1e17);
    dis[1] = 0;
    for(int i=0;i<n-1;i++)
    {
        for(auto e:edges)
            {
                ll e1 = e.first;
                ll e2 = e.second.first;
                ll wt = e.second.second;
                if((dis[e1] + wt) < dis[e2])
                    {
                        // cout<<e1<<" "<<e2<<endl;
                        par[e2] = e1;
                        dis[e2] = dis[e1]+wt; 
                    }
            }
    } 
    bool relax = false;
    int idx;
    for(auto e:edges)
            {
                ll e1 = e.first;
                ll e2 = e.second.first;
                ll wt = e.second.second;
                       
                    // dis[e2] = min(dis[e2],dis[e1] + wt);
                    if((dis[e1]+wt)< dis[e2])
                        {
                            relax = true;
                            par[e2] = e1;
                            idx = e2;
                            break;
                        }
            }        
        if(!relax)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        // cout<<idx<<endl;
        cout<<"YES"<<endl;
        vector<int> path;  
        // cout<<idx<<endl;
        // cout<<par[idx]<<endl;
        for(int i=0;i<n;i++)
            idx  = par[idx]; // to ensure we are inside a circle
        int id  = par[idx];
        path.push_back(idx);
        while(id!=idx)
            {
                // cout<<id<<endl;
                path.push_back(id);
                id = par[id];
            }
        path.push_back(idx);
        reverse(path.begin(),path.end());
        for(auto i:path)    
            {
                cout<<i<<" ";
            }
 
    
 
    
    return 0;
}
