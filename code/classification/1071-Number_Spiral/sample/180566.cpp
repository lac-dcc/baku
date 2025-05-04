#include<bits/stdc++.h>
#pragma optimize("Ofast")
#pragma("O")
#pragma("O2")
#pragma("O3")
#pragma("Os")
 
#define int long long
 
int sq(int n){
  return n*n;
}
 
int32_t main(){
  
    int tc,r,c,n,ans; scanf("%lld",&tc);
    
    while(tc--){
 
      scanf("%lld%lld",&r,&c);
 
      n = std::max(r,c); //nth_col_term
 
      int first_row_nth_col_term = sq(n-1) + (n-1) + 1 ;
      
      if((n-1)%2==0) first_row_nth_col_term+=(n-1);
      else first_row_nth_col_term-=(n-1);
 
      ans = first_row_nth_col_term;
 
      if(c>=r){
        if(c%2==0) ans+=(r -1);
        else ans-=(r -1);
      }
      else{
        if(r%2==0){
          ans+=(r*2)-2;
          ans-=(c-1);
        }
        else{
          ans-=(r*2)-2;
          ans+=(c-1);
        }
      }
 
      printf("%lld\n",ans);
    }
    
    return 0;
} 
