#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int MAX_N = 2e5;
using pi = pair<int,int>;
#define pb push_back
#define mp make_pair
 
int main(){
          lli n,sum=0,ma=-9e18;
    cin>>n;
    vector<lli>v(n);
    for(lli &i:v)
    {
    	cin>>i;
    	sum=max(sum+i,i);
    	ma=max(ma,sum);
   }
   cout<<ma<<endl;
           
           return 0;
}