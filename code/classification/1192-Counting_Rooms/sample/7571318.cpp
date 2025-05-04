#include <bits/stdc++.h>
 
using namespace std;
 
char mat[1010][1010];
int t=0, a, m, n;
 
void dfs(int x, int y)
{
    if(x<0 || x>n || y<0 || y>m) return;
    if(mat[x][y]!='.') return;
    
    mat[x][y]='#';
    
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}
int main()
{
 
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]=='.')
            {
                dfs(i, j);
                t++;
            }
        }
    }
    
    cout<<t<<endl;
    
}
