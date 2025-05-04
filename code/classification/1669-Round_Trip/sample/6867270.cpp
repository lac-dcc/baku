/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&v, vector<bool>&vis, vector<bool>&visrec, vector<int>&parent, int i,bool &flag)
{
    if(flag==false)
    {
        return;
    }
    vis[i]=true;
    visrec[i]=true;
    vector<int>w=v[i];
    for(int j=0;j<w.size();j++)
    {
        if(vis[w[j]]==false)
        {
            parent[w[j]]=i;
            dfs(v,vis,visrec,parent,w[j],flag);
            if(flag==false)
            {
                return;
            }
        }
        else if(visrec[w[j]]==true && w[j]!=parent[i])
        {
            stack<int>s;
            s.push(w[j]);
            s.push(i);
            while(i!=w[j])
            {
                i=parent[i];
                s.push(i);
            }
            cout<<s.size()<<endl;
            while(!s.empty())
            {
                int h=s.top();
                s.pop();
                cout<<h<<" ";
            }
            flag=false;
            return;
        }
    }
    visrec[i]=false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool>vis(n+1,false);
    vector<bool>visrec(n+1,false);
    vector<int>parent(n+1);
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            dfs(v,vis,visrec,parent,i,flag);
        }
    }
    if(flag==true)
    {
        cout<<"IMPOSSIBLE";
    }
    //cout<<"IMPOSSIBLE";
    return 0;
}
