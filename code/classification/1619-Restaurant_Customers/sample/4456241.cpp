#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(),v.end()
#define lower(s) f(i,0,s.length()) if(s[i]>='A' && s[i]<='Z') s[i]+=('a'-'A');
#define upper(s) f(i,0,s.length()) if(s[i]>='a' && s[i]<='z') s[i]-=('a'-'A');
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
typedef vector<int> vi;
typedef pair<int,int> pii;
 
void solve(){
    int n;
    cin>>n;
    vi a(n),b(n);
    f(i,0,n) cin>>a[i]>>b[i];
    sort(all(a));
    sort(all(b));
    int i=1,j=0;
    int count=1,ans=1;
    while(i<n && j<n){
        if(a[i]<b[j]) {
            count++;
            i++;
        }
        else {
            count--;
            j++;
        }
        ans = max(ans,count);
    }
    cout<<ans<<"\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1,x=1;
   // cin>>t;
    while(t--){
        //cout<<"Case #"<<x<<": ";
        solve();
        x++;
    }
}
