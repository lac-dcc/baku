#include <iostream>
#define MOD 1000000007
using namespace std;
 
int N, target;
 
int coins[100];
int memo[1000001];
 
int conta(int x){
    if(x<0)
        return 0;
 
    if(x == 0)
        return 1;
 
    if(memo[x] != -1)
        return memo[x];
 
    int a = 0;
 
    for(int i = 0; i<N; i++){
        a += conta(x-coins[i]);
        a %= MOD;
    }
 
    memo[x] = a;
 
    return a;
 
}
 
 
int main()
{
 
    for(int i = 0; i<=1000000;i++){
        memo[i] = -1;
    }
 
    //cin>>N>>target;
    scanf("%d",&N);
    scanf("%d",&target);
 
    for(int i = 0; i<N; i++){
        //cin>>coins[i];
        scanf("%d",&coins[i]);
    }
 
    printf("%d",conta(target));
 
    return 0;
}
