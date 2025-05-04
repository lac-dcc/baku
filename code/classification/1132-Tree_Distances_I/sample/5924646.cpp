#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<pii> vii;
 
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); (a)++)
#define FORL(a, b, c) for (ll(a) = (b); (a) < (c); (a)++)
#define pb push_back
#define mp make_pair
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
#define TC(t) while (t--)
 
const ll mod = 1e9 + 7;
 
 
void yes()
{
    cout << "YES" << endl;
}
void no()
{
    cout << "NO" << endl;
}
 
 
class Trie{
    private:
    struct TrieNode {
        bool isEnd = false ;
        TrieNode* children[26] ;
    };
 
    public:
    TrieNode* root ;
 
    Trie() {
        root = new TrieNode() ;
    }
 
    void insert(string word){
        TrieNode* curr = root ;
        for(auto c : word){
            int idx = c - 'a'; 
            if(curr -> children[idx] == NULL){
                curr -> children[idx] = new TrieNode() ;
            }
            curr = curr -> children[idx]; 
        }
        curr -> isEnd = true ;
    }
 
    bool search(string word){
        TrieNode* curr = root ;
        for(auto c : word){
            int idx = c - 'a'; 
            if(curr -> children[idx] == NULL) return false ;
            curr = curr -> children[idx]; 
        }
 
        return curr -> isEnd ;
    }
 
};
 
class DisJointSet {
 
    vector<int> rank , parent , size ;
 
public:
 
    DisJointSet(int n){
        rank.resize(n+1,0) ;
        parent.resize(n+1) ;
        size.resize(n+1,1) ;
        for(int i = 0 ; i <= n ; i++){
            parent[i] = i ;
        }
    }
 
    int findParent(int node){
        if(node == parent[node]) return node ;
        return parent[node] = findParent(parent[node]) ;
    }
 
    void unionByRank(int u , int v){
        int p1 = findParent(u) ;
        int p2 = findParent(v) ;
        if(p1 == p2) return ;
        if(rank[p1] < rank[p2]){
            parent[p1] = p2 ;
        }
        else if(rank[p2] < rank[p1]){
            parent[p2] = p1 ;
        }
        else{
            parent[p1] = p2 ;
            rank[p2]++ ;
        }
    }
 
};
 
int endOne = 1 ;
int endTwo = -1 ;
void dfs1(int node , int par , vector<int> adj[] , int curr , int &dist){
    if(curr > dist){
        endOne = node ;
        dist = curr ;
    }
    for(auto x : adj[node]){
        if(x == par) continue ;
        dfs1(x , node , adj , curr+1 , dist) ;
    }
    return ;
}
 
void dfs2(int node , int par , vector<int> adj[] , int curr , int &dist){
    // cout<<node<<" "<<curr<<endl ;
    if(curr > dist){
        endTwo = node ;
        dist = curr ;
    }
    for(auto x : adj[node]){
        if(x == par) continue ;
        dfs2(x , node , adj , curr+1 , dist) ;
    }
    return ;
}
 
void dfs(int node , int par , vi &d , vector<int> adj[] , int curr){
    d[node] = curr ;
    for(auto x : adj[node]){
        if(x == par) continue ;
        dfs(x , node , d , adj , curr+1) ;
    }
    return ;
}
 
void solve() {
    
    int n ;
    cin>>n;
    if(n == 1){
        cout<<0<<endl ;
        return ;
    }
    vector<int> adj[n+1] ;
    
    for(int i = 0 ; i < n-1 ; i++){
        int a , b ;
        cin>>a>>b ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }
    int dist = 0 ;
    dfs1(1 , -1 , adj , 0 , dist) ; 
    dist = 0 ;
    // cout<<endOne<<endl ;
    dfs2(endOne , -1 , adj , 0 , dist) ;
    vi d1(n+1 , 1e9); 
    vi d2(n+1 , 1e9); 
    dfs(endOne , -1 , d1 , adj , 0); 
    dfs(endTwo , -1 , d2 , adj , 0); 
    for(int i = 1 ; i <= n ; i++){
        cout<<max(d1[i] , d2[i])<<" " ;
    }
}
 
int main()
{
    int t  = 1;
    // cin>>t ;
    while(t--){
        solve() ;
    }
}
 
