#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <bitset>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <queue>
#include <unordered_map>
#include <random>
#include <chrono>
#include <stack>
#include <deque>
// cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
using namespace std;
const long long N = 1e6, inf = 1e9;
typedef long long ll;
#define deb(x) cout << #x << " = " << x << endl;
#define debg cout << "yes" << endl;
 
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define Test  \
    long long t;    \
    cin >> t; \
    while (t--)
#define F first
#define S second
#define fo(i, n) for (int i = 0; i < n; i++)
 
#define fon(i, n) for (int i = n - 1; i >= 0; i--)
#define Ln length()
bitset<1000000000>M;
bool cmp(pair<int,int>p,pair<int,int>p1)
{
  return p.F<p1.F;
}
int main()
{
    fast;
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#else
// online submission
#endif
int n,m;
cin>>n;
vector<int>v(n),v1(n);
int a,b;
fo(i,n)
{
  cin>>v[i]>>v1[i];
}
sort(v.begin(), v.end());
sort(v1.begin(), v1.end());
int i=0,j=0;
m=v.size();
int c=0,mx=1;
while(i<m)
{
  if(v[i]<=v1[j]){c++;i++;}
  else{c--;j++;}
  if(mx<c)mx=c;
}
cout<<mx<<endl;
 
}
