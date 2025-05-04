#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct triplet{
   long long int w;
   int node;
   int coupon;
};
class Compare{
   public:
   bool operator()(triplet& below,triplet& above){
        if(below.w>above.w){
            return true;
        }
        return false;
   }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        long long int w;
        cin>>w;
        adj[a].push_back({b,w});
    }
    vector<vector<long long int>>dist(n+1,vector<long long int>(2,1e15));
    dist[1][1]=0;
    priority_queue<triplet,vector<triplet>,Compare>pq;
    pq.push({0,1,1});
    while(pq.size()!=0){
        auto f=pq.top();
        //cout<<"{"<<f.node<<" "<<f.w<<" "<<f.coupon<<"}"<<endl;
        pq.pop();
        //cout<<dist[f.node][f.coupon]<<endl;
        if(f.coupon==1){
           if(dist[f.node][1]<f.w){
            continue;
           }
           for(int i=0;i<adj[f.node].size();i++){
            if(dist[adj[f.node][i].first][1]>dist[f.node][1]+adj[f.node][i].second){
                dist[adj[f.node][i].first][1]=dist[f.node][1]+adj[f.node][i].second;
                pq.push({dist[adj[f.node][i].first][1],adj[f.node][i].first,1});
            }
            if(dist[adj[f.node][i].first][0]>dist[f.node][1]+(adj[f.node][i].second)/2){
                dist[adj[f.node][i].first][0]=dist[f.node][1]+(adj[f.node][i].second)/2;
                pq.push({dist[adj[f.node][i].first][0],adj[f.node][i].first,0});
            }
           }
        }
        else{
           if(dist[f.node][0]<f.w){
            continue;
           }
         for(int i=0;i<adj[f.node].size();i++){
            if(dist[adj[f.node][i].first][0]>dist[f.node][0]+adj[f.node][i].second){
                dist[adj[f.node][i].first][0]=dist[f.node][0]+adj[f.node][i].second;
                pq.push({dist[adj[f.node][i].first][0],adj[f.node][i].first,0});
            }
           }
        }
    }
    cout<<min(dist[n][0],dist[n][1]);
}
