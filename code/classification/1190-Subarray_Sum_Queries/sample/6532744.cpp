#include<bits/stdc++.h>
 
using namespace std ;
 
#define FOR(i,l,r) for(int i=l;i<=r;++i)
#define FORD(i,r,l) for(int i=r;i>=l;--i)
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
#define MASK( x ) ( 1LL << ( x ) )
#define c_bit( x ) __builtin_popcountll( x )
#define BIT( x , i ) ( ( x >> i ) & 1 )
#define ON_BIT( x , i ) ( ( x ) | MASK(i) )
#define OFF_BIT( x , i ) ( ( x ) & ~( MASK ( i ) ) )
#define INV_BIT( x , i ) ( ( x ) ^ ( MASK ( i ) ) )
#define c_lz( x ) __builtin_clz( x )
#define c_tz( x ) __builtin_ctz( x )
 
typedef long long ll ;
typedef unsigned long long ull ;
typedef vector < int > arr1 ;
typedef vector < arr1 > arr2 ;
typedef vector < arr2 > arr3 ;
typedef pair < int , int > pii ;
 
const int maxn = 2e5 + 9 ;
const int N = 1e5 + 9 ;
const ll inf = 1e18 ;
const ll mod = 1e9 + 7 ;
const int base = 31 ;
const int lim = 131 ;
 
int n , q ;
ll a[maxn] ;
 
struct Data
{
    ll sum = 0 , pre = 0 , suf = 0 , best = 0 ;
};
 
Data st[maxn<<2] ;
 
Data combine( Data a , Data b )
{
    Data x ;
 
    x.sum = a.sum + b.sum ;
 
    x.pre = max( a.pre , a.sum + b.pre ) ;
    x.suf = max( b.suf , b.sum + a.suf ) ;
 
    x.best = max( { a.best , b.best , a.suf + b.pre } ) ;
 
    return x ;
}
 
void build( int id , int l , int r )
{
    if( l == r )
    {
        st[id].sum = a[l] ;
        st[id].pre = max( (ll)0 , a[l] ) ;
        st[id].suf = max( (ll)0 , a[l] ) ;
        st[id].best = max( (ll)0 , a[l] ) ;
 
        return ;
    }
 
    int mid = ( l + r ) >> 1 ;
 
    build( id << 1 , l , mid ) ;
    build( id << 1 | 1 , mid + 1 , r ) ;
 
    st[id] = combine( st[id<<1] , st[id<<1|1] ) ;
}
 
void update( int id , int l , int r , int pos , ll val )
{
    if( l > pos || r < pos ) return ;
 
    if( l == r )
    {
        st[id].sum = val ;
        st[id].pre = max( (ll)0 , val ) ;
        st[id].suf = max( (ll)0 , val ) ;
        st[id].best = max( (ll)0 , val ) ;
 
        return ;
    }
 
    int mid = ( l + r ) >> 1 ;
 
    update( id << 1 , l , mid , pos , val ) ;
    update( id << 1 | 1, mid + 1 , r , pos , val ) ;
 
    st[id] = combine( st[id<<1] , st[id<<1|1] ) ;
}
 
int main()
{
    faster
 
    cin >> n >> q ;
 
    FOR(i,1,n) cin >> a[i] ;
 
    build( 1 , 1 , n ) ;
 
    while( q-- )
    {
        int k ; ll x ;
 
        cin >> k >> x ;
 
        update( 1 , 1 , n , k , x ) ;
 
        cout << st[1].best << '\n' ;
    }
}
