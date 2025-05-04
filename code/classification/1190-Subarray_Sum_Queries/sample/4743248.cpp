#include<bits/stdc++.h>
using namespace std;
#define bug(a) cerr<<#a<<" : "<<a<<endl;
using ll = long long;
const int mx = 2e5+7;
const ll inf = 1<<30;
 
struct Tree
{
    ll sum, pref, suff, ans;
}tree[4*mx];
int arr[mx];
 
Tree Combine(Tree l, Tree r)
{
    Tree ret;
    ret.sum  = l.sum+r.sum;
    ret.pref = max(l.pref, l.sum+r.pref);
    ret.suff = max(r.suff, r.sum+l.suff);
    ret.ans  = max(l.suff+r.pref, max(l.ans, r.ans));
    return ret;
}
 
void build(ll node, ll start, ll end)
{
    if(start==end){
            tree[node].sum = tree[node].pref = tree[node].suff = tree[node].ans = max(-inf, (ll)arr[start]);
            return;
    }
    ll mid = (start+end)>>1;
 
    build(node<<1, start, mid);
    build(node<<1|1, mid+1, end);
    tree[node] = Combine(tree[node<<1], tree[node<<1|1]);
}
 
Tree query(ll node, ll start, ll end, ll i, ll j)
{
    if(i>end || j<start)
            return {-1<<31, -1<<31, -1<<31, -1<<31};
    if(start>=i && end<=j)
            return tree[node];
 
    ll mid = (start+end)>>1;
    Tree x = query(node<<1, start, mid, i, j);
    Tree y = query(node<<1|1, mid+1, end, i, j);
 
    return Combine(x, y);
}
 
void update(ll node, ll start, ll end, ll i, ll newvalue)
{
    if(i<start || i>end)
             return;
    if(start>=i && end<=i){
             tree[node].sum = tree[node].pref = tree[node].suff = tree[node].ans = max(-inf, newvalue);
             return;
    }
    ll mid = (start+end)>>1;
 
    update(node<<1, start, mid, i, newvalue);
    update(node<<1|1, mid+1, end, i, newvalue);
    tree[node] = Combine(tree[node<<1], tree[node<<1|1]);
}
 
int main()
{
   // ios_base::sync_with_stdio(0);
  //  cin.tie(0); cout.tie(0);
 
    int tc=1, n, m, k;
   // cin >> tc;
 
    while(tc--){
             int q;
             scanf("%d %d", &n, &q);
             for(int i=1; i<=n; i++)scanf("%d", &arr[i]);
 
             build(1, 1, n);
 
             while(q--){
                    int k, x;
                    scanf("%d %d", &k, &x);
                    update(1,1 , n, k, x);
                    printf("%lld\n", max(0ll, query(1, 1, n, 1, n).ans));
             }
    }
    return 0;
}
