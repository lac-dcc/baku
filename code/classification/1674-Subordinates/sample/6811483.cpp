#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
using namespace __gnu_pbds;
 
#ifdef karit
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
 
struct insert_root { static uint64_t split_mix64(uint64_t seed) { seed += 0x9E3779B97F4A7C15; seed = (seed ^ (seed >> 30)) * 0xBF58476D1CE4E5B9; seed = (seed ^ (seed >> 27)) * 0x94D049BB133111EB; return seed ^ (seed >> 31); } size_t operator()(uint64_t seed) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return split_mix64(seed + FIXED_RANDOM); } };
 
typedef tree < long long, null_type, less < long long >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
typedef tree < long long, null_type, less_equal < long long >, rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;
typedef tree < long long, null_type, greater < long long >, rb_tree_tag, tree_order_statistics_node_update > reversed_ordered_set;
typedef tree < long long, null_type, greater_equal < long long >, rb_tree_tag, tree_order_statistics_node_update > reversed_ordered_multiset;
 
#define endl '\n'
#define elif else if
#define len(container) (int)container.size()
#define whole(container) container.begin(), container.end()
#define case(index) cout << "Case #" << index << ": "
 
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
const int LEN = (int)1E6 + 10;
//be aware of modulo!
const long long MOD = (int)1E9 + 7;//998244353
const long double PI = acosl(-1.0);
const long long INF = (long long)1E18;
const long long EPS = (long long)1E-18;
 
const int KING[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
const int KNIGHT[8][2] = { {1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1} };
const int BISHOP[28][2] = { {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {-1, -1}, {-2, -2}, {-3, -3}, {-4, -4}, {-5, -5}, {-6, -6}, {-7, -7}, {1, -1}, {2, -2}, {3, -3}, {4, -4}, {5, -5}, {6, -6}, {7, -7}, {-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7} };
const int ROCK[28][2] = { {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-5, 0}, {-6, 0}, {-7, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, -1}, {0, -2}, {0, -3}, {0, -4}, {0, -5}, {0, -6}, {0, -7} };
const int MIRO[10] = { 0, 1, 5, -1, -1, 2, -1, -1, 8, -1 };
 
inline bool is_set_bit(long long operand, int index) { return operand & ((uint64_t)1 << index); }
inline long long set_bit(long long operand, int index) { return operand |= ((uint64_t)1 << index); }
inline long long set_whole_bit(int largest_index) { return ((uint64_t)1 << largest_index) - 1; }
inline long long not_set_bit(long long operand, int index) { return operand &= ~((uint64_t)1 << index); }
inline long long inverse_bit(long long operand, int index) { return operand ^= ((uint64_t)1 << index); }
inline long long inverse_whole_bit(long long operand, int largest_index) { return operand ^= set_whole_bit(largest_index); }
inline int least_significant_set_bit(long long operand) { return operand & (-operand); }
inline bool is_power2(long long operand) { return operand && !(operand & (operand - 1)); }
inline bool compare(const pair < long long, long long > &first_pair, const pair < long long, long long > &second_pair)
{
    if (first_pair.first > second_pair.first)
        return true;
    if (first_pair.first == second_pair.first)
        return first_pair.second < second_pair.second;
    return false;
}
 
inline long long ceiler_partition(long long dividend, long long divisor) { return (dividend + divisor - 1) / divisor; }
//inline int log2_floor(unsigned long long exponent) { return __bit_width(exponent) - 1; }
inline long double logos_base(long long base, unsigned long long exponent) { return log2l(1.0 * exponent) / log2l(1.0 * base); }
inline long long moduli(long long dividend, long long divisor) { return dividend % divisor >= 0 ? dividend % divisor : dividend % divisor + abs(divisor); }
inline long long modular_summation(long long first_summand, long long second_summand, long long modulo) { return moduli(moduli(first_summand, modulo) + moduli(second_summand, modulo), modulo); }
inline long long modular_subtraction(long long subtractor, long long subtracted, long long modulo) { return moduli(moduli(subtractor, modulo) - moduli(subtracted, modulo), modulo); }
inline long long modular_multiplication(long long first_multiplier, long long second_multiplier, long long modulo) { return moduli(moduli(first_multiplier, modulo) * moduli(second_multiplier, modulo), modulo); }
 
long long binary_power(long long base, unsigned long long exponent) { long long result = 1; while (exponent) { if (exponent & 1) result = result * base; base = base * base; exponent >>= 1; } return result; }
long long modular_power(long long base, unsigned long long exponent, long long modulo) { base = moduli(base, modulo); long long result = 1; while (exponent) { if (exponent & 1) result = modular_multiplication(result, base, modulo); base = modular_multiplication(base, base, modulo); exponent >>= 1; } return result; }
long long inverse_modular_power(long long base, long long modulo) { return modular_power(base, modulo - 2, modulo); }
long long modular_partition(long long operand_one, long long operand_two, long long modulo) { return modular_multiplication(operand_one, inverse_modular_power(operand_two, modulo), modulo); }
 
/*vector < int > node_parent(LEN, -1);
vector < int > tree_size(LEN);//rather rank / index
void build_set(int node)
{
    node_parent[node] = node;
    tree_size[node] = 1;
 
    //tree_rank[node] = 0;
    //tree_index[node] = rand();
}
int find_set(int node)
{
    if (node == node_parent[node])
        return node;
    return node_parent[node] = find_set(node_parent[node]);
}
bool unite_set(int first_node, int second_node)
{
    first_node = find_set(first_node);
    second_node = find_set(second_node);
    if(first_node == second_node)
        return false;
    if (tree_size[first_node] < tree_size[second_node])//rather rank / index
        swap(first_node, second_node);
    node_parent[second_node] = first_node;
    tree_size[first_node] += tree_size[second_node];
 
    //if (tree_rank[first_node] == tree_rank[second_node])
        //tree_rank[first_node]++;
    return true;
}*/
 
vector<vector<int>>vg(LEN);
vector<bool>vis(LEN);
vector<int>sub(LEN);
int dfs(int u){
    vis[u]=true;
    int cnt=0;
    for(int v:vg[u]){
        if(!vis[v]){
            cnt++;
            cnt+=dfs(v);
        }
    }
    sub[u]=cnt;
    return cnt;
}
void solve()
{
    cout << fixed << setprecision(20);
    
    int n;
    cin>>n;
    vg[1].push_back(1);
    for(int i=2;i<=n;i++){
        int v;
        cin>>v;
        vg[v].push_back(i);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    for(int i=1;i<=n;i++)
        cout<<sub[i]<<' ';
    cout<<endl;
    return;
}
 
 
int main()
{
    float start = clock();
    ios_base::sync_with_stdio(false);
    //remove in problems with online queries!
    cin.tie(nullptr);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
    #endif
 
    //g++ -std=c++2a -Wl,--stack=268435456 Main.cpp -o Main.exe
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        //case(i);
        solve();
        //if(i != t)
            //cout << endl;
    }
 
    cerr << "Time taken: " << (clock() - start) / CLOCKS_PER_SEC<< " Seconds" << endl;
 
    return 0;
}
