/*
डर मुझे भी लगा फांसला देख कर,
पर मैं बढ़ता गया रास्ता देख कर,
खुद ब खुद मेरे नज़दीक आती गई
मेरी मंज़िल मेरा हौंसला देख कर
*/
#include<stdio.h>
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
#define ll long long int
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod=1e9+7;
const int mx=1e7;
const ll INF=1e18;
vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
const int N=2e6+10;
int parent[N];
ll bit[N];
vector<pair<ll,ll>>dp[N];
vector<ll>dis(N,INF);
int good=0;
ll fact[N];
ll inv[N];
ll power(ll a,ll b)
{ll res=1;while(b){if(b&1){res=res*a;}a=a*a; b>>=1; }return res;}
 
int main()
{
    FastRead;
    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            ll a,b,w;
            cin>>a>>b>>w;
            dp[a].push_back({b,w});
        }
        fill(dis.begin(),dis.end(),INF);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        dis[1]=0;
        pq.push({0,1});
        vector<bool>vis(n+100,false);
        while(pq.size())
        {
            auto temp=pq.top();
            pq.pop();
            ll wt=temp.first;
            ll node=temp.second;
            if(vis[node])
            {
                continue;
            }
            vis[node]=true;
            for(auto it:dp[node])
            {
                if(dis[it.first]>dis[node]+it.second)
                {
                    dis[it.first]=dis[node]+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<dis[i]<<" ";
        }
        cout<<endl;
    } 
}
