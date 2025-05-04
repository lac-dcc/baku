#include <iostream>
using namespace std;
 
 
int main(){
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i ++){
        long long int row, column;
        cin >> row;
        cin >> column;
        
        if (row >column){
            if (row%2 == 0){
                long long int side = row*row;
                cout << side - column + 1 << endl;
            }else{
                long long int side = (row - 1)*(row - 1) + 1;
                cout << side + column - 1 << endl;
            }
        }else{
            if (column%2 == 0){
                long long int side = (column - 1)*(column - 1) + 1;
                cout << side + row - 1 << endl;
            }else{
                long long int side = column*column;
                cout << side - row + 1 << endl;
            }
        }
    }
}
