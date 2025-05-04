#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int INT;
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void DFS(int node,vector<INT> adj[],vector<int>& vis)
{
    vis[node]=1;
    for(auto next:adj[node])
    {
        if(!vis[next])
        {
            DFS(next,adj,vis);
        }
    }
}
int main(void)
{
    INT T = 1;
    // cin >> T;
    INT t = 0;
    while (t < T)
    {
        INT N,M;
        cin >> N >> M;
        vector<INT> adj[N];
        for(int i=0;i<M;i++)
        {
            INT X,Y;
            cin >> X >> Y;
            adj[X-1].push_back(Y-1);
            adj[Y-1].push_back(X-1);
        }
        vector<int> vis(N,0);
        INT prev = -1;
        INT count = 0;
        vector<pair<int,int>> vect;
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                count++;
                if(prev==-1)
                {
                    prev=i;
                }
                else
                {
                    vect.push_back({prev,i});
                    prev = i;
                }
                DFS(i,adj,vis);
            }
        }
        cout << count-1 << endl;
        for(int i=0;i<vect.size();i++)
        {
            cout << vect[i].first+1 << " " << vect[i].second+1 << endl;
        }
        t++;
    }
}
 
 
 
