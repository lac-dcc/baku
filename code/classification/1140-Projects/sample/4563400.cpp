    #include<bits/stdc++.h>
    using namespace std;
    #include<string.h>
    #define  int                 long long
    #define  pb                  push_back
    #define  ppb                 pop_back
    #define  pf                  push_front
    #define  ppf                 pop_front
    #define  fo(i,a,b)           for(int i=a; i<b ; i++)
    #define  rfo(i,a,b)          for(int i=a; i>=b ; i--)
    #define  yes                 cout<<"YES"<<endl
    #define  no                  cout<<"NO"<<endl
    #define  all(x)              (x).begin(),(x).end()
    #define  boost               ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define  INF                 2000000000000000000
    #define  mod                 1000000007
 
    int power(int b,int e){if(e==0) return 1; if(e&1) return b*power(b*b,e/2); return power(b*b,e/2);}
    bool isPrime(int n){if (n<=1)return false; if (n<=3)return true; if (n%2==0||n%3==0)return false;
            for(int i=5;i*i<=n;i=i+6){if(n%i==0||n%(i+2)==0){return false;}} return true;}
    int bpow(int n,int po)
{
	int res=1;
	while(po>0)
	{
		if(po%2)
		{
			res=(res*n)%mod;
			po--;
		}
		else
		{
			n=(n*n)%mod;
			po/=2;
		}
	}
	return res;
}
    int modInverse(int n,int p)
{
	return bpow(n,p-2);
}
 
    int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
    int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
 
    ///////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////
   int N,M;
   bool valid(int x, int y ){
   if(x<0 || y<0 || x>=N || y>=M)return false;
   return true;
   }
 
 
   int vis[100001];
   int sz[100001];
   int in[100001];
   int par[100001];
   int stc[100001]={};
   vector<int> seq;
   vector<int> ar[100001];
 /*  int f(int a){
       if(par[a]==-1){return a;}
       return par[a]=f(par[a]);
   }
   void merg(int x, int y){
      par[x]=y;
      sz[y]+=sz[x];
   }
*/
 
 
   void dfs(int node){
       cout<<node<<" "<<par[node]<<endl;
    vis[node]=1;
    int cnt=0;
    for(int child :  ar[node]){
    cnt++;
    if(vis[child]==0){par[child]=node; dfs(child);}
    }
 
 
   return;
  }
 
   struct job{
    int x,y,z;
   };
    bool comp(job a, job b){
    return(a.y<b.y);
    }
 
 
   int dp[200001];
 
 
     void BOOM_BAAM()
     {
           int n; cin>>n;
           job a[n];
 
           fo(i,0,n){
           cin>>a[i].x>>a[i].y>>a[i].z;
           }
 
           sort(a,a+n,comp);
           for(int i=0; i<=n ; i++){
            dp[i]=0;
           }
//           for(int i=0 ; i<n;i ++){cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;}
 
           int l=0,r=0,mid;
           dp[1]=a[0].z;
           for(int i=2 ; i<=n ; i++){
            dp[i]=dp[i-1];
            int flag=0;
 
            int t=a[i-1].x;
            l=0; r=i-1;
            while(l<=r){
                mid=(l+r)/2;
                if(a[mid].y<t && a[mid+1].y>=t){flag=1;break;}
                else if(a[mid].y<t){l=mid+1;}
                else{r=mid-1;}
            }
            mid++;
        //    cout<<"mid = "<<mid<<" ";
            if(flag==0){mid=0;}
            dp[i]=max(dp[i],dp[mid]+a[i-1].z);
         //             cout<<dp[i]<<" ";
           }
           cout<<dp[n]<<endl;
 
     }
    ////////////////////////////////// ////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////
 
        signed main()
        {
         boost;
      //   freopen("input.txt","r",stdin);
      //   freopen("output.txt","w",stdout);
 
         int T=1;
       //  cin >> T;
 
            for(int i=1 ; i<=T ; i++){
                BOOM_BAAM();
 
            }
 
            return 0;
        }