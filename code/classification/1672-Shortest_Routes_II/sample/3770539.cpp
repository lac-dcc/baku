#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
  
 
long long a[502][502];
int main() {
    long long n,m,q,c;
    int i,j,k,s,e;
    cin>>n>>m>>q;
    for(i = 0; i < 502;i++)
    {for(j=0;j<502;j++){
    a[i][j]=1000000000000003;}
    a[i][i]=0;
    }
    for(i = 0; i < m; i++){
        cin>>s>>e>>c;
        a[s][e]=min(a[s][e],c);
        a[e][s]=a[s][e];
    }
    for(k = 0; k <= n; k++)
    {
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(a[i][j]>a[i][k]+a[k][j])
                {a[i][j]=a[i][k]+a[k][j];
                a[j][i]=a[i][j];}
            }
        }
    }
    for(i = 0; i < q; i++)
    {
        cin>>s>>e;
        if(a[s][e]==1000000000000003)
        cout<<"-1\n";
        else
        cout<<a[s][e]<<"\n";
    }
}
