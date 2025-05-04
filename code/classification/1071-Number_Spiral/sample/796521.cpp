    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    int main()
    {
       ll t;cin>>t;
       ll ans;
       while(t--)
       {
           ll x,y;
           cin>>x>>y;
           if(x>=y)
           {
               if(x&1)
               {
                   ans=(x-1)*(x-1)+y;
                   cout<<ans<<endl;
               }
               else{
                   ans=(x)*x-y+1;
                   cout<<ans<<endl;
               }
           }
           else
           {
               if(y&1)
               {
                   ans=(y*y)-x+1;
                   cout<<ans<<endl;
               }
               else
               {
                   ans=(y-1)*(y-1)+x;
                   cout<<ans<<endl;
               }
           }
       }
    }
