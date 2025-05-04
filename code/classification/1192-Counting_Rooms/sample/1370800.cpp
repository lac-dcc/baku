#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        char mat[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }
        bool visited[n][m];
        int count=0;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='.' && visited[i][j]==false){
                        count++;
                        queue<pair<int,int>> q;
                        q.push(make_pair(i,j));
                        visited[i][j]=true;
                        while(!q.empty()){
                            pair<int,int> temp = q.front();
                            int a = temp.first;
                            int b = temp.second;
                            //visited[a][b]=true;
                            q.pop();
                            if(a+1<n && mat[a+1][b]=='.' && visited[a+1][b]==false){
                                q.push(make_pair(a+1,b));
                                visited[a+1][b]=true;
                            }
                            if(a-1>=0 && mat[a-1][b]=='.' && visited[a-1][b]==false){
                                q.push(make_pair(a-1,b));
                                visited[a-1][b]=true;
                            }
                            if(b+1<m && mat[a][b+1]=='.' && visited[a][b+1]==false){
                                q.push(make_pair(a,b+1));
                                visited[a][b+1]=true;
                            }
                            if(b-1>=0 && mat[a][b-1]=='.' && visited[a][b-1]==false){
                                q.push(make_pair(a,b-1));
                                visited[a][b-1]=true;
                            }
                        }
                }
            }
        }
        cout<<count<<endl;
    }
}
