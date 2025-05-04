/*
    # Enjoy the journey #
*/
#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target( "popcnt")
#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>
#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L
#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll
#include <bitset>
#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#define _GLIBCXX_FILESYSTEM
#undef __builtin_ctzl
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define pb emplace_back
#define _DEBUG(x) cout<< #x <<" = "<<"\""<< (x) <<"\""<<endl
#define forq(i , a , b) for (int i = (a); i <= (b); ++i)
#define qrof(i , b , a) for (int i = (a); i >= (b); --i)
#define forr(i , b) forq( i , 0 , b - 1 )
#define F first
#define S second
#define IF ->first
#define IS ->second
#define endl '\n'
#define OFF false
#define ON true
#define qqmemset(array , val) memset (array , val , sizeof(array))
#define ALLV(vect) vect.begin() , vect.end()
#define mid ((st + en) / 2)
#define _mid ((_st + _en) / 2)
#define mid1 ((2 * st + en) / 3)
#define mid2 ((2 * en + st) / 3)
#define lef 2 * Node
#define rig lef + 1
#define _lef 2 * _Node
#define _rig _lef + 1
mt19937 rng( chrono::steady_clock::now().time_since_epoch().count() );
#define Ran(a, b) rng() % ( (b) - (a) + 1 ) + (a)
#define Debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
/*
template<
typename Key, // Key type
typename Mapped, // Mapped-policy
typename Cmp_Fn = std::less<Key>, // Key comparison functor
typename Tag = rb_tree_tag, // Specifies which underlying data structure to use
template<
typename Const_Node_Iterator,
typename Node_Iterator,
typename Cmp_Fn_,
typename Allocator_>
class Node_Update = null_node_update, // A policy for updating node invariants
typename Allocator = std::allocator<char> > // An allocator type
class tree;
*/
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl; err(++it, args...);}
 
ll R = 7 + 1e9 , R1 = 19491001 , R2 = 236 , NUMTESTCASE ;
const ll NN = 10 + 100 , KK = 10 + 1e6 , Inverse2 = 500000004 ;
const double pi = acos(-1.0) ;
int di [8] = {1 , 0 , -1 , 0  , 1 , -1 , 1  , -1 } , dj [8] = {0 , 1 , 0  , -1 , 1 , -1 , -1 , 1  } ;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n , x , k ;
    cin >> n >> k ;
    vector <vector<int>> dp (2 , vector <int> (k + 1)) ;
    dp [0][0] = 1 ;
    for (int i = 1 ; i <= n ; i ++){
        cin >> x ;
        for (int p = 0 ; p <= k ; p ++) {
            dp [i & 1][p] = ((p - x >= 0 ? dp [i & 1][p - x] : 0) + dp [i & 1 ^ 1][p]) ;
            if (dp [i & 1][p] >= R)
                dp [i & 1][p] -= R ;
        }
    }
    cout << dp [n & 1][k] ;
    return 0;
}
