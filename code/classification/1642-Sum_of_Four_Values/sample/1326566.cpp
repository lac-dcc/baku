/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
#define ff first
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define fl(i,a,b) for(int i = a ; i <b ;i++)
#define get(a) fl(i,0,a.size())  cin>>a[i];
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;
 
 
 
int main(){
    Shazam;
    int n; cin >> n;
    int x; cin >> x;
    vector<int> a(n); get(a);
    unordered_map<int, array<int,2>> mp;
    mp.reserve(1<<21);
    string ans = "IMPOSSIBLE";
    if(4LL * ( *min_element(all(a))) > x){
        cout << ans << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(mp.find(x - a[i] - a[j])  != mp.end()){
                array<int,2> p = mp[x - a[i] - a[j]];
                cout << i + 1 << " " << j + 1 << " " << p[0] + 1 << " " << p[1] + 1 << endl;
                return 0;
            }
        }
        for(int j = 0; j < i; j++){
            mp[a[i] + a[j]] = {i , j};
        }
    }
    cout << ans << endl;
    return 0;
}
