// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
// #pragma GCC optimize("unroll-loops")
		
#include <bits/stdc++.h>
using namespace std;
 
typedef long long lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<pair<lli , lli>> vpll;
typedef vector<pair<ld , ld>> vplld;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
typedef vector<lli> vl;
typedef pair<lli,lli> pll;
typedef priority_queue<lli> pq;
typedef priority_queue<pair<lli,lli>> pqp;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl;
#define printarr(a , n) for(int i = 0 ; i < n  ;i ++) cout << a[i] << " "; cout << endl;
#define endl '\n'
#define sq(a) (a)*(a)
#define yes  cout << "YES" << endl;
#define no  cout << "NO" << endl;
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define inf 1e18
/*
	order_of_key(x) -> number of elements strictly smaller than x
	find_by_order(k) -> kth element 
 
	---------------------------------------------
	Think reverse -> graph problems
	Try converting into new operation
	graph trav , scc , topo , floyd ,  .... 
	copy code check
	index bounds
	maxsz
	set low , up bound be carefull
*/
 
 
 
 
 
struct node
{
	lli val;
	lli pref;
	lli suff;
	lli sz;
	lli sum;
};
 
struct segtree
{
	int size;
	vector<struct node> values;
	// initial here
	struct node empty_node = {0,0,0,0,0};
 
	void init(int n)
	{
		size = 1;
		while(size < n) size*=2;
		values.assign(2*size , empty_node);
	}
 
	struct node merge(struct node p1 , struct node p2)
	{
		struct node merge_node;
		// operation here
 
		merge_node.val = max(max(p1.val , p2.val) , p1.suff + p2.pref);
		merge_node.sz = p1.sz + p2.sz;
		merge_node.pref=  max(p1.pref , p1.sum + p2.pref);
		merge_node.suff=  max(p2.suff , p2.sum + p1.suff);
		merge_node.sum = p1.sum + p2.sum;
		return merge_node;
	}
 
	void set(int i , lli v , int x , int  lx , int rx)
	{
		if(rx  - lx == 1)
		{
			values[x].val = v;
			values[x].pref = v;
			values[x].suff = v;
			values[x].sz = 1;
			values[x].sum = v;
 
			return;
		}
 
		int m = (lx + rx)/2;
		if( i < m)
		{
			set(i , v , 2*x + 1 , lx , m);
		}
		else
		{
			set(i , v , 2*x + 2 , m , rx);
		}
 
		values[x] = merge(values[2*x+1] , values[2*x+2]);
	}
 
	void set(int i , lli v)
	{
		set(i , v, 0 , 0 , size);
	}
 
	struct node range_calc(int l , int r , int x , int lx , int rx)
	{
		if(lx >= r || l >= rx) return empty_node;
		if(l <= lx && r >= rx) return values[x];
		int m = (lx + rx)/2;
 
		struct node s1 = range_calc(l , r , 2*x+1 , lx , m);
		struct node s2 = range_calc(l , r , 2*x+2 , m , rx);
		
		return merge(s1 , s2);
	}
	lli range_calc(int l , int r)
	{
		return range_calc(l , r , 0 , 0 , size).val;
	}
 
 
	vl combine(vl a , vl b)
	{
		while(b.size())
		{
			a.pb(b[b.size()-1]);
			b.pop_back();
		}
		return a;
	}
 
	vl find_all_index(int l , int r , lli v , int x , int lx , int rx)
	{
		if(lx >= r || l >= rx) return {};
		
		int m = (lx + rx)/2;
		if(values[x].val < v)
		{
			return {};
		}
 
		if(rx - lx == 1)
		{
			return {lx};
		}
 
		return combine(find_all_index(l , r , v ,  2*x+1 , lx , m) , find_all_index(l , r , v , 2*x+2 , m , rx));
	}
 
	vl find_all_index(int l , int r , lli v)
	{
		return find_all_index(l , r ,  v , 0 , 0 , size);
	}
 	
 
	int find_first_index(int l , int r , lli v , int x , int lx , int rx)
	{
		if(lx >= r || l >= rx) return -1;
		
		int m = (lx + rx)/2;
 
		if(rx - lx == 1)
		{
			if(values[x].val >= v) return lx;
			return -1;
		}
 
		if(l <= lx && r >= rx)
		{
			if(values[2*x+1].val >= v)
			{
				return find_first_index(l , r , v ,  2*x+1 , lx , m);
			}
			else if(values[2*x+2].val >= v)
			{
				return find_first_index(l , r , v ,  2*x+2 , m , rx);
			}
			else
			{
				return -1;
			}
		}
 
		int ans1  = find_first_index(l , r , v ,  2*x+1 , lx , m);
		if(ans1 != -1) return ans1;	
		
		return find_first_index(l , r , v , 2*x+2 , m , rx);
	}
 
	int find_first_index(int l , int r , lli v)
	{
		return find_first_index(l , r ,  v , 0 , 0 , size);
	}
 
 
};
 
 
void solve(){
 
	lli n , m;
	cin >> n >> m;
	vl arr(n);
 
	segtree ss;
	ss.init(n);
 
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> arr[i];
		ss.set(i , arr[i]);
	}
 
 
	// for(int i = 0; i < n ; i ++) 
	// {
	// 	cout << ss.get(i) << " "; 
	// }
	// cout << endl;
 
	while(m--)
	{
		lli a , b;
		cin >> a >> b;
		ss.set(a-1,b);
 
		cout << max(0ll , ss.range_calc(0 , n)) << endl;
		
	}
 
 
}
int main(){
 
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif
 
	//int t;cin>>t; while(t--)
    
    solve();
	
	return 0;
}
