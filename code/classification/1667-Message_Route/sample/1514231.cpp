#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pi pair<lli,lli>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define FOR(i,a,b) for(lli i=a;i<b;i++)
//const lli inf=1000000000000000000;
//const long double pi = 3.14159265358979323846264338;
lli mod=998244353;
lli dx[4] = { -1, 0, 1, 0 };
lli dy[4] = { 0, 1, 0, -1 };
vector <lli> bol;
vector <lli> a[200005];
lli n,m;
queue <lli> q;
vector <lli> res;
void bfs () {
        if(q.empty())
        	return;
        else{
        	lli temp;
        	lli tt;
        	while(!q.empty()){
               temp=q.front();
               bol[temp]=1;
               q.pop();
               tt=a[temp].size();
               for(lli i=0;i<tt;i++){
                   if(bol[a[temp][i]]==0){
                   	res[a[temp][i]]=temp;
                   	bol[a[temp][i]]=1;
                   	q.push(a[temp][i]);
                   }
               }
        	}
 
        }
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
        #endif
	    int t=1;
	    //cin>>t;    
while(t--) {
	
	cin>>n>>m;
	bol.resize(n);
	res.resize(n);
	lli x,y;
	FOR(i,0,m){
       cin>>x>>y;
       x--;y--;
       a[x].push_back(y);
       a[y].push_back(x);
	}
    q.push(0);
    bfs();
    if(bol[n-1]==1){
      vector <lli> ans;
      ans.push_back(n);
      lli temp=res[n-1];
      lli k=0;
      while(temp!=0){
      	ans.push_back(temp+1);
        k=res[temp];
        temp=k;
      }
      ans.push_back(1);
      k=ans.size();
      cout<<k<<endl;
      for(lli i=k-1;i>=0;i--){
          cout<<ans[i]<<" ";
      }
      cout<<endl;
    }
    else
    	cout<<"IMPOSSIBLE"<<endl;
 
 
 
 
 
 
 
}
}
 
 
