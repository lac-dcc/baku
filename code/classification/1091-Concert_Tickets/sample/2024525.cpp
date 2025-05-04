#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ll long long
#define mod 1000000007
#define MAXSIEVE 100000000 // All prime numbers up to this 
#define MAXSIEVEHALF (MAXSIEVE/2) 
#define MAXSQRT 5000 // sqrt(MAXSIEVE)/2 
char a[MAXSIEVE/16+2]; 
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd 
//most optimized sieve.....
void sieve()
{
    int i,j; 
    memset(a,255,sizeof(a)); 
    a[0]=0xFE; 
    for(i=1;i<MAXSQRT;i++) 
        if (a[i>>3]&(1<<(i&7))) 
            for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1) 
                a[j>>3]&=~(1<<(j&7));
}
// to check prime for larg numbers like of the order of 1e9;
/*void solve(int test){
    long long num;
    cin>>num;
    cout<<"Case #"<<test<<": ";
    if(num<15){
        cout<<6<<endl;
        return;
    }
    int srt=sqrt(num);
    while(srt*1ll*srt<num)
        srt++;
    while(srt*1ll*srt>num)
        srt--;
 
    int p=srt;
    if(p%2==0)p--;
 
    while(!isprime(p)){
        p-=2;
    }
    int q=p-2;
    int r=p+2;
 
    while(q>1 and !isprime(q))
        q-=2;
    while(!isprime(r))
        r+=2;
 
    if(p*r*1ll<=num)
        cout<<p*1ll*r<<endl;
    else
        cout<<q*1ll*p<<endl;
 
 
}*/
 
 
bool cmp(pair<long long,pair<long long,long long>> a,pair<long long,pair<long long,long long>> b){
 
    if(a.first!=b.first)
        return a.first<b.first;
 
    else
        return a.second.first>b.second.first;
 
 
}
 
long long fact(int num){
    long long ans=1;
    for(int i=1;i<=num;i++){
        ans=(ans*i)%mod;
    }
 
    return ans;
}
long long GCD(long long a,long long b){
  //base case
  if(b==0)
    return a;
 
  long long ans=GCD(b,a%b);
 
  return ans;
}
 
 
bool containsElement(int arr[], int n)
{
 
    int xorArr = 0;
    for (int i = 0; i < n; ++i)
        xorArr ^= arr[i];
 
    for (int i = 0; i < n; ++i) {
 
        // Take the XOR after excluding
        // the current element
        int x = xorArr ^ arr[i];
 
        if (arr[i] == x)
            return true;
    }
 
    return false;
}
 
int main(){
 
    ios_base::sync_with_stdio(false);cin.tie(NULL);
 
   #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 
    #endif
    int n,m;
    cin>>n>>m;
    multiset<int> ticket;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        ticket.insert(a);
    }
    /*for(auto it:ticket)cout<<it<<" ";
        cout<<endl;*/
        
    for(int i=0;i<m;i++){
        int a;cin>>a;
        auto it=ticket.lower_bound(a);
        if(*it==a){
            cout<<*it<<endl;
             ticket.erase(it);
        }
        else{
            auto it1=ticket.begin();
            if(it==it1){
                cout<<-1<<endl;
            }
            else
            {
                it--;
                cout<<*it<<endl;
                 ticket.erase(it);
            }
        }
    
    }
 
}
