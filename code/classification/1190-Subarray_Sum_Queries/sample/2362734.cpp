//******************************************
//     Author : nesco   
//     Created: Fri Jun 18 2021 17:58:36
//     File   : Subarray Sum Queries.cpp
//******************************************
 
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define endl '\n';
 
template<typename T>istream& operator>>(istream& is,vector<T> &v){for (auto& i : v) is >> i;return is;}
 
struct maxsumdata {
   ll sum;    // the sum of the segment
   ll pref;   // the maximum prefix sum
   ll suff;   // the maximum suffix sum
   ll ans; // the sum of the maximal subsegment
};
 
class SegmentTree {
   // This segment tree finds subsegments with the maximal sum in the segment [l,r];
   // You can update the values of the array.
public:
   SegmentTree(ll sz, ll values[]) {
      n = sz;
      data = new maxsumdata [4*n];
      build(values,1,0,n-1);
   }
   ~SegmentTree(){
      delete[] data;
   }
   maxsumdata maxsum(ll l, ll r)
   {
      ll v = 1;
      ll tl = 0;
      ll tr = n-1;  
      return query(v,tl,tr,--l,--r);    
   }
   void update(ll pos, ll new_val)
   {
      ll v = 1;
      ll tl = 0;
      ll tr = n-1;
      privateupdate(v,tl,tr,--pos,new_val);
   }
private:
   ll n;
   maxsumdata *data;
   maxsumdata combine(maxsumdata l, maxsumdata r) {
      maxsumdata res;
      res.sum = l.sum + r.sum;
      res.pref = max(l.pref, l.sum + r.pref);
      res.suff = max(r.suff, r.sum + l.suff);
      res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
      return res;
   }
   maxsumdata make_maxsumdata(ll val)
   {
      maxsumdata res;
      res.sum = val;
      res.pref = res.suff = res.ans = max((ll)0,val);
      return res;
   }
   void build(ll a[], ll v, ll tl, ll tr) {
      if (tl == tr) {
         data[v] = make_maxsumdata(a[tl]);
      } else {
         int tm = (tl + tr) / 2;
         build(a, v*2, tl, tm);
         build(a, v*2+1, tm+1, tr);
         data[v] = combine(data[v*2], data[v*2+1]);
      }
   }
   void privateupdate(ll v, ll tl, ll tr, ll pos, ll new_val) {
      if (tl == tr) {
         data[v] = make_maxsumdata(new_val);
      } else {
         int tm = (tl + tr) / 2;
         if (pos <= tm)
            privateupdate(v*2, tl, tm, pos, new_val);
         else
            privateupdate(v*2+1, tm+1, tr, pos, new_val);
         data[v] = combine(data[v*2], data[v*2+1]);
      }
   }
   maxsumdata query(ll v, ll tl, ll tr, ll l, ll r) {
      if (l > r) 
         return make_maxsumdata(0);
      if (l == tl && r == tr) 
         return data[v];
      ll tm = (tl + tr) / 2;
      return combine(query(v*2, tl, tm, l, min(r, tm)), 
                     query(v*2+1, tm+1, tr, max(l, tm+1), r));
   }
};
 
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   ll n, m; cin >> n >> m;
   ll x[n];
 
   for (int i=0; i<n; i++)
   {
      cin >> x[i];
   }
 
   SegmentTree segtree(n,x);
 
   for (int i=0; i<m; i++)
   {
      ll k, x; cin >> k >> x;
 
      segtree.update(k,x);
      maxsumdata t = segtree.maxsum(1,n);
      cout << t.ans << endl;
   }
   
   return 0;
}
