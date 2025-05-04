 #include <bits/stdc++.h>
    using namespace std;
    #define ff first
    #define ss second
    #define int long long
    #define double long double
    typedef vector<int> vi;
     
    #define all(x) x.begin(), x.end()
    #define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
    #define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
    #define deb(x) cout << #x << "=" << x << endl
    #define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
    #define endl "\n"
    #define pb push_back
    #define mp make_pair
    #define re(i,n)        for(int i=0;i<(n);i++)
    #define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
    #define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
    typedef pair<int, int> pii;
    typedef priority_queue<pii, vector<pii>, greater<pii>> minpq;
    typedef priority_queue<pii> maxpq;
    const int mod = 1000000007;
    
    const int N = 505;
    int adj[N][N];
    int d[N][N];
    int n , m;
    int dp[N][N];
    const int INF = 1e18;
 
    void floyd(){
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                if(adj[i][j] != -1){
                    dp[i][j] = adj[i][j];
                }else{
                    dp[i][j] = INF;
                }
                if(i==j)dp[i][j]=0; 
            }
        }
 
        for(int k = 1 ; k <= n ;++k){
            for(int i = 1; i <= n ; ++i){
                for(int j = 1; j <= n ; ++j){
                    dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
                }
            }
        }
 
 
 
    }
 
    
     
    int32_t main()
    {
       FIO;
       int q;
       cin>>n>>m>>q;
       int a , b , c;
       
       memset(adj , -1 , sizeof(adj));
       for(int i = 0 ; i < m ; ++i){
           cin>>a>>b>>c;
           if(adj[a][b]== -1)
          { adj[a][b] = c;
           adj[b][a] = c;}else{
               int d = min(c , adj[a][b]);
               adj[a][b] = d;
           adj[b][a] = d;
           }
       }
       floyd();
       int x , y;
       while(q--){
           cin>>x>>y;
           if(dp[x][y] == INF){
               cout<<-1<<endl;
           }else{
               cout<<dp[x][y]<<endl;
           }
       }
 
       
       
       return 0;
    }
