// "el sol sale incluso despues de la noche mas oscura"
#include<bits/stdc++.h>
using namespace std ;
#define int long long
#define double long double 
#define endl "\n"
#define PB push_back  
#define F first 
#define S second 
#define vvi vector<vector<int>>
#define sz(a) (int)a.size()
#define all(a)   a.begin() , a.end()  
#define allr(a)   a.rbegin() , a.rend()  
#define YES {cout<<"YES\n";return;} 
#define NO {cout<<"NO\n";return;} 
#define mem(a,x) memset(a,x,sizeof(a))
#define PI 3.14159265
 
pair<int , int> dir[4]={{1 ,0},{-1 ,0} ,{0 ,1} ,{0 ,-1}};
 
inline void io(){ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 }
void PV(vector<int> v) { for (int i = 0 ; i < sz(v) ; i++) cout << v[i]  << " " ; cout << endl;}
void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] <<" "  ; cout << endl;}
void IA(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
//**********************************************************************************************************************************************************************************
const int N = 2e6 + 2, N1 = 1e9+7, MOD = 1e9+7 , INF = (1e15 + 7) ; // 10000
map<int, int> I;
int dp[N], st[4*N], stn;
void update(int i, int l, int r, int p, int val) {
    if(p < l or p > r) return;
    if(l == r and l == p){
        st[i] = val;
        dp[p] = val;
        return;
    }
    int md = (l + r) / 2;
    update(2*i+1, l, md, p, val);
    update(2*i+2, md + 1, r, p, val);
    st[i] = max(st[2*i+1], st[2*i+2]);
}
int tellmax(int i, int l, int r, int ql, int qr) {
    if(ql <= l and r <= qr) return st[i];
    if(ql > r or qr < l) return -1;
    int md = (l + r) / 2;
    int res = tellmax(2*i+1, l, md, ql, qr);
    res = max(res, tellmax(2*i+2, md+1, r, ql, qr) );
    return res;
}
 
bool const comp(const vector<int>& a, const vector<int>& b) {
    if(a[1] < b[1]) return true;
    if(a[1] > b[1]) return false;
    return a[0] < b[0];
}
void solve() {
    int n; cin >> n;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    sort(v.begin(), v.end(), comp);
    {
        set<int> coco;
        for(auto i: v) {
            coco.insert(i[0]-1);
            coco.insert(i[1]);
        }
        int x = 0;
        stn= coco.size();
        while(!coco.empty()) {
            I[*coco.begin()] = x++;
            coco.erase(coco.begin());
        }
    }
    for(auto i: v) {
        int previou_max = tellmax(0, 0, stn, 0, I[i[0]-1]);
        int cur_value = dp[I[i[1]]];
        if(cur_value < previou_max + i[2]) {
            update(0, 0, stn, I[i[1]], previou_max + i[2]);
        }
    }
 
    cout << tellmax(0, 0, stn, 0, stn);
 
}
 
 
signed main () {
    ios_base::sync_with_stdio(false);cin.tie(0); 
    io();    
    int t1 = 1 , x0=1 ;
    // cin >> t1 ;
    // cout << fixed << setprecision(9);
    while(t1--){   
        // cout <<"Case #"<<x0++<<": ";
        solve() ;
    }    
}  
