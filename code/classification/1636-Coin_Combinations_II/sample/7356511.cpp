/*********Jai Shree Ram*****************
**        Solution by kunal0612       **
**********Jai Shree Ram****************/
#include <bits/stdc++.h>
#define ll long long int
#define lll unsigned long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define mod 1000000007
#define nl "\n"
using namespace std;
 
vector<vector<ll>> dir4={{1,0},{0,1},{-1,0},{0,-1}};
vector<vector<ll>> dir8={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};
 
// vector<ll> v,Tree,Lazy;
// void build(ll st,ll l,ll h){
// 	if(l==h){
// 		Tree[st] = v[h];
// 		return;
// 	}
// 	ll mid = (l+h)/2;
// 	build(2*st+1, l, mid);
// 	build(2*st+2, mid+1, h);
// 	Tree[st] = Tree[2*st+1]^Tree[2*st+2];
// }
 
// void updateTree(ll st, ll l, ll h, ll idx, ll val){
// 	if(l==h){
// 		Tree[st] = val;
// 		return;
// 	}
// 	ll mid = (l+h)/2;
// 	if(idx<=mid) updateTree(2*st+1, l, mid, idx, val);
// 	else updateTree(2*st+2, mid+1, h, idx, val);
// 	Tree[st] = Tree[2*st+1]^Tree[2*st+2];
// }
 
// ll query(ll tidx, ll lo, ll hi, ll L, ll R){
// 	if( R<lo || L>hi ) return 0;
// 	if( lo>=L && hi<=R )return Tree[tidx];
// 	ll mid = (lo+hi)/2;
// 	ll leftans = query(2*tidx+1, lo, mid, L, R);
// 	ll rightans = query(2*tidx+2, mid+1, hi, L, R);
// 	return leftans^rightans;
// }
 
// void updaterange(int st, int l, int h, int i, int j, int val)
// {
//     if (Lazy[st] != 0) {                             
//         Tree[st] += (h-l + 1)*Lazy[st]; 
 
//         if (l != h) {                                    
//             Lazy[2 * st + 1] += Lazy[st];
//             Lazy[2 * st + 2] += Lazy[st];
//         }
 
//         Lazy[st] = 0;                                
//     }
 
//     if (l > h || l > j || h < i)
//         return;                                            
 
//     if (i <= l && h <= j) {                               
//         Tree[st] += (h - l + 1) * val;             
 
//         if (l != h) {                                     
//             Lazy[2 * st + 1] += val;
//             Lazy[2 * st + 2] += val;
//         }
 
//         return;
//     }
 
//     int mid = l + (h - l) / 2;                             
 
//     updaterange(2 * st + 1, l, mid, i, j, val);
//     updaterange(2 * st + 2, mid + 1, h, i, j, val);
//     Tree[st] = Tree[2*st+ 1] + Tree[2 * st + 2];
// }
 
// ll queryrange(ll st,ll l,ll h,ll i,ll j){
//     if (l > j || h < i) return 0;                                          
//     if (Lazy[st] != 0) {                             
//         Tree[st] += (h - l + 1) * Lazy[st]; 
//         if (l != h) {                                     
//             Lazy[2 * st + 1] += Lazy[st];
//             Lazy[2 * st + 2] += Lazy[st];
//         }
//         Lazy[st] = 0;                               
//     }
//     if (i <= l && j >= h) return Tree[st];
//     ll mid = l + (h - l) / 2;                         
//     if (i > mid) return queryrange(2 * st + 2, mid + 1, h, i, j);
//     else if (j <= mid) return queryrange(2 * st + 1, l, mid, i, j);
//     ll leftQuery = queryrange(2 * st + 1, l, mid, i, mid);
//     ll rightQuery = queryrange(2 * st + 2, mid + 1, h, mid + 1, j);
//     return leftQuery + rightQuery;
// }
 
// ll dp[10005];
 
 
 
void kunal(){
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> dp(x+1,0);
    dp[0]=1;
    for(ll i=0;i<n;i++){
        for(ll sum=1;sum<=x;sum++){
            if(sum-a[i]>=0){
                dp[sum]=(dp[sum]+dp[sum-a[i]])%mod;
            }
        }
    }
    cout<<dp[x]<<nl;
}
 
 
//cout << fixed << setprecision(10) <<sum;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    while(t--){
        kunal();
    }
    return 0;
}
