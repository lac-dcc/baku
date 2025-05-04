/* 
        ~~~~~~ @spectre900 ~~~~~~~
*/
 
#include<bits/stdc++.h>
 
#define mod 1000000007
 
#define endl "\n"
#define space " "
#define li long int
#define llli __int128
#define ld long double
#define lli long long int
#define uli unsigned long int
#define cd complex<long double>
#define pi acos((long double)(-1))
#define ulli unsigned long long int
 
#define uset unordered_set
#define umap unordered_map
#define priq priority_queue
#define SEED srand(18112001)
#define modinv(x) power((x),mod-2)
#define all(x) (x).begin(),(x).end()
#define getBlock(x) (((int)(sqrt(x)/100)+1)*100)
#define range(i,beg,end) for(int i=beg;i<end;i++)
#define rrange(i,end,beg) for(int i=end;i>=beg;i--)
#define itover(x) for(auto it=(x).begin();it!=(x).end();it++)
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
 
using namespace std;
 
void solve();
 
lli power(lli n,lli k){
    if(k==0)return 1;
    if(k%2)return (n*power(n,k-1))%mod;
    return power((n*n)%mod,k/2);
}
 
lli gcd(lli a,lli b){
    return b?gcd(b,a%b):a;
}
 
lli lcm(lli a,lli b){
    return (((a*b)%mod)*modinv(gcd(a,b)))%mod;
}
 
int main(){
    SEED;
    FASTIO;
    solve();
    return 0;
}
 
#define N 100000
 
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    range(i,0,n){
        cin>>nums[i];
    }
    map<int,int>dict,number;
    range(i,0,n){
        range(j,0,i){
            int sum=nums[i]+nums[j];
            if(dict.find(sum)==dict.end()){
                dict.insert(pair<int,int>(sum,i));
            }
        }
        if(number.find(nums[i])==number.end()){
            number.insert(pair<int,int>(nums[i],i));
        }
    }
    range(i,0,n){
        range(j,0,i){
            int sum=k-nums[i]-nums[j];
            if(dict.find(sum)!=dict.end() and dict[sum]<j){
                cout<<number[sum-nums[dict[sum]]]+1<<space<<dict[sum]+1<<space<<j+1<<space<<i+1;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}