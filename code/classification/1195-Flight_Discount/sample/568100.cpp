#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tlii tuple<ll,int,int>
#define N 100001
 
vector<vector<pii>> adj(N);
ll d[2][N];
priority_queue<tlii,vector<tlii>,greater<tlii>> Q;
 
void Relax(int k, int i, ll x){
  if(x < d[k][i]){
    d[k][i] = x;
    Q.push({x, k, i});
  }
}
 
int main(){
  int n, m;
 
  scanf("%d%d", &n, &m);
  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    adj[i].push_back({j, k});
  }
 
  for(int i = 1; i <= n; ++i){
    d[0][i] = LLONG_MAX;
    d[1][i] = LLONG_MAX;
  }
 
  Relax(0, 1, 0ll);
  
  while(!Q.empty()){
    auto [di, k, i] = Q.top();
    Q.pop();
 
    if(di != d[k][i]){
      continue;
    }
 
    for(pii p: adj[i]){
      Relax(k, p.first, di + p.second);
      if(k == 0){
        Relax(1, p.first, di + p.second / 2);
      }
    }
  }
 
  printf("%lld\n", min(d[0][n], d[1][n]));
 
  return 0;
}
