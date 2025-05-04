#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define w(x) ll x; cin>>x; while(x--)
 
    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << " ";
            os << v[i];
            first = false;
        }
        return os;
    }
    
/*-------------------------------------------------*/
 
// read once, read again, think, code
 
    struct SegmentTree {
    	
        vi prefix, sumAll;
        ll sz, n;
    
        void init(ll n) {
            this -> n = n;
            sz = 1;
            while(sz < n) sz <<= 1;
            sz = 2*sz-1;
            prefix.assign(sz,0ll);
            sumAll.assign(sz,0ll);
        }
    
        void build(vi &a, int pos, int l, int r) {
    		if(l == r) {
    			sumAll[pos] = a[l];
    			prefix[pos] = max(a[l], 0ll);
    			return;
    		}
    
    		int mid = (l + r) / 2;
    		build(a,2*pos+1,l,mid);
    		build(a,2*pos+2,mid+1,r);
    		sumAll[pos] = sumAll[2*pos+1] + sumAll[2*pos+2];
    		prefix[pos] = max(prefix[2*pos+1], sumAll[2*pos+1]+ prefix[2*pos+2]);
    	}
    
    	void build(vi &a) {
    		build(a,0,0,n-1);
    	}
    
        void update(ll idx, ll num, ll pos, ll l, ll r) {
            if(l == r) {
                sumAll[pos] = num;
    			prefix[pos] = max(num, 0ll);
                return;
            }
    
            ll mid = (l + r)/2;
            if(idx <= mid) update(idx,num,2*pos+1,l,mid);
            else update(idx,num,2*pos+2,mid+1,r);
            sumAll[pos] = sumAll[2*pos+1] + sumAll[2*pos+2];
    		prefix[pos] = max(prefix[2*pos+1], sumAll[2*pos+1] + prefix[2*pos+2]);
        }
    
        void update(ll idx, ll num) {
            update(idx,num,0,0,n-1);
        }
    
        pii query(ll pos, ll l, ll r, ll ql, ll qr) {
            if(ql > r or qr < l) return {0,0};
            if(ql <= l and r <= qr) return {sumAll[pos], prefix[pos]};
    
            ll mid = (l + r)/2;
            pii left = query(2*pos+1,l,mid,ql,qr);
            pii right = query(2*pos+2,mid+1,r,ql,qr);
            ll sumAll = left.fi + right.fi;
            ll prefix = max(left.se, left.fi + right.se);
            return {sumAll, prefix};
    
        }
    
        pii query(ll ql, ll qr) {
            return query(0,0,n-1,ql,qr);
        }
    
    };
    
    /*
    	seg.init(n);
    	seg.build(a);
    	seg.update(idx,num);
    	seg.query(ql,qr);
    */
 
void solve() {
 
    ll n, q;
    cin >> n >> q;
 
    vi a(n);
    rep(i,n) cin >> a[i];
 
    SegmentTree seg;
    seg.init(n);
    seg.build(a);
 
    while(q--) {
    	int op; cin >> op;
    	if(op == 1) {
    		ll k, num; cin >> k >> num;
    		seg.update(k-1,num);
    	} else {
    		ll a, b; cin >> a >> b;
    		pii ans = seg.query(a-1,b-1);
    		p1(ans.se);
    	}
    }
}
 
 
int main()
{
	fastio;
 
    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif
 
    //w(tc)
    	solve();
	
	return 0;
}
