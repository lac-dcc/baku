    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #include<vector>
    #define mod 1000000007
    #include<stack>
    int main()
    {
         /*ll t;
         cin>>t;
         while(t--){*/
         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
         ll n,i,k,r=0,p=0,j,x,y=0,pp=0,k1,r1=0;
         cin>>n>>k;
         ll a[n+5],b[n+5];
         map<ll,ll> m,m1;
         vector<ll> v;
         for(i=0;i<n;i++)
         {
             cin>>a[i];
             //a[i]=b[i];
             m[a[i]]=i+1;
             m1[a[i]]++;
         }
         if(k%2==0)
         {
             k1=k/2;
             if(m1[k1]>=2)
             {
                 for(i=0;i<n;i++)
                 {
                     if(a[i]==k1)
                     {
                         v.push_back(i+1);
                         r1++;
                         if(r1==2)
                         {
                             break;
                         }
                     }
                 }
                 cout<<v[0]<<" "<<v[1]<<"\n";
             }
             else{
                 sort(a,a+n);
         i=0,j=n-1;
         while(i<j)
         {
             x=a[i]+a[j];
             if(x>k)
             {
                 j--;
             }
             else if(x<k)
             {
                   i++;
             }
             else if(x==k)
             {
                 pp=1;
                 y=m[a[i]];
                 p=m[a[j]];
                 break;
             }
         }
         if(pp)
         {
             cout<<y<<" "<<p<<"\n";
         }
         else{
             cout<<"IMPOSSIBLE\n";
         }
             }
         }
         else{
         sort(a,a+n);
         i=0,j=n-1;
         while(i<j)
         {
             x=a[i]+a[j];
             if(x>k)
             {
                 j--;
             }
             else if(x<k)
             {
                   i++;
             }
             else if(x==k)
             {
                 pp=1;
                 y=m[a[i]];
                 p=m[a[j]];
                 break;
             }
         }
         if(pp)
         {
             cout<<y<<" "<<p<<"\n";
         }
         else{
             cout<<"IMPOSSIBLE\n";
         }
         }
        // }
    return 0;
    }
