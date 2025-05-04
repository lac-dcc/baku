#include<bits/stdc++.h>
using namespace std;
 
#define LL long long
#define ULL unsigned long long
#define LD long double
 
#define MAX (int)(1e3+1)
#define MOD (int)(1e9+7)
#define endl '\n'
 
#define VI vector<int>
#define VLL vector<long long>
#define VB vector<bool>
 
#define PI pair<int, int>
#define PLL pair<long long, long long>
 
// starting and ending both included
#define REP(i, s, e)  for(long long i = s; i <= e; i++)
#define RREP(i, e, s) for(long long i = e; i >= s; i--)
 
template<typename T>
void PV(vector<T> arr);
 
template<typename T>
int BS(vector<T> arr, int start, int end, T key);
 
template<typename T>
T power(T num, T exp);
 
struct node
{
    LL sum;
    LL ans;
    LL prefix;
    LL suffix;
    node()
    {
        sum = ans = prefix = suffix = 0;
    }
};
 
void solve()
{
    int n, m;
    cin>>n>>m;
 
    int size = 1;
    while(size < n)
        size *= 2;
 
    vector<node> arr(2*size, node());
 
//    REP(i, 1, 2*size-1)
//    {
//        cout<<arr[i].sum<<" "<<arr[i].ans<<" "<<arr[i].prefix<<" "<<arr[i].suffix<<"\n";
//    }
 
    REP(i, size, size+n-1)
    {
        int temp;
        cin>>temp;
        arr[i].sum = arr[i].ans = arr[i].prefix = arr[i].suffix = temp;
        if(temp < 0)
            arr[i].ans = arr[i].prefix = arr[i].suffix = 0;
    }
 
    RREP(i, size-1, 1)
    {
        auto l = arr[2*i];
        auto r = arr[2*i+1];
 
        arr[i].sum = l.sum + r.sum;
        arr[i].ans = max({l.ans, r.ans, l.suffix + r.prefix});
        arr[i].prefix = max({l.prefix, l.sum + r.prefix, 0ll});
        arr[i].suffix = max({r.suffix, r.sum + l.suffix, 0ll});
    }
 
    REP(i, 1, m)
    {
        int a, b;
        cin>>a>>b;
 
        a += size-1;
 
        arr[a].sum = arr[a].ans = arr[a].prefix = arr[a].suffix = b;
        if(b < 0)
            arr[a].ans = arr[a].prefix = arr[a].suffix = 0;
 
        int x = a/2;
 
        while(x >= 1)
        {
            auto l = arr[2*x];
            auto r = arr[2*x+1];
 
            arr[x].sum = l.sum + r.sum;
            arr[x].ans = max({l.ans, r.ans, l.suffix + r.prefix});
            arr[x].prefix = max({l.prefix, l.sum + r.prefix, 0ll});
            arr[x].suffix = max({r.suffix, r.sum + l.suffix, 0ll});
            x /= 2;
        }
        cout<<arr[1].ans<<endl;
    }
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
 
    return 0;
}
 
template<typename T>
void PV(vector<T> arr)      // print vector
{
    int n= arr.size();
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<"\n";
}
 
template<typename T>
int BS(vector<T> arr, int start, int end, T key)    // Binary search which returns position
{
    int i = start;
    int j = end;
 
    while(i<=j)
    {
        int mid = i+(j-i)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            j=mid-1;
        else
            i=mid+1;
    }
    return -1;
}
 
template<typename T>
T power(T num, T exp)
{
    if(exp<=0)
        return 1;
 
    T ans = power(num, exp/2);
    ans = ans*ans;
 
    if(exp%2 != 0)
        ans *= num;
 
    return ans;
}
 
