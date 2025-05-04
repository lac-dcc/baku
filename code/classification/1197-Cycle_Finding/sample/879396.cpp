#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl
#define PR(n,name) for(int i =1;i<=n;i++) cout << name[i] << " "; cout F;
 
typedef long long ll;
const int mxn = 1e5;
const int MXN = 4e5;
int n,m;
bool ready[mxn];
int anterior[mxn];
ll distancia[mxn];
vector<tuple<int,int,ll>> edges;
int a, b;
ll w;
 
/*
7 10
1 2 1
1 4 1
2 1 1
2 5 1
3 2 1
3 7 1
5 4 1
6 5 1
6 3 1
7 6 1
*/
 
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  cin >> n >> m;
  for (int i = 0;i<m;i++) {
    cin >> a >> b >> w;
    edges.push_back({a,b,w});
  }
 
  for (int i = 0; i<n ; i++) {
    for (auto e : edges) {
      tie(a,b,w) = e;
      if (distancia[b]>distancia[a]+w) {
        distancia[b]=distancia[a]+w;
        anterior[b]=a;
      }
      distancia[b]=min(distancia[b], distancia[a]+w);
    }
  }
 
  bool found = false;
  for (auto e : edges) {
    tie(a,b,w) = e;
    if (distancia[b]>distancia[a]+w) {
      cout << "YES" F;
      found = true;
      anterior[b]=a;
      break;
    }
    distancia[b]=min(distancia[b], distancia[a]+w);
  }
 
  //for (int i = 1; i<=n; i++) cout << i << " "; cout F;
  //PR(n, anterior)
  if (found) {
    int temp = b;
    set<int> s;
    while(s.count(temp)==0) {
      s.insert(temp);
      temp = anterior[temp];
    }
    b = temp;
    vector<int> res;
    int lres = 0;
    res.push_back(temp);
    lres++;
    for (temp = anterior[temp]; temp!=b; temp = anterior[temp]) {
      res.push_back(temp);
      lres++;
    }
    res.push_back(temp);
    lres++;
    for (int i = lres-1;i>=0; i-- ) cout << res[i] << " "; cout F;
  }
  else cout << "NO" F;
}
