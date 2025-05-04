#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>
#include <deque>
#include <stack>
using namespace std;
 
 
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vvl vector<vector<long long> >
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define fr(i,s,e) for(long long int i=s;i<e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
 
int n,m;
vector<int> adj[100001];
 
void solve(){
    cin>>n>>m;
    fr(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s=1,e=n;
    // cin>>s>>e;
    deque<int> q;
    q.push_back(s);
    vector<int> dist(n+1,-1);
    dist[s]=0;
    while(q.size()){
        int node = q.front();q.pop_front();
        for(int nextNode:adj[node]){
            if(dist[nextNode]==-1){
                dist[nextNode]=dist[node]+1;
                q.push_back(nextNode);
            }
        }
    }
    if(dist[e]==-1){
        cout<<"IMPOSSIBLE\n";
    }
    else {
        stack<int> path;
        int d=dist[e];
        int curr=e;
        path.push(curr);
        while(curr!=s){
            for(int node:adj[curr]){
                if(dist[node]==d-1){
                    curr=node;
                    d=d-1;
                    path.push(curr);
                    break;
                }
            }
        }
        cout<<path.size()<<endl;
        while(!path.empty()){
            cout<<path.top()<<" ";
            path.pop();
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc=1;
    //cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}
