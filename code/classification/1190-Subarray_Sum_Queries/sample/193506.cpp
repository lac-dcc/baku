#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007 
#define ll long long 
#define N 200005
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define print(x) cout << #x << "=" << x << "\t";
#define newline cout << endl;
 
int n;
int m;
int a[N];
ll tree[4*N];
ll leftmax[4*N];
ll rightmax[4*N];
ll ans[4*N];
 
void unwind(int idx) {
    tree[idx] = tree[2*idx] + tree[2*idx+1];
    leftmax[idx] = max(leftmax[2*idx], tree[2*idx] + leftmax[2*idx+1]);
    rightmax[idx] = max(rightmax[2*idx+1], tree[2*idx+1] + rightmax[2*idx]);
    ans[idx] = max(ans[2*idx], ans[2*idx+1]);
    ans[idx] = max(ans[idx], leftmax[idx]);
    ans[idx] = max(ans[idx], rightmax[idx]);
    ans[idx] = max(ans[idx], rightmax[2*idx] + leftmax[2*idx+1]);
}
 
void build(int idx, int l, int r) {
    if (l == r) {
        tree[idx] = a[r];
        if (tree[idx] > 0) {
            leftmax[idx] = tree[idx];
            rightmax[idx] = tree[idx];
            ans[idx] = tree[idx];
        }
        return;
    }
    int mid = (l + r) / 2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    unwind(idx);
}
 
void update(int idx, int lup, int rup, int val, int l, int r) {
    if (lup <= l && r <= rup) {
        tree[idx] = val;
        leftmax[idx] = rightmax[idx] = ans[idx] = 0;
        if (tree[idx] > 0) {
            leftmax[idx] = tree[idx];
            rightmax[idx] = tree[idx];
            ans[idx] = tree[idx];
        }
        return;
    }
    if (lup > r || l > rup)
        return;
    int mid = (l + r) / 2;
    update(2*idx, lup, rup, val, l, mid);
    update(2*idx+1, lup, rup, val, mid+1, r);
    unwind(idx);
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    build(1,1,n);
 
    while (m--) {
        int x, y;
        cin >> x >> y;
        update(1,x,x,y,1,n);
        cout << ans[1] << endl;
    }
    return 0;
}