#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
 
// solution for Tree Diameter
// see algo in book "Binary Tree Problems: Must for Interviews and Competitive Coding", pages 58-67
using namespace std;
 
inline float getTime()
{
  return (float)clock()/CLOCKS_PER_SEC;
}
 
inline void printTime(const char *pfx)
{
#ifdef TIME
  printf("%s: %f\n", pfx, getTime());
#endif
}
 
struct rt {
 vector<vector<int> > g;
 vector<char> visited;
 vector<int> dist;
 int maxNode = 0;
 int maxD = 0;
 rt(int n)
  : g(n), visited(n, 0), dist(n)
 {}
 void read(int n)
 {
   for ( int i = 1; i < n; ++i )
   {
     int a, b;
     cin>>a>>b; a--; b--;
     g[a].push_back(b);
     g[b].push_back(a);
   }
 }
 void dfs(int node, int d)
 {
   visited[node] = 1;
   if ( d > maxD )
   {
     maxNode = node;
     maxD = d;
   }
   if ( d > dist[node] ) dist[node] = d;
   for ( int n: g[node] ) if ( !visited[n] ) dfs(n, d+1);
 }
 void calc()
 {
   // run DFS from root
   dfs(0, 0);
   fill(visited.begin(), visited.end(), 0);
   maxD = -1;
   // run DFS from maxNode
   dfs(maxNode, 0);
   // and yet one time from new maxNode
   fill(visited.begin(), visited.end(), 0);
   dfs(maxNode, 0);
 }
};
 
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  int n;
  cin>>n;
  rt t(n);
  t.read(n);
printTime("read");
  t.calc();
  for ( int d: t.dist ) printf("%d ", d);
  printf("\n");
printTime("rec");
}
