#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
vector<ll int> g[200001];
int dia[200001][2];
int downpath[200001];
void cal(int s,int p)
{
    dia[s][0]=dia[s][1]=0;
    downpath[s]=0;
    for(int i=0;i<g[s].size();i++)
    {
        int c=g[s][i];
        if(c!=p)
        {
            cal(c,s);
            downpath[s]=max(downpath[s],1+downpath[c]);
        }
    }
    return;
}
void solve(int s,int p)
{
    bool f=true;
    dia[s][0]=dia[s][1]=0;
    for(int i=0;i<g[s].size();i++)
    {
        int c=g[s][i];
        if(c!=p)
        {
            f=false;
            solve(c,s);
        }
    }
    if(f)
    return;
    vector<int>v;
    for(int i=0;i<g[s].size();i++)
    {
        int c=g[s][i];
        if(c!=p)
        {
            v.push_back(downpath[c]);
            dia[s][0]=max(dia[s][0],max(dia[c][0],dia[c][1]));
        }
    }
    sort(v.begin(),v.end());
    if(v.size()>1)
    dia[s][1]=2+v[v.size()-1]+v[v.size()-2];
    else
    dia[s][1]=1+v[v.size()-1];
    return;
}
int main() {
    ll int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        ll int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cal(1,-1);
    solve(1,-1);
    cout<<max(dia[1][0],dia[1][1]);
	// your code goes here
	return 0;
}
