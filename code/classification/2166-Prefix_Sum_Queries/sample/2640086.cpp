/*
 
                       _oo0oo_ 
                      o8888888o 
                      88" . "88 
                      (| -_- |) 
                      0\  =  /0 
                    ___/`---'\___ 
                  .' \\|     |// '. 
                 / \\|||  :  |||// \ 
                / _||||| -:- |||||- \ 
               |   | \\\  -  /// |   | 
               | \_|  ''\---/''  |_/ | 
               \  .-\__  '-'  ___/-. / 
             ___'. .'  /--.--\  `. .'___ 
          ."" '<  `.___\_<|>_/___.' >' "". 
         | | :  `- \`.;`\ _ /`;.`/ - ` : | | 
         \  \ `_.   \_ __\ /__ _/   .-` /  / 
     =====`-.____`.___ \_____/___.-`___.-'===== 
                       `=---=' 
keep calm and don't hurt the computer.
created by -> Prakhar
Fri Aug 06 2021
*/
#include"bits/stdc++.h"
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
#define int ll
#ifdef int
#define INF 1000000000000000000 //1e18
#else
#define INF 1000000000  //1e9
#endif
 
#define ll long long
#define ull unsigned ll
#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626
map<int,int> Factorize(int n){map<int,int> result;int i=2;while(i*i<=n){while(n%i==0)result[i]++,n/=i;i++;}if(n>1)result[n]++;return result;}
int bin_exp(int a,int b){int result = 1;while(b){if(b&1)result*=a;a*=a;b>>=1;}return result;}
const int mod = 1'000'000'007; //1e9+7
const int N = 2e5+5;
 
template<class T> class SegmentTree{
    
    public:
        SegmentTree(std::vector<T> data , T (*combine)(T , T));
        SegmentTree(T data[] , int n , T (*combine)(T obj1 , T obj2));
        T query(int l , int r);
        void update(int idx , T val);
 
    private:
        T* m_tree;
        int m_n;
        T (*m_combine)(T , T);
        void build(int v , int tl , int tr , T* arr);
        T queryHelper(int v , int tl , int tr , int l , int r);
        void updateHelper(int v , int tl , int tr , int idx , T val);
};
 
template<class T> SegmentTree<T>::SegmentTree(std::vector<T> data , T (*combine)(T , T))
{
    m_combine = combine;
    m_n = data.size();
    m_tree = new T[4 * m_n];
    build(0 , 0 , m_n - 1, data.data());
}
 
template<class T> SegmentTree<T>::SegmentTree(T* data , int n , T (*combine)(T obj1 , T obj2))
{
    m_combine = combine;
    m_n = n;
    m_tree = new T[4 * m_n];
    build(0 , 0 , m_n - 1, data);
}
 
template<class T> T SegmentTree<T>::query(int l , int r)
{
    return queryHelper(0 , 0 , m_n - 1 , l , r);
}
 
template<class T> void SegmentTree<T>::update(int idx , T val)
{
    return updateHelper(0 , 0 , m_n - 1 , idx , val);
}
 
template<class T> void SegmentTree<T>::build(int v , int tl , int tr , T* arr)
{
    if(tl == tr)
    {
        m_tree[v] = arr[tl];
    }
    else
    {
        int tm = tl + (tr - tl) / 2;
        build(2 * v + 1 ,  tl , tm , arr);
        build(2 * v + 2 , tm+1 , tr , arr);
        m_tree[v] = m_combine(m_tree[2*v + 1] , m_tree[2*v + 2]);
    }
    return;
}
 
template<class T> T SegmentTree<T>::queryHelper(int v , int tl , int tr , int l , int r)
{
    if(l == tl && r == tr)
        return m_tree[v];
    int tm = tl + (tr - tl) / 2;
    if(l <= std::min(tm , tr) && std::max(l , tm + 1) <= r)
        return m_combine(queryHelper(2 * v + 1, tl , tm , l , std::min(tm , r)) , queryHelper(2 * v + 2 , tm + 1 , tr , std::max(l , tm + 1) , r));
    else if(l <= std::min(tm , r))
            return queryHelper(2 * v + 1, tl , tm , l , std::min(tm , r));
        else if(std::max(l , tm + 1) <= r)
            return queryHelper(2 * v + 2 , tm + 1 , tr , std::max(l , tm + 1) , r);
    assert(false);
}
 
template<class T> void SegmentTree<T>::updateHelper(int v , int tl , int tr , int idx , T val)
{
    if(tl == tr)
    {
        m_tree[v] = val;
    }
    else{
        int tm = tl + (tr - tl) / 2;
        if(idx <= tm)
            updateHelper(2 * v + 1 , tl , tm , idx , val);
        else
            updateHelper(2 * v + 2 , tm + 1 , tr , idx , val);
        m_tree[v] = m_combine(m_tree[2 * v + 1] , m_tree[2 * v + 2]);
    }
    return;
}
 
struct Node{
    int maxSum , total;
};
 
Node combine(Node a , Node b)
{
    return {max(a.maxSum , a.total + b.maxSum) , a.total + b.total};
}
 
int solve()
{
    int n , q;
    cin >> n >> q;
    vector<Node> a;
    rep(i,n)
    {
        int x;
        cin >> x;
        a.push_back({x , x});
    }
    SegmentTree<Node> tree(a , combine);
    while(q--)
    {
        int t , x , y;
        cin >> t >> x >> y;
        if(t == 1)
        {
            tree.update(x - 1 , {y , y});
        }   
        else{
            auto res = tree.query(x - 1 , y - 1);
            cout << max(res.maxSum , 0LL) << "\n";
        }
    }
 
    return 0;
}
int32_t main()
{
    cin.tie(nullptr) -> sync_with_stdio(false);
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
