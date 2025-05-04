#include<bits/stdc++.h>
#define ll long long int
#define iamspeed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nl "\n"
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define fl(i,a,b) for(ll i=a;i<b;i+=1)
#define rl(i,a,b) for(ll i=a;i>b;i-=1)
#define input(a,n) fl(i,0,n)cin>>a[i];
#define printt(a,n) fl(i,0,n) cout<<a[i]<<' ';
#define all(a) a.begin(),a.end()
#define test() ll t; cin>>t; while(t--)
#define maxelement(arr,n) *max_element(arr,arr+n)
//typedef long long ll;
const ll INF = 9e18;
const ll MOD = 1000000007;
const ll mod = 998244353;
const int N = 2e6 +1;
using namespace std;
 
// 
// vector<ll> tree;
// ll ans=0;
// 
// ll sum(int node, int low, int high, ll value){
	// if(low==high && tree[node]>=value){
		// // tree[low]-=value;
		// return low;
	// }
	// int last_in_left= (low+high)/2;
	// if(tree[2*node]>=value){
		// return sum( 2*node, low, last_in_left, value);
	// }
	// else
	// return sum(2*node+1, last_in_left+1, high, value);
// }
// 
// void update(int posi){
	// if(posi==1 || posi==0){
		// return;
	// }
	// int node = posi/2;
	// tree[node] = max(tree[2*node], tree[2*node+1]);
	// update(node);
// 	
	// // tree[node] = tree[2*node]+ tree[2*node+1];
	// //return sum+tree[node];
// }
 
vector<int> v[200001];
int arr[200001]={0};
int vis[200001]={0};
void dfs( int node){
	vis[node]=1;
	// arr[node] = v[node].size()-1;
	arr[node]=0;
	
	for(int x: v[node]){
		if(!vis[x]){
			arr[node]++;
			dfs(x);
			arr[node]+=arr[x];
		}
	}
	// return 0;
}
 
int main(){
	iamspeed;
	int n;
	cin>>n;
	
	
	for(int i=2; i<=n;i++){
		int x;
		cin>>x;
		v[x].pb(i);
		v[i].pb(x);
	}
	dfs(1);
	fl(i,1, n+1){
		cout<<arr[i]<<" ";
	}
	
	cout<<endl;
}
 
//APPROACHING A QUESTION
//+ Don't be dumb
//+ Think of binary search (max of min etc also if n<=2*10^5)
//+ Think of common dp states (Even if it appears as maths 
//but constraints are small)
//+ Check constraints
//+ Keep calm and enjoy the question
//+ Be sure to remove MOD from binpow (if needed)
//+ Try bidirectional analysis for constructive questions1
//+ If given some sequence try thinking of prefix sums
//+ If constraints are too large maybe its simple maths
//+ In questions with binary operations think of bits independently 
//and also the change pattern
//+ If two or more binary operations are given mostly there is 
//a relation between them and an arithmatic operator
//+ multi source bfs
/* trick to get string to int 
		stringstream geek(str);
		ll y=0;	
		geek>>y;
		cout<<y<<endl;
		or just use stoi(str)/stoll(str) u idiot;
		
	bitset<200005> b;
    b[0] = 1;
    for (int i : v) b |= (b << i);
    return b[s >> 1];
*/
