#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        long long int y, x;
        cin>>y>>x;
        long long int square = max(x, y);
        long long int ans;
        if(square % 2 == 0){
            //  starts with column
            long long int end = square * square;
            long long int start = end - (2 * square) + 2;
            if(x > y){
                ans = start + y - 1;
            }
            else{
                ans = end - x + 1;
            }
        }
        else{
            //  starts with row
            long long int end = square * square;
            long long int start = end - (2 * square) + 2;
            if(x < y){
                ans = start + x - 1;
            }
            else{
                ans = end - y + 1;
            }
        }
        cout<<ans<<endl;
    }
}
