#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pll pair<ll,ll>
#define ppll pair<ll, pll>
using namespace std;
const int maxn = 1100;
ll n, x;
vector<pll>v;
 
pll sum2(int li, int ri, int forb, ll x) {
	if(ri - li + 1 < 2) return mp(-1, -1);
	while(li < ri) {
		if(li == forb) li++;
		if(ri == forb) ri--;
 
		if(v[li].f + v[ri].f == x)
			return mp(li, ri);
		else if(v[li].f + v[ri].f < x) li++;
		else ri--;
	}
	return mp(-1, -1);
}
 
ppll sum3(int li, int ri, ll x) {
	if(ri - li + 1 < 3) return mp(-1, mp(-1, -1));
 
	for(int i=li;i<=ri;i++) {
		pll curr = sum2(li, ri, i, x - v[i].f);
		if(curr.first != -1) return mp(i, curr);
	}
	return mp(-1, mp(-1, -1));
}
 
int result[4];
 
void recursion(int li, int ri) {
	if(ri - li < 3) return;
 
	int mid = (li + ri) / 2;
 
	for(int i=li;i<=mid;i++) {
		for(int j=i+1;j<=mid;j++) {
			if(v[i].f + v[j].f < x) {
				pll curr = sum2(mid+1, ri, -1, x - (v[i].f+v[j].f));
 
				if(curr.first != -1) {
					result[0] = i;
					result[1] = j;
					result[2] = curr.f;
					result[3] = curr.s;
				}
			}
		}
 
		ppll curr = sum3(mid+1, ri, x - v[i].f);
 
		if(curr.first != -1) {
			result[0] = i;
			result[1] = curr.f;
			result[2] = curr.s.f;
			result[3] = curr.s.s;
		}
	}
 
	for(int i=mid+1;i<=ri;i++) {
		ppll curr = sum3(li, mid, x - v[i].f);
 
		//cout<<v[i].f<<" - "<<curr.f<<"\n";
 
		if(curr.first != -1) {
			result[0] = i;
			result[1] = curr.f;
			result[2] = curr.s.f;
			result[3] = curr.s.s;
		}
	}
 
 
	if(result[0] == -1) {
		recursion(li, mid);
		recursion(mid+1, ri);
	}
}
 
int main() {
	cin>>n>>x;
	for(int i=0;i<n;i++) {
		ll a;
		cin>>a;
		v.pb(mp(a, i));
	}
 
	sort(v.begin(), v.end());
 
	memset(result, -1, sizeof(result));
	recursion(0, n-1);
 
	if(result[0] == -1) {
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
 
	for(int i=0;i<4;i++) {
		cout<<v[result[i]].s+1<<" ";
	} cout<<"\n";
}
