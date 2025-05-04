#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=3*1e5;
ll subsum[N<<2], pre[N<<2], suf[N<<2], total[N<<2];
 
 
 
void upd( int i,ll value, int node, int l, int r){
    if(r-l==1){
        total[node]=value;
        pre[node]=max(0ll, value);
        suf[node]=max(0ll, value);
        subsum[node]=max(0ll, value);
        return;
    }
    int mid = (l+r)/2;
    if(i<mid) upd(i, value, node<<1, l, mid);
    else upd(i,value, node<<1|1, mid, r);
    total[node]=total[node<<1]+total[node<<1 |1];
    pre[node]= max(pre[node<<1], total[node<<1]+pre[node<<1 |1]);
    suf[node] = max(suf[node<<1 |1], total[node<<1|1]+suf[node<<1]);
    subsum[node]=max(suf[node<<1]+pre[node<<1|1], max(subsum[node<<1], subsum[node<<1|1]));
}
 
int main() {
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
        upd(i,a[i], 1,0,n);
    }
 
    while(m--){
        int k; ll x; cin >> k >> x;
        k--;
        upd(k,x, 1, 0, n);
        cout << subsum[1] << endl;
    }
}
