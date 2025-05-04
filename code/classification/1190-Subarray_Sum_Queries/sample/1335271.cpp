/*
    Code written by Talant I.D.
*/
  
#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
  
#define precision(n) fixed << setprecision(n)
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define eps (double)1e-9
#define PI 2*acos(0.0)
#define endl "\n"
#define sz(v) int((v).size())
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define do_not_disturb ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define OK cout << "OK" << endl;
  
inline bool isvowel(char ch){
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
  
inline bool isprime(int n){
    if(n < 2 || (n%2 == 0 && n != 2)) return false;
    for(int i = 3; i*i <= n; i++)
        if(n%i == 0) return false;
    return true;
}
 
class Union{
    private:
        vector <int> saizu, link;
    public:
        Union(int n){
            saizu.assign(n, 1); link.resize(n); 
            iota(all(link), 0);
        }
        int find(int n){
            if(link[n] == n) return n;
            return link[n] = find(link[n]);
        }
        int same(int a, int b){
            return find(a) == find(b);
        }
        void unite(int a, int b){
            if(same(a, b)) return;
             
            a = find(a); b = find(b);
            if(saizu[a] < saizu[b]) swap(a, b);
             
            saizu[a] += saizu[b];
            link[b] = a;
        }
        int getsize(int a){
            return saizu[find(a)];
        }
};
 
const int mod = 1e9+7;
 
ll mode(ll a){
    a %= mod;
    if(a < 0) a += mod;
    return a;
}
 
ll subt(ll a, ll b){
    return mode(mode(a)-mode(b));
}
 
ll add(ll a, ll b){
    return mode(mode(a)+mode(b));
}
 
ll mult(ll a, ll b){
    return mode(mode(a)*mode(b));
}
 
ll binpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}
 
vector <ll> vec;
 
struct Node{
    ll val, l, r, sum;
    Node operator + (Node other){
        return {max(max(val, other.val), r+other.l), max(l, sum+other.l), max(other.r, other.sum+r), sum+other.sum}; 
    }
};
 
class Segment_tree{
    private:
        vector <Node> tree;
        //vector <int> lz;
    public:
        Segment_tree(int n){
            tree.resize(n*4);
            //lz.resize(n*4);
        }
        void build(int v, int l, int r){
            if(l == r){
                tree[v] = {max(0ll, vec[l]), max(0ll, vec[l]), max(0ll, vec[l]), vec[l]};
                return;
            }
            int mid = (l+r) >> 1;
            build(v*2, l, mid);
            build(v*2+1, mid+1, r);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
        /*void push(int v, int l, int r){
            if(lz[v]){
                tree[v] += (r-l+1)*lz[v];
                if(l != r){
                    lz[v*2] += lz[v];
                    lz[v*2+1] += lz[v];
                }
                lz[v] = 0;
            }
        }
        int get(int v, int l, int r, int val){
            if(l == r){
                return l;
            }
            int mid = (l+r) >> 1;
            if(tree[v*2] >= val) return get(v*2, l, mid, val);
            else return get(v*2+1, mid+1, r, val);
        }*/
        void update(int v, int l, int r, int pos, ll val){
            if(l == r && l == pos){
                tree[v] = {max(0ll, val), max(0ll, val), max(0ll, val), val};
                return ;
            }
            int mid = (l+r) >> 1;  
            if(pos <= mid) update(v*2, l, mid, pos, val);
            else update(v*2+1, mid+1, r, pos, val);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
        ll get_first(){
            return tree[1].val;
        }
};
 
int main(){
    do_not_disturb
    
    ll n, m;
    cin >> n >> m;
    vec.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> vec[i];
    }
    
    Segment_tree t(n+1);
    t.build(1, 1, n);
    
    while(m--){
        ll x;
        ll y;
        cin >> x >> y;
        t.update(1, 1, n, x, y);
        cout << t.get_first() << endl;
    }
    
    return 0;
}
