#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define forsn(i, s, n) for(int i = s; i < n; ++i)
#define dforn(i, n) for(int i = n-1; i >= 0; --i)
#define DBG(x) cout << #x << " = " << x << endl;
typedef pair<int, int> pii;
 
typedef pair<long long,long long> T;
 
struct segtree{
	vector<T> st;
	int n;
	T neutro = {0,-1e18};
	
	segtree(vector<long long> &v){
		n = v.size();
		st.assign(4*n, neutro);
		build(1, 0, n-1, v);
	}
	
	void build(int p, int L, int R, vector<long long>&v){
		if(L == R){
			
			st[p]  = {v[L],v[L]};
			
		}
		else{
			int m = (L+R)/2, l = 2*p, r = 2*p+1;
			build(l, L, m, v);
			build(r, m+1, R, v);
 
			long long f = st[l].F + st[r].F;
			st[p] = {
				f,
				max(st[l].S, st[l].F+st[r].S)
			};
			
			
		}
	}
	
	void print(){
		for(auto i : st){
			cout<<i.F<<" - "<<i.S<<endl;
		}
		cout<<endl;
	}
	
	T query(int i, int j){
		return query(1, 0, n-1, i, j);
	}
	
	
	T query(int p, int L, int R, int i, int j){
 
		if(R < i || L > j) {
			return neutro;
		}
		if( i <= L && R <= j){
			return st[p];
		}
		int m = (L+R)/2, l = 2*p, r = 2*p+1;
		T lf = query(l, L, m, i, j);
		T rg = query(r, m+1, R, i, j);
 
		
		long long f = lf.F + rg.F;
		long long prf = max(lf.S, lf.F+rg.S);
 
		return {f,prf};
		
	}
	
	void update(int i, long long value){
		update(1, 0, n-1, i, value);
	}
	
	void update(int p, int L, int R, int i, long long value){
		if(R < i || L > i){
			return;
		}
		if(i <= L && R <= i){
			st[p] = {value,value};
		}else{
			int m = (L+R)/2, l = 2*p, r = 2*p+1;
			update(l, L, m, i, value);
			update(r, m+1, R, i, value);
 
			
			long long f = st[l].F + st[r].F;
			st[p] = {
				f,
				max(st[l].S, st[l].F+st[r].S)
			};
 
		}
		
	}
};
 
int main(){
	fastIO;
	int n, q;
	cin>>n>>q;
	vector<long long> v(n);
 
 
	forn(i,n)cin>>v[i];
		segtree st(v);
			//st.print();
	while(q--){
		int m,l,r;
		cin>>m>>l>>r;
		if(m==2){
			T res = st.query(l-1,r-1);
			if(res.S < 0)cout<<0<<endl;
			else cout<<res.S<<endl;
		}else{
			st.update(l-1,r);
			// st.print();
		}
	}
	
	return 0;
}
 
