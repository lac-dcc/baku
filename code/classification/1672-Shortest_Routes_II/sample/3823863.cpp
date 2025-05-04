#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
 
lint n,m;
lint Node[600][600];
void Floyd_Warshall()
{
    // Floyd-Warshall
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                Node[i][j] = min(Node[i][j],Node[i][k]+Node[k][j]);
            }
        }
    }
}
int main()
{
    int q;
    cin >> n >> m >> q;
    for(int i=0;i<600;i++){
        for(int j=0;j<600;j++){
            Node[i][j] = 0x3f3f3f3f3f3f3f3f;
            if(i == j) Node[i][j] = 0;
        }
    }
    //  Input
    for(lint i=0;i<m;i++)
    {
        lint a,b,w;
        cin >> a >> b >> w;
        Node[a][b] = min(Node[a][b],w);
        Node[b][a] = Node[a][b];
    }
    Floyd_Warshall();
    int a,b;
    for(int i=0;i<q;i++)
    {
        cin >> a >> b;
        if(Node[a][b] >= 0x3f3f3f3f3f3f3f3f)
            cout << -1 << endl;
        else
            cout << Node[a][b] << endl;
    }
    return 0;
}
