/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Prefix Sum Queries
	Link: https://cses.fi/problemset/task/2166
	Online Judge: CSES
	Idea: Use a SegmentTree that can store the best sum of a prefix in the interval.
    The one used here is a SegmentTree that allows to solve an ever greater problem    
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 2e5 + 3;
 
int n, m, k, x, q, u, a, b;
ll arr[lim];
 
// >> SEGMENT TREE
struct node
{
	ll sum; // sum of all values in the interval
	ll bestSum; // best sum of the interval
	ll bestLeft; // best sum of a prefix in the interval
	ll bestRight; // best sum of a sufix in the interval
 
	node(){sum = bestLeft = bestRight = bestSum = 0;}
	node(ll sm, ll bs, ll bl, ll br)
	{ sum = sm; bestSum = bs; bestLeft = bl; bestRight = br; }
};
node t[lim << 2];
 
node merge(node leNode, node riNode)
{
    node ret;
	ret.sum = leNode.sum + riNode.sum;
	ret.bestSum = max(leNode.bestSum, riNode.bestSum);
 
	if(leNode.bestRight + riNode.bestLeft > ret.bestSum)
		ret.bestSum = leNode.bestRight + riNode.bestLeft;
 
	ret.bestLeft = max(leNode.bestLeft, leNode.sum + riNode.bestLeft);
	ret.bestRight = max(riNode.bestRight, riNode.sum + leNode.bestRight);
 
	return ret;
}
 
void buildTree(int idx, int L, int R)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{
		t[idx] = node(arr[L], arr[L], arr[L], arr[L]);
		return;
	}
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);
	// merge
	t[idx] = merge(t[le], t[ri]);
}
 
void update(int idx, int L, int R, int ii, int upd)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{
		arr[L] = upd;
		t[idx] = node(arr[L], arr[L], arr[L], arr[L]);
		return;
	}
	if(ii <= mid)
		update(le, L, mid, ii, upd);
	else 
		update(ri, mid + 1, R, ii, upd);
	// merge
	t[idx] = merge(t[le], t[ri]);
}
 
node retrieve(int idx, int L, int R, int QL, int QR)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L >= QL && R <= QR)
		return t[idx];
	if(L > QR || R < QL)
		return node(-inf, -inf, -inf, -inf);
 
	node leNode = retrieve(le, L, mid, QL, QR);
	node riNode = retrieve(ri, mid + 1, R, QL, QR);
 
	if(riNode.sum == -inf)
		return leNode;
	if(leNode.sum == -inf)
		return riNode;
 
	node ret = merge(leNode, riNode);
 
	return ret;
}
// << SEGMENT TREE
 
void solve()
{
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	buildTree(0, 0, n - 1);
 
	while(q--)
	{
		cin >> x >> a >> b;
		if(x == 1)
		{
			a--;
			update(0, 0, n - 1, a, b);
		}
		else
		{
			a--; b--;
			node answ = retrieve(0, 0, n - 1, a, b);
			cout << max(0ll, answ.bestLeft) << endl;
		}		
	}
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
 
	if(fopen("c:\\Competitive Programming\\lmo.in","r") != NULL)
	{
		freopen("c:\\Competitive Programming\\lmo.in","r",stdin);
	}
	else if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}
