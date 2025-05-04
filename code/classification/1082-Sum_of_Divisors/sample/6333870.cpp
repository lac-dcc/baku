#include <bits/stdc++.h>
#define int long long
#define fo(i,n) for(int i=0;i<n;i++)
#define ko(i,n,k) for(int i=k;k<n?i<n:i>n;k<n?i=i+1:i=i-1)
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define tr(it,a) for(auto it:a)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define srt(v)  sort(v.begin(),v.end())
 
typedef std::vector<int> vi;
typedef std::pair<int,int> pii;
typedef std::vector<pii>  vpi;
const int m1=1e9+7;
const int m2=998244353;
 
using namespace std;
 
 
int power(long long x, unsigned int y)
{
    int res = 1;
 
    x = x% 1000000007;
 
    if (x == 0) return 0;
 
    while (y > 0)
    {
 
        if (y & 1)
            res = (res*x)%  1000000007;
 
 
        y = y>>1;
        x = (x*x)%  1000000007;
    }
    return res;
}
 
 
 
void sol(){
int n;
cin>>n;
int sum=0;
int left=n;
int right=n;
int cur=1;
int k=power(2,m1-2);
while(left>=1){
    left=(n/(cur+1))+1;
 
    int add=((((right-left+1)%m1)*((right+left)%m1))%m1*(k%m1))%m1;
    sum=(sum+(cur*add)%m1)%m1;
 
    if(left==1){
        break;
    }
    cur=n/(left-1);
    right=left-1;
 
    
 
}
cout<<sum<<endl;
}
 
 
 
 
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   //cout<<fixed<<setprecision(9);
    
    int t=1;
    //cin>>t;
    while(t--){
     sol();
    }
return 0;
}
