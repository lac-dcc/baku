#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define ld long double
#define li __int128_t
#define pb push_back
#define ppb pop_back
#define fio ios_base::sync_with_stdio(0); cin.tie(0);
template <typename T>
using indexed_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
/*
    member functions :
                1. order_of_key(k) : number of elements strictly lesser than k
                2. find_by_order(k) : k-th element in the set (counting from zero)
*/
 
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
 
double eucliddist(double i, double j, double p, double q)
{
    double a=pow(p-i,2);
    double b=pow(q-j,2);
    double ans=sqrt(a+b);
    return ans;
}
 
// bool prime[100001];
// void sieveoferatosthenes()
// {
//     memset(prime,true,sizeof(prime));
//     prime[0]=false;
//     prime[1]=false;
//     for(int p=2;p*p<100001;p++)
//     {
//         if(prime[p]==true)
//         {
//             for(int i=p*p;i<100001;i+=p)
//                 prime[i]=false;
//         }
//     }
// }
 
lli fact(int n)
{
    lli f=1;
    for(int i=2;i<=n;i++)
        f=f*i;
    return f;
}
 
vector<int> pairSum(int n){
     
    int mid = n / 2;
    vector<int> v;
    for (int i = mid; i >= 1; i--) {
        if (gcd(i, n - i) == 1) {
            v.push_back(i);
            v.push_back(n-i);
            break;
        }
    }
    return v;
}
 
bool palindrome(string s, int n)
{
    int i=0, j=n-1;
    while(i<j)
    {
        if(s[i]==s[j])
        {
            i++; j--;
        }
        else
            break;
    }
    if(i>=j)
        return true;
    return false;
}
 
bool checkprime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
 
int givepower(int n)
{
    int i=0;
    while(1)
    {
        if(n&(1<<i))
            return i;
        i++;
    }
}
 
bool isPowerOfTwo(int n)
{
   int cnt=0;
   while(n)
   {
        if(n&1)
            cnt++;
        n=n>>1;
   }
   if(cnt==1)
    return true;
   return false;
}
 
int main()
{
    fio; 
    //sieveoferatosthenes();
    //cout<<fixed<<setprecision(12);
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.pb({x,y});
    }
    sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b)
    {
        return a.second<b.second;
    });
    multiset<int> s;
    int cnt=0;
    s.insert(v[0].second);
    for(int i=1;i<n;i++)
    {
        auto it=s.upper_bound(v[i].first);
        if(it==s.begin())
        {
            if(s.size()<k)
                s.insert(v[i].second);
            else if(s.size()==k)
                cnt++;
        }
        else
        {
            it--;
            s.erase(it);
            s.insert(v[i].second);
        }
    }
    cout<<n-cnt<<endl;
}
 