#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long int lli;
 
void nhap();
void floyd_warshall();
 
lli MIN(lli,lli);
lli n,m,q,matrix1[505][505]={999999999999},matrix2[500][500];
vector<pair<int,int>> END;
 
int main() {
    nhap();
    floyd_warshall();
    for(lli i=0;i<END.size();i++)
    {
        if(matrix2[END[i].first-1][END[i].second-1]==999999999999)
            cout<<-1<<endl;
        else
            cout<<matrix2[END[i].first-1][END[i].second-1]<<endl;
    }
    return 0;
}
 
void floyd_warshall()
{
    for(lli k=0;k<n;k++)
    {
        for(lli i=0;i<n;i++)
        {
            for(lli j=0;j<n;j++)
            {
                matrix2[i][j]=MIN(matrix2[i][j],matrix2[i][k]+matrix2[k][j]);
            }
        }
    }
}
lli MIN(lli a,lli b){
    if(a>b)
        return b;
    return a;
}
void nhap()
{
    int a,b,c;
    cin>>n>>m>>q;
    for(lli i=0;i<n;i++){
        for(lli j=0;j<n;j++) {
            matrix1[i][j]=999999999999;
        }
    }
    for(lli i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        matrix1[a-1][b-1]=MIN( matrix1[a-1][b-1],c);
        matrix1[b-1][a-1]=MIN( matrix1[b-1][a-1],c);
    }
    int e,f;
    for(lli i=0;i<q;i++)
    {
        cin>>e>>f;
        END.push_back(make_pair(e,f));
    }
    for(lli i=0;i<n;i++){
        for(lli j=0;j<n;j++) {
            if(i==j){matrix2[i][j]=0;}
            else{matrix2[i][j]=matrix1[i][j];}
        }
    }
//    for(lli i=0;i<n;i++){
//        for(lli j=0;j<n;j++) {
//            cout<<matrix1[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
