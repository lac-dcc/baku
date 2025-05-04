#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
 
const int MAXN=5010;
int dp[MAXN][MAXN],n,m;
string s,t;
 
int solve(int x, int y){
	if(x==n&&y==m)return 0;
	int &r=dp[x][y];
	if(r>=0)return r;
	r=1e9;
	
	//cambiar
	if(x<n&&y<m) r=min(r,1+solve(x+1,y+1));
	//borrar
	if(y<m) r=min(r,1+solve(x,y+1));
	//agregar
	if(x<n) r=min(r,1+solve(x+1,y));
	//nada
	if(x<n&&y<m&&s[x]==t[y]) r=min(r,solve(x+1,y+1));
	
	return r;
}
 
int main(){FIN;
	cin>>s>>t;
	n=SZ(s); m=SZ(t);
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0)<<"\n";
}