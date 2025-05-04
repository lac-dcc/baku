/*
Competitive Boiler Plate
    Rahul chhabra (3rd year computer science student).
*/
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
#define FAST            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define endl			"\n"
#define LMX             1e18
#define pb 				push_back
#define eb				emplace_back
#define vi              std::vector<ll>
#define vs				std::vector<std::string>
#define vvi             std::vector<vector<ll>>
#define vc              std::vector<char>
#define pii             std::pair<ll,ll>
#define ump				std::unordered_map
#define mp 				std::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<"\n";	
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef trie<std::string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
ll inline powerM(ll a, ll b, ll p){
    a %= p;
    ll ans = 1;
    while(b>0){
        if(b & 1)
            ans = (ans*a)%p;
        a = (a*a)%p;
        b >>= 1;
    }
    return ans;
}
ll power(ll a,ll b) {
	ll ans = 1;
	while(b) {
		if(b&1) ans *=a;
		a*=a;
		b >>= 1;
	}
	return ans;
}
// FOR BFS		
int dx[] = {1,0,-1,0,1,-1,1,-1}; 
int dy[] = {0,1,0,-1,1,1,-1,-1};  
 
//MOD INVERSE (ONLY WORKS WHEN P IS PRIME)
ll mod_inv(ll n, ll p){
    return powerM(n,p-2, p);
}
const int M = 3e5 + 5;
 
//SIEVE IN O(N) TIME (FOR N UPTO 1e7 OTHERWISE YOU'LL FACE MEMORY ISSUES)
vi lp(M);
vi pr;
void sieve()
{
	lp[0] = 1; 
 
	for(int i = 2 ; i < M ; i++)
	{
		if(lp[i] == 0)
		{
			//this is a prime
			lp[i] = i;
			pr.push_back(i);
		}
		for(int j = 0 ; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < M; j++)
			lp[i * pr[j]] = pr[j];
	}
}
ll sumOfAll(vi nums,int n) {
	ll sum = 0;
	for(int i = 0;i<n;i++) 
		sum += (nums[i]*1ll*(i+1)*1ll*(n-i));
	return sum;
} 
 
class BIT {
private:
	vector<ll> tree;
	ll n;
public:
	BIT(ll n) {
		this->n = n;
		tree.resize(n+1,0);
	}
	void Build(vi &nums,int n) {
		loop(i,1,n) {
			addIndex(i,nums[i]);
		}
	}
	void addIndex(int idx,ll value) {
		while(idx <= n) {
			tree[idx] += value;
			idx+= idx & -idx;
		}
	}
	ll getSum(ll idx) {
		ll sum = 0;
		while(idx) {
			sum += tree[idx];
			idx = idx&(idx-1);
		}
		return sum;
	}
	ll query(ll l,ll r) {
		ll leftRange = getSum(l-1);
		ll rightRange = getSum(r);
		return rightRange-leftRange;
	}
	void pointUpdate(int idx,ll value,ll prev) {
		while(idx <= n) {
			tree[idx] = tree[idx]-prev+value;
			idx += idx & -idx;
		}
	}
};
 
bool cmp(string str1,string str2){
	return str1.size() < str2.size();
}
bool startsWith(std::string mainStr, std::string toMatch)
{
    // std::string::find returns 0 if toMatch is found at starting
    if(mainStr.find(toMatch) == 0)
        return true;
    else
        return false;
}
string findDiff(string str1, string str2)
{
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
 
    int carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
 
}
void google(int tt) {
	cout << "Case #" << tt <<": ";
}
const int N = 1e6;
vector<int> gr[N];
vector<int> dp;
ll dfs(int node,int par) {
	if(dp[node] != -1) return dp[node];
	ll count = 0;
	ll child = 0;
	for(auto adj : gr[node]) {
		if(adj != par) {
			child++;
			count += dfs(adj,node);
		}
	}
	if(child == 0){
		dp[node] = 0;
		return 1;
	}
	else{
		dp[node] = count;
		return count+1;
	}
}
void solve() { 
		int n;
		cin >> n;
		dp.resize(N,-1);
		loop(u,2,n) {
			int v;
			cin >> v;
			gr[u].pb(v);
			gr[v].pb(u);
		}
		dfs(1,0);
		loop(node,1,n) cout << dp[node] << " ";
		cout << "\n";
}
void file_i_o()
{
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
 
int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    solve();
    // Write your code here...
    return 0;
}
