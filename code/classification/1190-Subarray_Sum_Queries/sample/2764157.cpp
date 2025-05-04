#include <bits/stdc++.h>
#define fo(i,m,n) for(int i = m; i <= n; i++)
#define fod(i,m,n) for(int i = m; i >= n; i--)
#define fov(i,x) for(auto &i : x)
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
const int N = 2e5+7;
struct Node
{
	i64 ans;
	i64 sum;
	i64 max_left;
	i64 max_right;
};
Node Merge(Node x, Node y)
{
	Node z;
	z.ans = max(x.ans,y.ans);
	z.ans = max(z.ans,x.max_right+y.max_left);
	z.sum = x.sum + y.sum;
	z.max_left = max(x.max_left,x.sum+y.max_left);
	z.max_right = max(x.max_right+y.sum,y.max_right);
	return z;
}
int n,m;
i64 zero = 0, inf = 1e14;
Node seg[N << 2];
void Update(int pos, int L, int R, int x, Node val)
{
	if(x < L || x > R) return;
	if(L == R)
	{
		seg[pos] = val;
		return;
	}
	int mid = (L+R) >> 1;
	Update(pos<<1,L,mid,x,val);
	Update(pos<<1|1,mid+1,R,x,val);
	seg[pos] = Merge(seg[pos<<1],seg[pos<<1|1]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fo(i,1,n)
	{
		i64 x,y; cin >> x;
		y = max(zero,x);
		Update(1,1,n,i,{y,x,y,y});
	}
	while(m--)
	{
		i64 pos,x; cin >> pos >> x;
		i64 y = max(zero,x);
		Update(1,1,n,pos,{y,x,y,y});
		cout << seg[1].ans << '\n';
	}
}
