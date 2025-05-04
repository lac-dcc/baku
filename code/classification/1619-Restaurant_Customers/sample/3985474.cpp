#include<bits/stdc++.h>
using namespace std;
 
#define debug(x) cout<<"{"<<(#x)<<":"<<(x)<<"}";
#define debug2(x) cout<<"{"<<(#x)<<":"<<(x)<<"}\n";
#define ll long long
#define dd double
#define pl pair<ll,ll>
#define pi pair<int,int>
#define vl vector <pl>
#define vi vector <pi> 
#define all(v) v.begin(),v.end()           
#define trav(a,x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define sec second
#define lb(v,a) lower_bound(all(v), a)
#define ub(v,a) upper_bound(all(v), a)
#define loop(I,intialise,N,INC) for(I=intialise;I<N&&I>N;I+=INC)
#define sortd(v) sort(all(v), greater<int>());
#define forin(i,n) for(ll i=0;i<n;i++)
#define take(x) int x;cin>>x;
#define input(v) forin(i,v.size())cin>>v[i];
#define amin(a,b) a = min(a,b)
#define amax(a,b) a = max(a,b)
 
////////////////////////////////////////////////////////////////////////////////////////////////templates
 
 
 
////////////////////////////////////////////////////////////////////////////////////////////////constants            
const int MOD = 1e9 + 7;
const int max_size = 1e7;
const int inf = INT_MAX;
 
 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ascii value   0->48, a->97, A->65 write functions here
 
struct my_pair {
    int a,b;
      
    bool operator<(const my_pair& rhs) const
    {
        
        if(this->a==rhs.a)
          return this->b<rhs.b;
        return this->a<rhs.a;
    }
 
    bool operator==(const my_pair& rhs) const
    {
        return this->a==rhs.a&&this->b==rhs.b;
    }
};
 
 
/////////////////////////////////////////////////////////////////////////////////
 
void kurumi()
{  
   int n;
   cin>>n;
   multiset <my_pair> s;
   my_pair temp;
   forin(i,n)
   {
      cin>>temp.a;
      cin>>temp.b;
 
      s.insert(temp);
   }
 
   auto it = s.begin();
   int count = 1;
 
   multiset <int> end;
   end.insert(it->b);
   it++;
   while(it!=s.end())
   {
      while(!end.empty()&&*end.begin()<it->a)
        end.erase(end.begin());
      end.insert(it->b);
      it++;
 
      count = max(count,(int)end.size());
   }
 
 
   cout<<count;
 
 
   
}
 
//////////////////////////////////////////////////////////////////////////////////////
   int main ()
    {   
       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
       int zaphkeil=1,i;
       // cin>>zaphkeil;
        
        for(i=0;i<zaphkeil;i++)
         {
           kurumi();
         }
              
        return 0;
    }
 
/////////////////////////////////////////////////////////////////////////
