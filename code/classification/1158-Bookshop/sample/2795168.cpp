#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
 
const int MAX_BOOKS = 1000;
const int MAX_TOTAL = 100000;
 
int npages[MAX_BOOKS];
int price[MAX_BOOKS];
 
int lookup[MAX_TOTAL];
 
//const int MOD = 1000000007;
 
int solution(int books, int total) {
    for(int i = 0; i != books; ++i) {
        for(int j = total; price[i] <= j; --j) {
            lookup[j] = std::max(lookup[j - price[i]] + npages[i], lookup[j]);
        }
    }
    return *std::max_element(&lookup[0], &lookup[total + 1]);
}
 
int main() {
    int books, total;
    scanf("%d %d", &books, &total);
    for(int i = 0; i != books; ++i) {
        scanf("%d", &price[i]);
    }
    for(int i = 0; i != books; ++i) {
        scanf("%d", &npages[i]);
    }
    printf("%d\n", solution(books, total));
    return 0;
}