#include <bits/stdc++.h>
using namespace std;
#define int long long
void setIO(string file = "")
{
  // speed up
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size()))
  {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
typedef struct Node {
  int mss, mls, mrs, m;
  Node operator+(Node other){
    return {
      max(max(mss, other.mss), other.mls + mrs),
      max(mls, m + other.mls),
      max(mrs + other.m, other.mrs),
      m + other.m
    };
  }
} Node;
int n, m;
vector<Node> segtree;
vector<int>  d;
void build(int node = 1, int left = 1, int right = n){
  if(left == right){
    segtree[node] = {max(0ll, d[left]), max(0ll, d[left]), max(0ll, d[left]), d[left]};
    return;
  }
  int mid = (left + right)/2;
  build(node <<1, left, mid);
  build(node << 1 | 1, mid+1, right);
  segtree[node] = segtree[node<<1] + segtree[node<<1|1];
}
void update(int loc, int val, int node = 1, int left = 1, int right = n){
  if(left == right){
    segtree[node] = {max(0ll, val), max(0ll, val), max(0ll, val), val};
    return;
  }
  int mid = (left + right)/2;
  if(loc > mid){
    update(loc, val, node<<1 | 1, mid+1, right);
  }
  else{
    update(loc, val, node<<1, left, mid);
  }
  segtree[node] = segtree[node<<1] + segtree[node<<1 | 1];
}
signed main(){
  // setIO("test");
  cin>>n>>m;
  segtree.assign(4*n, {0, 0, 0, 0});
  d.assign(n+1, 0);
  for(int i = 1; i <= n; ++i){
    cin>>d[i];
  }
  build();
  while(m--){
    int loc, val;
    cin>>loc>>val;
    update(loc, val);
    cout<<segtree[1].mss<<endl;
  }
  
 
}
