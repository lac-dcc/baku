/*
        Author ::  _mak_ 
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll            long long
#define pb            push_back
#define rep(i,a,n )   for( int i=a;i<n;i++)
#define all(v)        v.begin() , v.end()
#define gcd(a,b)      __gcd(a,b);
#define lb            lower_bound
#define ub            upper_bound
#define ss             second
#define ff             first
typedef pair < int , int  > pii ;
typedef pair < ll , ll >  pll ;  
// #define PI            3.1415926535
 
template < typename A , typename B > ostream& operator<< ( ostream &cout , pair < A , B > &p  ){  cout<<"[ "<<p.ff<<" , "<<p.ss<<" ] ";  }
template < typename A > ostream& operator<< ( ostream &cout , vector < A > &p  ){ for( auto r : p  ){ cout<<r<<' ';  } cout<<'\n' ;  }
 
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);      
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int n , m ; cin>>n>>m; 
    vector < vector <  pll > > p( n+1 , vector< pll >());
 
    rep( i , 0 , m  ){
        ll a , b, c ; cin>>a>>b>>c;
        p[a].pb({b,c}); 
    }
 
    set < pll > r ; 
    r.insert({0,1}); 
    vector < pll > d( n+1 , { 1e14 , -1 } ); 
    d[0] = {0 , 0 }; 
    while( !r.empty()){
        auto it = r.begin() ; auto g = *it ; r.erase(it); 
        ll v = g.ff , b = g.ss ; // cout<<b<<' '; 
        for( auto w : p[b] ){
            ll k = v + w.ss ; 
            if( d[w.ff].ff > k   ){
                r.erase({d[w.ff].ff , w.ff });  
                d[w.ff] = { k , max(w.ss , d[b].ss )}; 
                r.insert({ k , w.ff }); 
            }else if ( d[w.ff].ff == k ){
                d[w.ff].ss = max( d[w.ff].ss , max( d[b].ss , w.ss ) );  
            }     
        }
    }
 
    r.clear(); 
    ll ans = d[n].ff - d[n].ss + d[n].ss/2 ; 
 
   //  set < pll > r ; 
    r.insert({0,1}); 
    d.assign( n+1 , { 1e14 , -1 } ); 
    d[0] = {0 , 0 }; 
    while( !r.empty()){
        auto it = r.begin() ; auto g = *it ; r.erase(it); 
        ll v = g.ff , b = g.ss ; // cout<<b<<' '; 
        for( auto w : p[b] ){
            ll k = v , j = -1 ; 
            if( b==1 ){
                k = w.ss/2 ; j = w.ss ;  
            }else{
                if( w.ss > d[b].ss ){
                    k = v - d[b].ss/2 + d[b].ss + w.ss/2 ;  j = w.ss ; 
                }else{
                    k += w.ss ; j = d[b].ss ; 
                }
            }
 
            if( d[w.ff].ff > k   ){
                r.erase({d[w.ff].ff , w.ff }); 
                d[w.ff] = { k , j }; 
                r.insert({ k , w.ff }); 
            }else if ( d[w.ff].ff == k ){    
                d[w.ff].ss = min( d[w.ff].ss , j  );  
            }      
        }
    }
 
    cout<<min( ans ,  d[n].ff )<<'\n'; 
    
return 0;
}
     
   
               
   
 
