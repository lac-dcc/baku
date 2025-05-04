#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define L(i) (2*i)
#define R(i) (2*i+1)
 
struct Data{
	ll sum[4];
	Data(ll a=-1):sum{max(0ll,a),max(0ll,a),max(0ll,a),a}{};
	Data(ll a,ll b,ll c,ll d):sum{a,b,c,d}{}
};
 
struct SegmentTree{
	int N;
	vector<Data>data;
	SegmentTree(vector<int>a):N(1<<int(1+log2(a.size()))),data(2*N){
		for(int i=N;i<N+a.size();++i)data[i]=Data(a[i-N]);
		for(int i=N-1;i>=1;--i)data[i]=merge(data[L(i)],data[R(i)]);
	}
	Data merge(Data l,Data r){
		return Data(max(l.sum[0],l.sum[3]+r.sum[0]),
								max({l.sum[2]+r.sum[0],l.sum[1],r.sum[1]}),
								max(l.sum[2]+r.sum[3],r.sum[2]),
								l.sum[3]+r.sum[3]);
	}
	ll update(int idx,int val){return update(0,N,1,idx,val).sum[1];}
	Data update(int l,int r,int idx,int t,int val){
		if(l+1==r)return data[idx]=Data(val);
		int m=(l+r)/2;
		if(t<m)update(l,m,L(idx),t,val);
		else update(m,r,R(idx),t,val);
		data[idx]=merge(data[L(idx)],data[R(idx)]);
		return data[idx];
	}
};
 
 
signed main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n,m;cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	SegmentTree st(a);
	while(m--){
		int k,a;cin>>k>>a;
		cout<<st.update(k-1,a)<<"\n";
	}
}
