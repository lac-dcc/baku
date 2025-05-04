#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define reg register
#define FLF(a, b, c) for(a = b; a <=c; a++)
#define FLB(a, b, c) for(a = b;a >= c; a--)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define GEN(T) template<typename T>
#define EB emplace_back
#define SORT(x) sort(all(x))
#define all(x) x.begin(), x.end()
#define yes cout<<"yes\n";
#define no cout<<"no\n";
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define Yes cout<<"Yes\n";
#define No cout<<"No\n";
#define vecPrint(vect) {for(int i=0;i<vect.size();i++) cout<<vect[i]<<" ";}
#define newl "\n"
#define IOF ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
using UL  =  unsigned long int;
using UI  =  unsigned int;
using ULL =  unsigned long long int;
using LI  =  long int;
using LL  =  long long;
using LF  =  double;
using LLF =  long double;
const int MOD1 = 1000000007;
const double PI = acos(-1);
typedef vector<vector<int>> adjList;
/*const int MOD2 = */
/* Combinatorics Start */
int binoMax = 10000;
vector<LL> numInv(binoMax + 1), factNumInv(binoMax + 1), fact(binoMax + 1);
vector<LL> little_primes = {2,3,5,7,11,13,17,19,23,31,37};
 
GEN(T)
T extgcd(T a,LL b,T &x,T &y){
	if(b==0){x=1;y=0;return a;}T d = extgcd(b,a%b,y,x);y-= (a/b *x);return d;
}
GEN(T) /*modular Inverse if p is not prime*/
T mod_inv(T a,T p){
	if(__gcd(a,p)!=1)return -1;T x,y;extgcd(a,p,x,y);x%=p;if(x<0)x+=p;return x;
}
inline void generate_ncrp(LL p)
{   int i;numInv[0] = numInv[1] = 1;
	FLF(i, 2, binoMax)
	{	numInv[i] = numInv[p % i] * (p - p / i) % p;
	}	factNumInv[0] = factNumInv[1] = 1;
	FLF(i, 2, binoMax)
	{	factNumInv[i] = (numInv[i] * factNumInv[i - 1]) % p;
	}
	fact[0] = 1;
	FLF(i, 1, binoMax)
	{	fact[i] = (fact[i - 1] * i) % p;
	}
}
LL ncrmodp(LL n, LL r, LL p)
{	LL ans = ((fact[n] * factNumInv[r]) % p * factNumInv[n - r]) % p;
	return ans;
}
/* Combinatorics End */
 
LL powM(LL x, LL y, LL p)
{	LL res = 1;
	while (y > 0)
	{	if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}return res;
}
/* Matrix Operations Start */
struct Matrix{
	int row,col;
	vector<vector<LL> > a;
	Matrix(int r,int c){
		row=r;col=c;
		a.resize(row,vector<LL>(col,0));
;	}
    static Matrix IDM(LL n){
    	Matrix res(n,n);
    	for(int i=0;i<n;i++)res.a[i][i]=1;
    	return res;
	}
};
Matrix Matmult(Matrix A,Matrix B){
	Matrix res(A.row,B.col);
	LL i,j,k;
	FLF(i,0,A.row-1){
		FLF(j,0,B.col-1){
			FLF(k,0,A.col-1){
				res.a[i][j]=(res.a[i][j]+A.a[i][k]*B.a[k][j])%MOD1;
			}
		}
	}
	return res;
	
}
Matrix BinExp(Matrix X,LL n){
	Matrix res=Matrix::IDM(X.row);
	while(n>0){
		if(n&1){
			res=Matmult(X,res);
		}
		X=Matmult(X,X);
		n>>=1;
	}
	return res;
}
/* Matrix Operations End */
 
adjList G;
int n;
vector<bool> vis;
vector<int> sub;
inline void dfs(int node,int par){
	for(auto child : G[node]){
		if(child!=par){
			dfs(child,node);
		}
	}
	if(par!=-1){
		sub[par]+=sub[node];
	}
}
 
int main(){
	/*Start Here*/
	IOF 
	cin>>n;
	int i,j,k,x,y;
	vis.resize(n);
	G.resize(n);
	sub.assign(n,1);
	FLF(i,2,n){
		cin>>j;
		G[i-1].push_back(j-1);
		G[j-1].push_back(i-1);
	}
 
	dfs(0,-1);
    FLF(i,0,n-1){
		cout<<sub[i]-1<<" ";
	}
}
