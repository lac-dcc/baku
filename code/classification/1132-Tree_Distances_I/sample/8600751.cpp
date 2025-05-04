/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(x) begin(x) , end(x) 
#define mask(i) (1LL << (i))
#define vi vector<int>
#define vvi vector<vi>
const int mod = pow(10,9)+7 ;
const int MAX = pow(10,5)+1 ;
const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
int mod_pow( int a , int b )
{
    if( a == 0 || a == 1 ) return a ;
    if( b == 0 )return 1 ;
    int ha = mod_pow( a , b/2 ); ha *= ha; ha %= mod ; if( b&1 ) ha *= a ;
    return ha%mod ;
}
int inverse( int a )
{
    return mod_pow(a,mod-2);
}
vector<int> factorial( int N = MAX )
{
    vector<int>f(N,1);
    for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
    return f ;
}
#define oo (int)pow(2L,60)
#define arr array<int,3> 
#define ar array<int,2>
 
/********** GO DOWN ***********/
 
/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/
 
 
class max_except_me
{
	vector<int>P , S ;
	int N ;
public:
	max_except_me( const vector<int>&A )
	{
		this->N = A.size();
		P.resize(N);
		S.resize(N);
 
		P.front() = A.front();
		S.back() = A.back();
 
		for( int i = 1 ; i < N ; i++ )
		{
			P[i] = max( P[i-1] , A[i] );
		}
 
		for( int i = N-2 ; i >= 0 ; i-- )
		{
			S[i] = max( S[i+1] , A[i] );
		}
	}
 
 
	int get( int i )
	{
		int res = INT_MIN ;
		if( i > 0 )
			res = max( res , P[i-1] );
		if( i < N-1 )
			res = max( res , S[i+1] );
 
		return res;
	}
 
 
};
 
void dfs1( vector<int>g[] , vector<int>&F , int u , int p )
{
	F[u] = 0 ;
 
	for( auto v : g[u] )
	{
		if( v != p )
		{
			dfs1( g , F , v , u );
 
			F[u] = max( F[u] , 1 + F[v] );
		}
	}
}
 
 
void dfs2( vector<int>g[] , vector<int>&S , vector<int>&F , int u , int p )
{
 
	vector<int>childs ;
	for( auto v : g[u] )
	{
		if( v != p )
			childs.push_back(v);
	}
 
	if(childs.size() == 0 )
		return ;
 
	vector<int>childs_f ;
	for( auto x : childs )
		childs_f.push_back(F[x]);
 
	max_except_me tool(childs_f);
 
	for( int i = 0 ; i < childs.size() ; i++ )
	{
		int v = childs[i];
		S[v] = max( 1 + S[u] , 2 + tool.get(i) );
 
		dfs2( g , S , F , v , u );
	}
}
 
 
 
int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
 
    auto solve = [&]()->void
    {
        int N ;
        cin>>N ;
        vector<int>g[N];
        for( int i = 0 ; i < N-1 ; i++ )
        {
        	int a , b ;
        	cin>>a>>b ;
        	a--;b--;
        	g[a].push_back(b);
        	g[b].push_back(a);
        }
 
 
        vector<int>F(N,0); 
        vector<int>S(N,0); // outside substree 
 
        dfs1( g , F , 0 , -1 );
        dfs2( g , S , F , 0 , -1 );
 
        for( int i = 0 ; i < N ; i++ )
        	cout<<max( F[i] , S[i] )<<" ";
        cout<<endl;
    };
    
 
        
    // int test = 1 ;
    // cin>>test;
    // while(test--)
    solve();
    
    return 0;
}
