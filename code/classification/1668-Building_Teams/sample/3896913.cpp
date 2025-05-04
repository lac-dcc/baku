#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> sasiedzi[100000];
bitset <100001> odwiedzone;
int druzyna[100001];
bool impossible=0;
void dfs(int w,int prev)
{
    if(odwiedzone[w]&&druzyna[w]==druzyna[prev]){impossible=1; return;}
    if(odwiedzone[w]==0)
    {odwiedzone[w]=1; if(druzyna[prev]==0)druzyna[w]=1;
                        else druzyna[w]=0;
    for(int i=0;i<sasiedzi[w].size();i++)
    {
    dfs(sasiedzi[w][i],w);
    }
    }
}
int main()
{ ios_base::sync_with_stdio(0);
cin.tie(0);
druzyna[0]=-1;
    int n;
    int m;
    cin>>n>>m;
for(int i=0;i<m;i++)
{int a,b;
cin>>a>>b;
    sasiedzi[a].push_back(b);
    sasiedzi[b].push_back(a);
}
for(int i=1;i<=n;i++)
{if(impossible){cout<<"IMPOSSIBLE"; return 0;}
    if(!odwiedzone[i])
    {
        dfs(i,0);
    }
}
for(int i=1;i<=n;i++)cout<<druzyna[i]+1<<' '; 
    return 0;
}
