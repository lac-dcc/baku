/* 
        ~~~~~~ @spectre900 ~~~~~~
*/
 
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
 
#define endl "\n"
#define space " "
#define prime 29
#define INF LLONG_MAX
#define mod 1000000007
#define PI acos((long double)(-1))
 
#define all(x) (x).begin(),(x).end()
#define getBlock(x) (((long long int)(sqrt(x)/100)+1)*100)
#define range(i,beg,end) for(long long int i=beg;i<end;i++)
#define rrange(i,end,beg) for(long long int i=end;i>=beg;i--)
#define itover(x) for(auto it=(x).begin();it!=(x).end();it++)
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long int li;
typedef long double ld;
typedef long long int lli;
typedef unsigned long int uli;
typedef complex<long double> cd;
typedef unsigned long long int ulli;
 
template <class T> using
ms = multiset<T>;
 
template <class K, class V> using
mm = multimap <K, V>;
 
template <class T> using
uset = unordered_set <T>;
 
template <class K, class V> using
umap = unordered_map <K, V>;
 
template <class T> using
ums = unordered_multiset <T>;
 
template <class K, class V> using
umm = unordered_multimap <K, V>;
 
template <class T, class C> using
priq =  priority_queue<T, vector<T>, C>;
 
template<class T> using
pset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
void solve();
 
lli power(lli n,lli k,lli m=mod){
    if(k==0) return 1;
    if(k%2) return (n*power(n,k-1,m))%m;
    return power((n*n)%m,k/2,m);
}
 
lli modinv(lli x, lli m=mod){
    return power(x,m-2);
}
 
lli gcd(lli a, lli b){
    return b?gcd(b,a%b):a;
}
 
lli lcm(lli a,lli b){
    return (((a*b)%mod)*modinv(gcd(a,b)))%mod;
}
 
int main(){
    
    srand(18112001);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    solve();
    return 0;
}
 
#define N 100005
 
vector<lli> get(vector<lli>&nums){
    lli n=nums.size();
    lli m=pow(2,n);
    vector<lli>sum(m);
    lli skip=1;
    range(i,0,n){
        range(j,0,m){
            if((j/skip)%2==0){
                sum[j]+=nums[i];
            }
        }
        skip*=2;
    }
    return sum;
}
 
void solve(){
    lli n,k;
    cin>>n>>k;
    vector<lli>nums1,nums2;
    range(i,0,n/2){
        lli x;
        cin>>x;
        nums1.push_back(x);
    }
    range(i,n/2,n){
        lli x;
        cin>>x;
        nums2.push_back(x);
    }
    if(n==1){
        if(nums2[0]==k){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return ;
    }
    lli ans=0;
    vector<lli>left=get(nums1);
    sort(all(left));
    vector<lli>right=get(nums2);
    sort(all(right));
    vector<pair<lli,lli>>dict;
    lli num=0;
    lli count=0;
    range(i,0,right.size()){
        if(right[i]!=num){
            dict.push_back({num,count});
            num=right[i];
            count=1;
        }
        else{
            count++;
        }
    }
    dict.push_back({num,count});
    lli j=dict.size()-1;
    range(i,0,left.size()){
        lli x=left[i];
        lli y=k-x;
        while(j>-1 and dict[j].first>y){
            j--;
        }
        if(j>-1 and dict[j].first==y){
            ans+=dict[j].second;
        }
    }
    cout<<ans;
}
