#include<iostream>
#include<set>
#define int long long 
using namespace std;
 
int N = 2e5 + 5;
 
int32_t main(){
    int n,m, a[N],k; cin >> n >> m;
    multiset<int>s;
    for(int i=0;i<n;i++)    cin >> k, s.insert(k);
    for(int i=0;i<m;i++) {
       cin >> a[i];
       if(s.empty())  {
           cout << -1 << endl;
           continue;
       }
       multiset<int>::iterator it = s.begin();
       it = s.upper_bound(a[i]);
       if(it==s.begin()) {
           k = (*it==a[i])?a[i]:-1;
       }
       else {
         it--;
         k = *it;
         s.erase(s.lower_bound(k));       
       }
       cout << k << endl;
   }
 
    return 0;
}
