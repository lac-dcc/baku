#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
using ll = long long int;
#define lp(i,n) for(ll i =0; i<n; i++)
#include <set>
 
int main(){
 //  freopen("input.txt", "r", stdin);
 //  freopen("output.txt","w",stdout);
    ll n,m;cin>>n>>m;
    vector<ll> maxprice(m);
    multiset<ll, greater<ll>> tickets = {};
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin>>temp;
        tickets.insert(temp);
    }
    for (ll i = 0; i < m; i++)
    {
        cin>>maxprice[i];
    }
    for(auto i : maxprice){
        auto it = tickets.lower_bound(i);
        if(it != tickets.end()){
            cout<<*(it)<<endl;
            tickets.erase(it);
        }
        else{
            cout<<-1<<endl;
        }
    }
    // ll n,m;
    // cin>>n>>m;
	// vector<ll> v(n),u(m);
	// lp(i,n)cin>>v[i];
	// lp(i,m)cin>>u[i];
	// multiset<ll,greater<ll>>s;
	// lp(i,n)s.insert(v[i]);
	// //joker(s)
	// lp(i,m)
	// {
	// 	auto it=s.lower_bound(u[i]);
	// 	if(it==s.end())cout<<-1<<endl;
	// 	else
	// 	{
	// 		cout<<*it<<endl;
	// 		s.erase(it);
	// 	}
	// 	//joker(s)
	// }
    
    return 0;
}
