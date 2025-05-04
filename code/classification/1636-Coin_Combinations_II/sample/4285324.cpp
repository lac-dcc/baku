#include<bits/stdc++.h>
using namespace std;
#define int unsigned int 
const int inf  = 1000000000000 ;
const int mod = 1000000007 ;
#define flo double
void init_code(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
 
    #endif // ONLINE_JUDGE
}
class segmentTree{
public:
	vector<int>seg;
public:
	segmentTree(int n){
		seg.resize(4 * n + 1);
	}
 
	void build(int ind , int low , int high , vector<int>&arr){
		if(low == high){
			seg[ind] = arr[low];
 
			return;
		}
 
		int mid = low + (high - low)/2 ;
 
		build(2 * ind + 1 , low , mid , arr);
		build(2 * ind + 2 , mid + 1, high , arr);
		seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
	}
	void update(int ind , int low , int high , int i , int val){
		if(low == high){
			seg[ind] = val ;
			return ;
		}
		int mid = low + (high - low)/2 ;
		if(i <= mid){
			update(2 * ind + 1 , low , mid , i , val);
		}else{
			update(2 * ind + 2 , mid + 1 , high , i , val);
		}
 
		seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
	}
	int query(int ind , int low , int high , int l , int r){
		//no overlap
		if(low > r || high < l)
			return INT_MAX ;
 
		if(low >= l && high <= r)
			return seg[ind];
 
		int mid = low + (high - low)/2 ;
		int left = query(2 * ind + 1 , low , mid , l , r);
		int right = query(2 * ind + 2 , mid + 1 , high , l , r);
 
		return min(left , right) ;
	}
};
class lazyPropgation{
	vector<int>seg;
	vector<int>lazy ;
public:
	lazyPropgation(int n){
		seg.resize(4 * n + 1);
		lazy.resize(4 * n + 1);
	}
 
	void build(int node, int start, int end , vector<int>&arr)
	{
	    if(start == end)
	    {
	        // Leaf node will have a single element
	        seg[node] = arr[start];
	    }
	    else
	    {
	        int mid = (start + end) / 2;
	        // Recurse on the left child
	        build(2*node + 1, start, mid , arr);
	        // Recurse on the right child
	        build(2*node+2, mid+1, end , arr);
	        // Internal node will have the sum of both of its children
	        seg[node] = seg[2*node + 1] + seg[2*node+2];
	    }
	}
	void updateRange(int node, int start, int end, int l, int r, int val)
	{
	    if(lazy[node] != 0)
	    { 
	        // This node needs to be updated
	        seg[node] += (end - start + 1) * lazy[node];    // Update it
	        if(start != end)
	        {
	            lazy[node*2+1] += lazy[node];                  // Mark child as lazy
	            lazy[node*2+2] += lazy[node];                // Mark child as lazy
	        }
	        lazy[node] = 0;                                  // Reset it
	    }
	    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
	        return;
	    if(start >= l and end <= r)
	    {
	        // Segment is fully within range
	        seg[node] += (end - start + 1) * val;
	        if(start != end)
	        {
	            // Not leaf node
	            lazy[node*2 + 1] += val;
	            lazy[node*2+2] += val;
	        }
	        return;
	    }
	    int mid = (start + end) / 2;
	    updateRange(node*2 + 1, start, mid, l, r, val);        // Updating left child
	    updateRange(node*2 + 2 , mid + 1, end, l, r, val);   // Updating right child
	    seg[node] = seg[node*2 + 1] + seg[node*2+2];        // Updating root with max value 
	}
	int queryRange(int node, int start, int end, int l, int r)
	{
	    if(start > end or start > r or end < l)
	        return 0;         // Out of range
	    if(lazy[node] != 0)
	    {
	        // This node needs to be updated
	        seg[node] += (end - start + 1) * lazy[node];            // Update it
	        if(start != end)
	        {
	            lazy[node*2 + 1] += lazy[node];         // Mark child as lazy
	            lazy[node*2+2] += lazy[node];    // Mark child as lazy
	        }
	        lazy[node] = 0;                 // Reset it
	    }
	    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
	        return seg[node];
	    int mid = (start + end) / 2;
	    int p1 = queryRange(node*2 + 1, start, mid, l, r);         // Query left child
	    int p2 = queryRange(node*2 + 2 , mid + 1, end, l, r); // Query right child
	    return (p1 + p2);
	}
};
void solve(){
	int n , val ;
	vector<int>v;
	cin>>n; cin>>val;
	v = vector<int>(n);
	for(int i = 0 ; i < n ;i++)cin>>v[i];
	vector<vector<int>>dp(n+1 , vector<int>(val+1));
	
	for(int i = 0 ; i <= n ; i++){
		dp[i][0] = 1 ;
	}
	for(int i =1 ; i <= n ; i++){
		for(int j = 1; j <= val ;j++){
			dp[i][j] = dp[i-1][j] % mod ;
			if(v[i-1] <= j)
				dp[i][j] += dp[i][j-v[i-1]] % mod;
 
			dp[i][j] %= mod ;
		}
	}
	cout<<dp[n][val] % mod<<endl;
}
signed main(){
	init_code();
	solve();
}
