#include <iostream>
using namespace std;
 
int main() {
    int book;
    int prize;
    cin>>book>>prize;
    int books[book];
    int pages[book];
    for(int i=0;i<book;i++)cin>>books[i];
    for(int i=0;i<book;i++)cin>>pages[i];
    int dp[book+1][prize+1];
    for(int i=0;i<book+1;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<prize+1;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<book+1;i++){
        for(int j=1;j<prize+1;j++){
            if(j-books[i-1]>=0){
                dp[i][j]=max(pages[i-1]+dp[i-1][j-books[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[book][prize];
	return 0;
}