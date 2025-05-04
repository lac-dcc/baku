/*
 
 
*==================================================*
 
	this program was written by Blaze;
 
*==================================================*
 
 
*/
 
#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
 
#define Blaze signed main(){
 
#define int long long
#define vi vector <int>
#define vii vector <pair<int, int>>;
#define mapi map<int, int >
#define pb push_back
#define sz size()	
#define faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(x) x.begin(), x.end()
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define endl cout << '\n';
#define check cout << "check"; endl
 
using namespace std;
 
const int MOD = 1e9+7;
const int N = 2e5+5;
const int MAX_INT = 1e18+7;
 
int n;
int m;
int a[N];
 
struct node{
	int mx;
	int sum;
	int pref, suf;
	node(){
		mx = sum = mx = pref = suf = 0;
	}
};
 
node merge(const node& l, const node& r){
	node nw;
	nw.sum = l.sum + r.sum;
	nw.pref = max(r.pref + l.sum, l.pref);
	nw.suf = max(l.suf + r.sum, r.suf);
	nw.mx = max(l.mx, max(r.mx, l.suf + r.pref));
	return nw;
}
 
struct segment{
	node tree [4*N];
	void upd(int pos, int val, int v = 1, int tl = 1, int tr = n){
		if(tl == tr){
			tree[v].mx = tree[v].pref = tree[v].suf  = max(0ll, val);
			tree[v].sum = val;
			return;
		}
		int tmid = (tl + tr) / 2;
		if(pos <= tmid){
			upd(pos, val, v+v, tl, tmid);
		}
		else {
			upd(pos, val, v+v+1, tmid+1, tr);
		}
		tree[v] = merge(tree[v+v], tree[v+v+1]);
	}
};
 
segment tr;
 
Blaze
	faster;
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		tr.upd(i, a[i]);
	}
	
	while(m--){
		int pos, val;cin >> pos >> val;
		tr.upd(pos, val);
		cout << tr.tree[1].mx;
		endl
	}
}
