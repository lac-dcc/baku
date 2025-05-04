#include<stdio.h>
#include<vector>
 
 
std::vector< std::vector<int> > v(200000);
int fv=0, fd=0, out[200000];
bool used[200000];
 
void dfs1(int x, int d){
	if(!used[x]){
		used[x]=1;
		if(d>fd){fv=x; fd=d;}
		for(auto f: v[x])dfs1(f, d+1);
	}
}
 
void dfs2(int x, int d){
	if(!used[x]){
		used[x]=1;
		out[x]=std::max(out[x], d);
		for(auto f: v[x])dfs2(f, d+1);
	}
}
 
void clr(int n){for(int i=0; i<n; i++)used[i]=0;}
 
int main(){
	int n, x, y, l, r;
	scanf("%d", &n);
	for(int i=0; i<n-1; i++){
		scanf("%d %d", &x, &y);
		x--; y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(0, 0); clr(n);
	fd=0; l=fv;
	dfs1(l, 0); clr(n);
	r=fv;
	dfs2(l, 0); clr(n);
	dfs2(r, 0);
	for(int i=0; i<n; i++)printf("%d ", out[i]);
}
