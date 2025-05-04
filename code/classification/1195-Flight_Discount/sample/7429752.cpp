#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pi pair<int,int>
#define pl pair<long long,long long>
#define adj(name) vector<vector<int>>name
#define adjs(name,size) vector<vector<int>>name(size)
#define adjpass(name) vector<vector<int>>&name
#define med(name,u,v) name[u].push_back(v)
#define rest(name,val) memset(name,val,sizeof name)
#define all(x) x.begin(),x.end()
#define killua ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0)
//changes in dir:
int dx[]={0 , 0 ,1  ,-1 ,-1 ,1  ,-1 , 1};
int dy[]={1 ,-1 ,0  , 0 , 1 ,1  ,-1 ,-1};
int cases=0;
/*******************الْمَالُ وَالْبَنُونَ زِينَةُ الْحَيَاةِ الدُّنْيَا ۖ وَالْبَاقِيَاتُ الصَّالِحَاتُ خَيْرٌ عِندَ رَبِّكَ ثَوَابًا وَخَيْرٌ أَمَلًا *******************/
/******************إِلا أَنْ يَشَاءَ اللَّهُ وَاذْكُرْ رَبَّكَ إِذَا نَسِيتَ وَقُلْ عَسَى أَنْ يَهْدِيَنِي رَبِّي لأَقْرَبَ مِنْ هَذَا رَشَدًا *****************/
void gon() {
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> v(n + 9);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;//{cost,{freeCopun,node}}
    int dis[n+9][2];
    for(int i=0;i<n+9;i++){
        dis[i][0]=1e18;
        dis[i][1]=1e18;
    }
    dis[1][0]=0;
    pq.push({dis[1][0],{0,1}});
    while(!pq.empty()){
        int node=pq.top().second.second;
        int free=pq.top().second.first;
        int cost=pq.top().first;
        pq.pop();
        if(cost>dis[node][free])
            continue;
        for(auto i:v[node]){
            if(cost+i.second<dis[i.first][free]){
                dis[i.first][free]=cost+i.second;
                pq.push({dis[i.first][free],{free,i.first}});
            }
            if(free==0){
                if(cost+i.second/2<dis[i.first][1]){
                    dis[i.first][1]=cost+i.second/2;
                    pq.push({dis[i.first][1],{1,i.first}});
                }
            }
        }
    }
    cout<<min(dis[n][1],dis[n][0])<<endl;
}
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("Input.txt","r",stdin);
        freopen("Output.txt","w",stdout);
    #endif
    killua;
    int t=1; if(cases) cin>>t;
    while(t--){
        gon();
    }
}