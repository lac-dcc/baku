//CODE BY Sanchit Gupta
#define pb push_back
#define db double
#define lli long long int
#define sa(v) sort(v.begin(),v.end())
#define sd(v) sort(v.begin(),v.end(),greater<lli>())
#define vpl vector<pair<lli,lli>>
#define vll vector<lli>
#define mps map<lli,lli>
#define mpst map<string,lli>
#define mpc map<char,lli>
#define ff first
#define ss second
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#include<algorithm>
using namespace std;
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define endl '\n'
const int mod=1e9+7;
const int M=2e5+1;
const int INF = 2e9;
 
vll arr(M,0);
 
lli dfs(lli root,vector<vll>&graph,vll &visited,lli count){
    visited[root]=1;
    for(lli node: graph[root]){
        if(!visited[node]){
            count+= 1+dfs(node,graph,visited,0);
        }
 
    }
    return arr[root]=count;
}
 
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
	lli n,m,t,i,j,k,input;
	cin >> n;
    vector<vll>graph(n);
    for(i=1;i<n;i++){
        cin >> input;
        graph[input-1].pb(i);
        graph[i].pb(input-1);
    }
    vll visited(n,0);
    dfs(0,graph,visited,0);
 
    for(i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
 
// //CODE BY Sanchit Gupta
// #define pb push_back
// #define db double
// #define lli long long int
// #define sa(v) sort(v.begin(),v.end())
// #define sd(v) sort(v.begin(),v.end(),greater<lli>())
// #define vpl vector<pair<lli,lli>>
// #define vll vector<lli>
// #define mps map<lli,lli>
// #define mpst map<string,lli>
// #define mpc map<char,lli>
// #define ff first
// #define ss second
// #include<iostream>
// #include<cmath>
// #include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #include<algorithm>
// using namespace std;
// #define gcd(a,b) __gcd(a,b)
// #define lcm(a,b) a*b/__gcd(a,b)
// #define endl '\n'
// const int mod=1e9+7;
// const int M=2e5+1;
// const int INF = 2e9;
 
// vll ans(M,0);
 
// void bfs(lli root,vector<vll>& graph){
//     mps mp;
//     vll visited(graph.size(),0);
//     queue<lli>q;
//     q.push(root);
//     vector<vll>v(graph.size());
//     while(!q.empty()){
//         root= q.front();
//         visited[root]=1;
//         lli count=0;
//         for(lli node: graph[root]){
//             if(!visited[node]){
//                 v[root].push_back(node);
//                 q.push(node);
//                 count++;
//             }
//         }
//         mp[root]=count;
//         q.pop();
//     }
//     for(auto it=mp.begin();it!=mp.end();++it){
//         cout << it->ff << " " << it->ss << endl;
//     }
//     for(lli i=0;i<v.size();i++){
//         for(lli j=0;j<v[i].size();j++){
//             cout << v[i][j] << " ";
//         }
//         cout << endl;
//     }
//     for(lli i=0;i<v.size();i++){
//         lli sum=0;
//         for(lli j=0;j<v[i].size();j++){
//             sum= sum + mp[v[i][j]];
//         }
//         ans[i]= sum + v[i].size();
//     }
// }
 
// int main(){
// ios_base::sync_with_stdio(0);
// cin.tie(0);
// cout.tie(0);
// 	lli n,m,t,i,j,k,input;
// 	cin >> n;
//     vector<vll>graph(n);
//     for(i=1;i<n;i++){
//         cin >> input;
//         graph[input-1].pb(i);
//         graph[i].pb(input-1);
//     }
//     bfs(0,graph);
    
//     for(i=0;i<n;i++){
//         cout << ans[i] << " ";
//     }
//     cout << endl;
// }
