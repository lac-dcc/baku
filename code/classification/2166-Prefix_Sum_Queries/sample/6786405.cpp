#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define F first
#define S second
#define Cheng0928 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE(a) signed(a.size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
 
using namespace std;
 
const int MN = 2e5;
const int INF = LONG_LONG_MAX;
const int MOD = 1e9 + 7;
 
void NO(){
	cout << "NO\n";
}
 
const int siz = (1 << 19);
 
struct Data{
	int sum;
	int pref;
};
 
struct segment_tree{
	Data node[siz];
	Data merge(Data a, Data b){
		return {a.sum + b.sum, max(a.pref, a.sum+b.pref)};
	}
	void init(int L, int R, int id, vector<Data> &input){
		if(L == R){
			node[id] = input[L];
			return;
		}
		int mm = L + (R - L)/2;
		init(L, mm, id*2, input), init(mm+1, R, id*2+1, input);
		node[id] = merge(node[id*2], node[id*2+1]);
	}
	void update(int L, int R, int id, int p, Data v){
		if(L == R){
			node[id] = v;
			return;
		}
		int mm = L + (R - L)/2;
		if(p <= mm) update(L, mm, id*2, p, v);
		else update(mm+1, R, id*2+1, p, v);
		node[id] = merge(node[id*2], node[id*2+1]);
	}
	Data query(int L, int R, int id, int l, int r){
		if(L >= l && r >= R) return node[id];
		int mm = L + (R - L)/2;
		if(r <= mm) return query(L, mm, id*2, l, r);
		if(l > mm) return query(mm+1, R, id*2+1, l, r);
		return merge(query(L, mm, id*2, l, r), query(mm+1, R, id*2+1, l, r));
	}
};
 
segment_tree seg;
 
void sol(){
    //freopen("cereal.in", "r", stdin);
    //freopen("cereal.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<Data> v(n + 1, {1,1});
	for(int i = 1; i <= n; i++) cin >> v[i].sum, v[i].pref = max(0LL, v[i].sum);
	seg.init(1, n, 1, v);
	while(q--){
		int ty;
		cin >> ty;
		if(ty == 1){
			int x,y;
			cin >> x >> y;
			seg.update(1,n,1,x,{y, max(0LL, y)});
		}
		else{
			int l, r;
			cin >> l >> r;
			auto cou = seg.query(1, n, 1, l, r);
			cout << cou.pref << '\n';
		}
	}
}
 
signed main()
{
    Cheng0928
    /*int t;
    cin >> t;
    //init();
    while(t--) */sol();
    return 0;
}
