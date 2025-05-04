#include <bits/stdc++.h>
 
using namespace std;
 
// typedef $long name$ $short name$;
#define us unsigned
#define ll long long
#define fori(i, a, b) for (ll i = a; i < b; i++)
#define ford(i, a, b) for (ll i = a; i >= b; i--)
#define endl '\n'
#define dbug1(a) cout << a << endl
#define dbug2(a, b) cout << a << "-" << b << endl
#define dbug3(a, b, c) cout << a << "-" << b << "-" << c << endl
#define dbug4(a, b, c, d) cout << a << "-" << b << "-" << c << "-" << d << endl
#define rdm(l, h) rand() % (h - l + 1) + l
#define fil1D(a, n, d) fill(a, a + n, d)
#define fil2D(a, n, d) fill(a[0], a[0] + n * n, d)
#define memo(a,b) memset(a,b,sizeof(a))
#define iseve(a) (a % 2 == 0)
#define ff first
#define ss second
#define desc greater<int>()
#define sz size()
#define all(v) v.begin(), v.end()
#define mod 1000000007
#define ARMX 1e8 + 1
#define pb push_back
#define swapI(x, y) \
    {               \
        x = x + y;  \
        y = x - y;  \
        x = x - y;  \
    }
#define maxA *max_element
#define minA *min_element
#define Pinf INT_MAX
#define Ninf INT_MIN
#define Plong LLONG_MAX
#define Nlong LLONG_MIN
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define len length()
#define strend string::npos
#define JustGreat(v, x) upper_bound(all(v), x)              // index of first number that is just greater than x
#define GreaterEqual(v, x) lower_bound(all(v), x)           // index of first number that is just greater or equal to x
#define NoEleLessX(v, x) upper_bound(all(v), x) - v.begin() // applicable only for sorted array
#define forr(it,ds) for(auto it = ds.rbegin(); it != ds.rend(); ++it)
#define forf(it,ds) for(auto it = ds.begin(); it != ds.end(); ++it)
// printf("%0.5lf",l);
 
// srand(time(NULL));
// O(1) < O(log n) < O(n) < O(n log n) < O(n^2) < O(2^n) < O(n!)
 
// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x){
//         val=x;
//         left=NULL;
//         right=NULL;
//     }
// };
 
// struct ListNode{
//     int val;
//     ListNode *next;
//     ListNode(int x){
//         val=x;
//         next=NULL;
//     }
// };
 
// struct trienode{
//     trienode* child[26];
//     bool isend;
//     trienode(){
//         for(int i=0;i<26;i++) child[i]=NULL;
//         isend=false;
//     }
// };
 
// // use when priority queue needs to be an object
// struct obj{
//     ll dist;
//     ll cx;
//     ll cy;
// };
// bool operator<(const struct obj& obj1,const struct obj& obj2){ // will have min dist on the top
//     return obj1.dist>obj2.dist;
// }
 
// ll FindByPathComp(vector<ll> &v,ll x){ 
//     if(v[x]==x) return x;
//     v[x]=FindByPathComp(v,v[x]);
//     return v[x];
// }
 
// void UnionByRank(vector<ll> &v,vector<ll> &r,ll x,ll y){
//     ll xp=FindByPathComp(v,x);
//     ll yp=FindByPathComp(v,y);
//     if(r[xp]>r[yp]) v[yp]=xp;
//     else if(r[yp]>r[xp]) v[xp]=yp;
//     else {
//         v[yp]=xp;
//         r[xp]++;
//     }
// }
 
// bool mycmp(pair<int,int> n1,pair<int,int> n2){
//     if(n1.ff==n2.ff) return n1.ss<n2.ss;
//     return n1.ff>n2.ff;
// }
 
// to overload operator '<' for using priority queue for different data type
// bool operator<(const struct tup& obj1,const struct tup& obj2){ // will have max height on the top
//     return obj1.sum<obj2.sum;
// }
 
// int gcd(int a,int b){
//     if(b==0) return a;
//     else return gcd(b,a%b);
// }
 
// bool check_prime3(int n){  
//     if(n==1) return false;
//     if(n==2 || n==3) return true;
//     if(n%2==0 || n%3==0) return false;
//     for(int i=5;i*i<=n;i+=6) 
//         if(n%i==0 || n%(i+2)==0) return false;
//     return true;
// }
 
// void all_factors2(int n){
//     int i;
//     for(i=1;i*i<=n;i++)
//         // if(n%i==0) cout<<i<<" "<<n/i<<" "; // do not give in sorted order
//         if(n%i==0) cout<<i<<" ";
//     for(i--;i>0;i--)
//         if(n%i==0) cout<<n/i<<" ";
//     cout<<endl;
// }
 
// long long binpow(long long a, long long b, long long m) {
//     a %= m;
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }
 
// long long Inversemod(long long a,long long b,long long m){
//     return a%m*binpow(b,m-2,m);
// }
 
ll max(ll x,ll y){
    return (x>y)?x:y;
}
 
ll min(ll x,ll y){
    return (x<y)?x:y;
}
 
// for upper/lower bound on pair use 
// auto it = lower_bound(all(ip),make_pair((int_type)5,numeric_limits<int_type>::min()));    
// auto it = lower_bound(all(ip),make_pair(numeric_limits<int_type>::min(),(int_type)5));    
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,x;
    cin>>n>>m>>x;
    vector<ll> ds(n);
    fori(i,0,n) cin>>ds[i];
    vector<ll> hs(m);
    fori(i,0,m) cin>>hs[i];
    sort(all(ds));
    sort(all(hs));
    ll cnt=0;
    fori(i,0,n){
        auto it=lower_bound(all(hs),max(0,ds[i]-x));
        if(it!=hs.end()){
            ll k=it-hs.begin();
            if(hs[k]<=(ll)(ds[i]+x)){
                cnt++;
                hs[k]=-1;
            }
        }
    } 
    cout<<cnt;
    return 0;
}