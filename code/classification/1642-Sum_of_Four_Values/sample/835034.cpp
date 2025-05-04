#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define black_tree tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define gp __gnu_pbds
#define INF 1000000000
#define MOD 1000000007
#define MAX 200001
#define endl '\n'
#define ll long long
#define ld long double
#define lli long long int
#define ull unsigned long long
#define ulli unsigned long long int
#define pb push_back
#define pf push_front
#define ook order_of_key
#define fbo find_by_order
#define np next_permutation
#define mp make_pair
#define eb emplace_back 
#define me max_element
#define lb lower_bound 
#define ub upper_bound
#define bs binary_search
#define ff first
#define ss second
using namespace std;
using namespace gp;
vector<pair<ll,ll> >v;
ll n,s,a,k,l;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s;
	for(ll i=1;i<=n;i++){
		cin>>a;
		v.pb(mp(a,i));
	}
	sort(v.begin(),v.end());
	if(v.size()<4){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	for(int i=0;i<v.size()-3;i++){
		for(int j=i+1;j<v.size()-2;j++){
			k=j+1,l=v.size()-1;
			while(k<l){
				if(v[i].ff+v[j].ff+v[k].ff+v[l].ff==s){
					cout<<v[i].ss<<" "<<v[j].ss<<" "<<v[k].ss<<" "<<v[l].ss;
					return 0;
				}
				else if(v[i].ff+v[j].ff+v[k].ff+v[l].ff<s){
					k++;
				}
				else{
					l--;
				}
			}
		}
	}
	cout<<"IMPOSSIBLE";
}
