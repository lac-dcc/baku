/*
4 10
4 8 5 3
5 12 8 1
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
int memoCalc[1001][100002];
 
// int calc(int books, int priceTotal, int price[], int pages[]) {
//     if (priceTotal == 0 || books == 0) {
//         return memoCalc[books][priceTotal] = 0;
//     }
//     if (memoCalc[books][priceTotal] != -1) {
//         return memoCalc[books][priceTotal];
//     }
//     if (price[books - 1] <= priceTotal) {
//         memoCalc[books][priceTotal] = max(pages[books - 1] + calc(books - 1, priceTotal - price[books - 1], price, pages), calc(books - 1, priceTotal, price, pages));
//     } else {
//         memoCalc[books][priceTotal] = calc(books - 1, priceTotal, price, pages);
//     }
//     return memoCalc[books][priceTotal];
// }
 
int main(){
    int books, priceTotal;
    cin >> books >> priceTotal;
    int price[books];
    for (int i = 0; i < books; i++) {
        cin >> price[i];
    }
    int pages[books];
    for (int i = 0; i < books; i++) {
        cin >> pages[i];
    }
    memset(memoCalc,-1,sizeof(memoCalc));
    // calc(books, priceTotal, price, pages);
    for (int i = 0; i <= books; i++) {
        for (int j = 0; j <= priceTotal; j++) {
            if (j == 0 || i == 0) {
                memoCalc[i][j] = 0;
            } else if (price[i - 1] <= j) {
                memoCalc[i][j] = max(pages[i - 1] + memoCalc[i - 1][j - price[i - 1]], memoCalc[i - 1][j]);
            } else {
                memoCalc[i][j] = memoCalc[i - 1][j];
            }
        }
    }
    cout << memoCalc[books][priceTotal] << endl;
    
    return 0;
}
