#include <bits/stdc++.h> 
#include<vector>
using namespace std;
typedef long long ll;
typedef vector <ll> v1;
v1 OneD;
multiset<pair<ll,ll> > ms;
multimap<ll,ll> pos;
bool isEnd(ll i)
{
    auto it=pos.find(i);
            if((it->second)%2==0)
                return false;
            return true;
}
int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,t=0;
    cin>>n;    
    v1 start,end,arr;
    for(ll i=0;i<n;i++){
        ll p1,p2;
        cin>>p1>>p2;
        ms.insert(make_pair(p1,p2));
        OneD.push_back(p1);
        pos.insert({p1,t}); t++;
        OneD.push_back(p2);
        pos.insert({p2,t}); t++;
 
    }
    for(auto it =ms.begin();it!=ms.end();++it){
        start.push_back((ll)it->first);
        end.push_back((ll)it->second);
    }
   arr=OneD;
   sort(arr.begin(),arr.end());
   ll mx=0,count=0,i=0,k=0,temp;
   while(i<n*2 && k<n){
       temp=arr[i];
       if(temp<end[k]){
           if(isEnd(temp))
               count--;
            else
            {
                count++;   
            }    
       }
       if(temp==end[k]){
           count--;
           k++;
        }
        if(temp>end[k])
            k++;
       mx=max(mx,count);
        i++;
   }
   cout<<mx<<"\n";
 
}
