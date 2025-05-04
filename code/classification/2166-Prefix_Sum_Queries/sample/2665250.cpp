#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN = 2e5+10, M = 1e9+7; 
int n, q; 
ll x[mxN];
 
struct node{
    ll sum, pref; 
    friend node operator+(const node& a, const node& b){
        return {a.sum + b.sum, max(a.pref, a.sum + b.pref)};
    }
}st[4*mxN];
 
void build(int l = 0, int r = n-1, int i = 1){
    if(l == r){
        st[i].sum = st[i].pref = x[l]; 
        st[i].pref = max(0LL, x[l]);
        return; 
    }
    int m = (l+r)/2;
    build(l, m, 2*i); 
    build(m+1, r, 2*i+1);
    st[i] = st[2*i] + st[2*i+1];
}
 
void upd(int l, ll val, int i = 1, int l2 = 0, int r2 = n-1){
    if(l2 == r2){
        st[i].sum = st[i].pref = val;
        st[i].pref = max(0LL, val);
        return; 
    }
    int m2 = (l2+r2)/2; 
    if(l <= m2){
        upd(l, val, 2*i, l2, m2); 
    }else{
        upd(l, val, 2*i+1, m2+1, r2);
    }
    st[i] = st[2*i] + st[2*i+1];
}
 
node qry(int l1, int r1, int i = 1, int l2 = 0, int r2 = n-1){
    if(l2 > r1 || r2 < l1){
        return {0, 0};
    }
    if(l1<=l2 && r2 <= r1){
        return st[i];
    }
    int m2 = (l2+r2)/2; 
    return qry(l1, r1, 2*i, l2, m2) + qry(l1, r1, 2*i+1, m2+1, r2); 
}
 
int main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
 
    cin >> n >> q; 
    for(int i = 0; i<n; ++i){
        cin >> x[i]; 
    }   
    build(); 
    while(q--){
        int qt; 
        cin >> qt; 
        if(qt == 1){
            int k, u; 
            cin >> k >> u, --k; 
            upd(k, u);
        }else{
            int a, b; 
            cin >> a >> b, --a, --b; 
            cout << qry(a, b).pref << "\n";
        }
    }
}
