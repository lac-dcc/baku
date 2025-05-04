#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
struct node
{
  int sum;
  int pre;
  node()
  {
    sum = 0;
    pre = 0;
  }
};
struct segtree
{
  int size;
  vector<node> sg;
  void init(int n)
  {
    size = 1;
    while (size < n)
    {
      size = size * 2;
    }
    sg.resize(2 * size);
  }
  node com(node a, node b)
  {
    node res;
    res.sum = a.sum + b.sum;
    res.pre = max({a.sum + b.sum, a.pre, a.sum + b.pre, 0LL});
    return res;
  }
  void build(vector<int> &a, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      node leaf;
      if (lx < a.size())
      {
        leaf.sum = a[lx];
        leaf.pre = max(0LL, a[lx]);
      }
      else
      {
        leaf.sum = INT_MIN;
        leaf.pre = INT_MIN;
      }
      sg[x] = leaf;
      return;
    }
    int mid = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, mid);
    build(a, 2 * x + 2, mid, rx);
    sg[x] = com(sg[2 * x + 1], sg[2 * x + 2]);
  }
  void build(vector<int> &a)
  {
    build(a, 0, 0, size);
  }
  void upd(int i, int val, int x, int lx, int rx)
  {
    if (rx - lx == 1)
    {
      // leaf node
      node leaf;
      leaf.sum = val;
      leaf.pre = max(0LL, val);
      sg[x] = leaf;
      return;
    }
    int mid = (lx + rx) / 2;
    if (i < mid)
    {
      upd(i, val, 2 * x + 1, lx, mid);
    }
    else
    {
 
      upd(i, val, 2 * x + 2, mid, rx);
    }
    sg[x] = com(sg[2 * x + 1], sg[2 * x + 2]);
  }
  void upd(int i, int val)
  {
    upd(i, val, 0, 0, size);
  }
  node query(int l, int r, int x, int lx, int rx)
  {
    // do not intersect
    if (lx >= r || rx <= l)
    {
      node temp;
      temp.pre = 0;
      temp.sum = 0;
      return temp;
    }
    // fully overlap
    else if (lx >= l && rx <= r)
    {
      return sg[x];
    }
    else
    {
      int mid = (lx + rx) / 2;
      return com(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid, rx));
    }
  }
  node query(int l, int r)
  {
    return query(l, r, 0, 0, size);
  }
};
int32_t main()
{
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  segtree sg;
  sg.init(n);
  sg.build(v);
  while (q--)
  {
    int type, a, b;
    cin >> type;
    cin >> a >> b;
    a--;
    if (type == 1)
    {
      // update at a to b
      sg.upd(a, b);
    }
    else
    {
      // maxi pre [a,b]
      cout << sg.query(a, b).pre << endl;
      ;
    }
  }
 
  return 0;
}
