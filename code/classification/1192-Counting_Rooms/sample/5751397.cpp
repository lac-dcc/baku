#include<bits/stdc++.h>
using namespace std;
 
int floodCount=0;
 
int r,c;
const int N=2005;
int mat[N][N];
int visited[N][N];
 
int dr[]= {0,0,1,-1};
int dc[]= {1,-1,0,0};
 
 
bool isInside(pair<int,int>coordinate)
{
    if(coordinate.first>=0 && coordinate.first<r  && coordinate.second>=0 && coordinate.second<c  )
    {
        return true;
    }
    return false;
}
 
bool isSafe(pair<int,int>coordinate)
{
    if(mat[coordinate.first][coordinate.second]==-1)
    {
        return false;
    }
    return true;
}
 
 
void DFS(pair<int,int> src)
{
   // queue<pair<int,int>>q;
    visited[src.first][src.second]=1;
 
    int curR=src.first;
    int curC=src.second;
 
    for(int i=0; i<4; i++)
    {
        int newR=curR+dr[i];
        int newC=curC+dc[i];
        pair<int,int>adj_node= {newR,newC};
        if(isInside(adj_node) && isSafe(adj_node) && visited[newR][newC]==0 )
        {
            DFS(adj_node);
        }
    }
}
 
 
int main()
{
    cin>>r>>c;
    pair<int,int>src,dst;
 
    for(int i=0; i<r; i++)
    {
        string s;
        cin>>s;
        for(int j=0; j<c; j++)
        {
            if(s[j]=='#')
            {
                mat[i][j]=-1;
            }
        }
    }
 
//    cout<<"After conversion the graph is: "<<endl;
//    for(int i=0;i<r;i++){
//        for(int j=0;j<c;j++){
//            cout<<mat[i][j]<<"\t";
//        }
//        cout<<endl;
//    }
 
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(visited[i][j]==0 && mat[i][j]==0)
            {
                //cout<<i<<" "<<j<<endl;
                DFS({i,j});
                floodCount++;
            }
        }
    }
 
 
    //cout<<"Number of flood "<<floodCount<<endl;
    cout<<floodCount<<endl;
 
    return 0;
}
 
 
 
 
/*
 
https://cses.fi/problemset/task/1192
 
5 8
########
#..#...#
####.#.#
#..#...#
########
 
 
*/
 
