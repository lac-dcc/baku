#include<bits/stdc++.h>
using namespace std;
 
 
    int n, m;
    char matriz[1000][1000];
 
bool is_possible(int x, int y){
    if(x>= 0 && x < n && y >= 0 && y < m && matriz[x][y] == '.'){
        matriz[x][y] = '+';
        return true;
    }
    return false;
}
void virar(int x, int y){
    if(is_possible(x+1, y)){
        virar(x+1,y);
    }
    if(is_possible(x-1,y)){
        virar(x-1,y);
    }
    if(is_possible(x,y+1)){
        virar(x,y+1);
    }
    if(is_possible(x,y-1)){
        virar(x,y-1);
    }
}
 
 
int main(){
    cin >> n >> m;
    int cont = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            cin >> matriz[i][j];
        }
    }
 
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            if(matriz[i][j] == '.'){
                virar(i,j);
                cont++;
            }
        }
    }
    cout << cont << endl;
}
 
