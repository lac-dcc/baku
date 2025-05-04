#include <iostream>
#include <vector>
#include <limits>
 
using namespace std;
 
template<typename T>
class Segment_tree {
public:
    Segment_tree(vector<T>& data) 
        :n((int)data.size()), tn(4*(int)data.size()+1),
        lo(vector<int>(tn)),
        hi(vector<int>(tn)),
        mx(vector<T>(tn,0)),
        lazy(vector<T>(tn,0))
    {
        init(1,0,n-1,data);
    }
    
    Segment_tree(const Segment_tree&) = delete;
    Segment_tree& operator=(const Segment_tree&) = delete;
 
    void range_update(int l, int r, T val)
    {
        range_update(1,l,r,val); 
    }
 
    T query_max(int l, int r)
    {
        if (l>r) return std::numeric_limits<T>::min();
        return query_max(1,l,r);
    }
 
    T query_point(int k)
    {
        if (k<0) return 0;
        return query_point(1,k);
    }
 
private:
    int n;
    int tn;
    vector<int> lo,hi;
    vector<T> mx;
    vector<T> lazy;
    
    void init(int v, int l, int r, const vector<T>& data)
    {
        lo[v] = l;
        hi[v] = r;
        if (l==r) {
            mx[v] = data[l];
            return;
        }
        int m = (l+r)/2;
        init(2*v,l,m,data);
        init(2*v+1,m+1,r,data);
        update_step(v);
    }
    
    void prop(int v)
    {
        lazy[2*v] += lazy[v];
        lazy[2*v+1] += lazy[v];
        lazy[v] = 0;
    }
 
    void update_step(int v)
    {
        mx[v] = std::max(mx[2*v]+lazy[2*v],mx[2*v+1]+lazy[2*v+1]);
    }
    
    void range_update(int v, int l, int r, T val)
    {
        if (lo[v]>r || hi[v]<l) 
            return;
        if (lo[v]>=l && hi[v]<=r) {
            lazy[v] += val;
            return;
        }
        prop(v);
        
        range_update(2*v,l,r,val);
        range_update(2*v+1,l,r,val);
 
        update_step(v);
    }
 
    T query_max(int v, int l, int r)
    {
        if (lo[v]>r || hi[v]<l) 
            return std::numeric_limits<T>::min();
        if (lo[v]>=l && hi[v]<=r) 
            return mx[v]+lazy[v];
        prop(v);
        
        T left = query_max(2*v,l,r);
        T right = query_max(2*v+1,l,r);
 
        update_step(v);
 
        return std::max(left,right);
    }
 
    T query_point(int v, int k)
    {
        if (lo[v]==hi[v]) {
            return mx[v]+lazy[v];
        }
        int m = (lo[v]+hi[v])/2;
        prop(v);
        T val = 0;
        if (k<=m) {
            val = query_point(2*v,k);
        } else {
            val = query_point(2*v+1,k);
        }
        update_step(v);
        return val;
    }
};
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,q; cin >> n >> q;
    vector<long long> v(n);
    vector<long long> pref_sum(n); // 0 indexed
    for (auto& i:v)
        cin >> i;
 
    pref_sum[0] = v[0];
    for (int i=1; i<n; ++i) { 
        pref_sum[i] = pref_sum[i-1]+v[i];
    }
 
    Segment_tree<long long> tree(pref_sum);
 
    while (q--) {
        int x; cin >> x;
        switch (x) {
            case 1: {
                int k,u; cin >> k >> u;
                --k;
                long long val = u-v[k];
                tree.range_update(k,n-1,val);
                v[k] = u;
                break;
            }
            case 2: {
                int a,b; cin >> a >> b;
                --a; --b;
                cout << std::max(tree.query_max(a,b)-tree.query_point(a-1), 0LL) << '\n';
                break;
            }
        }
 
    }
 
 
    return 0;
}
