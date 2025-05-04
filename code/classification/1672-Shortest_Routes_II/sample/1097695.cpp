//Fuck the world....don't care anyone........................................................
#include <bits/stdc++.h>
#include<bitset>
#include<iostream>
using namespace std;
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long
#define ld double
#include<stdio.h>
#define ff first
#define ss second
#include<stack>
#include<queue>
#define its set<ll>::iterator
#define itmp map<ll,ll>::iterator
#include<stack>
#define lp for(ll i=0;i<n;i++)
#define dlp for(ll i=0;i<n;i++) for(ll j=0;j<n;j++)
//#define mod 999999999
#define mxi 1e18
#define N 1001
ll b1[]={0,0,1,-1};
ll b2[]={1,-1,0,0};
 
//#define N 101
//#include <boost/functional/hash.hpp>
//bitset<1000> b;
//b.set();   all bit have 1
//seive of Erat
//totient theorm for co-prime
/*ll ll N=1000;
	ll p[1001]={0};
	p[2]=1;
		vector<ll>v;
        for(ll ll i=3;i<=N;i+=2)
        p[i]=1;
        v.push_back(2);
        for(ll ll i=3;i<=N;i+=2)
        {
            if(p[i])
            {
			v.push_back(i);
                for(ll ll j=i*i;j<=N;j+=2*i)
                p[j]=0;
            }
        }  */
/*
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} */
/*
stringstream ss;  
ss<<c;  
string s1;
ss>>s1;
*/
/*
ll power(ll x, unsigned ll y) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
}*/
// vector<char>chr={'R','L','D','U'};
 ll dp[500][500];
int main()
{
	ios_base::sync_with_stdio(false); 
    	cin.tie(NULL); 
		 ll t=1;
	//cin>>t;
   
	while(t--)
	{
            //We can use here concept of floyd warshel algorithm 
            //which is used for shortest path from ever
 
            //this is thr question of DP
            ll n,e,q;
            cin>>n>>e>>q;
            
            memset(dp,0x3f,sizeof(dp) );
            for(ll i=0;i<e;i++)
            {
               ll x,y,dist;
                cin>>x>>y>>dist,x--,y--;
                dp[x][y]=min(dp[x][y],dist);
                dp[y][x]=min(dp[y][x],dist);
            }
            for(int i=0;i<n;i++)
            dp[i][i]=0;
            // for(ll i=1;i<=n;i++)
            // {
            //     for(ll j=1;j<=n;j++)
            //     {
            //         if(i==j)
            //         dp[i][j]=0;
            //         else if(dp[i][j]==-1)
            //         dp[i][j]=mxi;
 
            //     }
            // }
           
            // for(ll i=1;i<=n;i++)
            // {
            //     for(ll j=1;j<=n;j++)
            //     cout<<dp[i][j]<<" ";
            //     cout<<endl;
            // }
            for(ll k=0;k<n;k++)
            {
                for(ll i=0;i<n;i++)
                {
                    for(ll j=0;j<n;j++)
                    {
                        if(dp[i][k]+dp[k][j]<dp[i][j])
                        dp[i][j] = dp[i][k]+dp[k][j];
                    }
                }
            }
            
            while(q--)
            {
                ll int x,y;
                cin>>x>>y;
                x--,y--;
                if(dp[x][y]>=1e18)
                cout<<-1<<endl;
                else
                cout<<dp[x][y]<<endl;
            }
    }
    return 0;
}
