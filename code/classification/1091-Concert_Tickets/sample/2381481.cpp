    //basic template
    #include <bits/stdc++.h> 
    #include <ext/pb_ds/assoc_container.hpp>
    using namespace std; 
    using namespace __gnu_pbds;
    #define ll long long
    const ll mod = 1e9+7;
    const ll mod2= 998244353;
    const ll INF = 1ll<<62;
    const long double pi=3.1415926535897932384626433832795;
    #define fo(i,n) for(ll i=0;i<(ll)n;++i)
    #define fos(j,i,n) for(ll j=i;j<(ll)n;++j)
    #define all(v) v.begin(),v.end()
    //#define endl "\n"
    #define dis(k) cout << k << endl
    #define ret(k) { dis(k); return;}
    #define ror(i,n) for(ll i=(ll)n-1;i>=0;--i)
    #define ve vector
    #define fi first
    #define se second
    #define pb push_back
    #define eb emplace_back
    #define setz(a) memset(a,0,sizeof(a))
    #define seti(a) memset(a,0x7f,sizeof(a))
    #define setmi(a) memset(a,0xc0,sizeof(a))
    typedef ve< ll > vi;
    typedef ve< vi > vvi;
    typedef pair< ll ,ll > ii;
    typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indset;
   
    
  int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	int t=1;
    	//cin >> t;		
    	while(t--){
           ll n,m;
           cin>>n>>m;
           ll a[n];
           ll b[m];
           multiset<ll>s;
           fo(i,n){
            cin>>a[i];
            s.insert(a[i]);       
           }
           fo(i,m)
           cin>>b[i];
         ll i=0;
          while(!s.empty()&& i<m){
              
              auto it = s.lower_bound(b[i]);
                if(it==s.begin() && *it>b[i]){
                 dis(-1);
                 
                 i++;
                 continue;
                }
 
              if(it==s.end()|| *it>b[i])
              it--;
              dis(*it);
              s.erase(it);
              i++;
          }
         for(i;i<m;i++){
             dis(-1);
         }
        }
    	return 0;
    }
    
