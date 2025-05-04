#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<numeric>
#include<iomanip>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<tuple>
#include<queue>
#include<deque>
#include<map>
#include<cstring>
 
typedef long long ll;
typedef long double ld;
ll inf=1e18;
ll mod=1e9+7;
using namespace std;
 
 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i+1;
    }
    int f=0;
    sort(v.begin(),v.end());
    for(ll i=0;i<n-3;i++){
        for(ll j=i+1;j<n-2;j++){
            ll target=m-v[i].first-v[j].first;
            ll lo=j+1,hi=n-1;
            while(hi>lo){
                if(v[lo].first+v[hi].first==target){
                    cout<<v[i].second<<" "<<v[j].second<<" "<<v[lo].second<<" "<<v[hi].second;
                    f=1;
                    break;
                }
                else if(v[lo].first+v[hi].first<target){
                    lo++;
                }
                else hi--;
            }
            if(f==1)break;
        }
        if(f==1)break;
    }
    if(f==0)cout<<"IMPOSSIBLE";
	return 0;
}
