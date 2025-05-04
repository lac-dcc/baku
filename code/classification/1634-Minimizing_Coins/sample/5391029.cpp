#include <iostream>
#include <vector>
using std::vector, std::cout, std::cin;
void print(vector<int>& a){
    for(size_t i = 0; i < a.size(); i++){
        cout << a.at(i) << " ";
    }
    cout << "\n";
}
int get_min_coins(vector<int>& coins, int target){
    vector<int> curr_coin_amount(target + 1, -1);
    curr_coin_amount[0] = 0;
    for(size_t i = 0; i < coins.size(); i++){
        size_t j = 0;
        while(j < curr_coin_amount.size()){
            if(curr_coin_amount[j] == -1){
                j++;
                continue;
            }
            if(j + coins.at(i) >= curr_coin_amount.size()){
                break;
            }
            if(curr_coin_amount[j + coins.at(i)] == -1 || curr_coin_amount[j] + 1 < curr_coin_amount[j + coins.at(i)]){
                curr_coin_amount[j + coins.at(i)] = curr_coin_amount[j] + 1;
            }
            j++;
        }
    }
    return curr_coin_amount[target];
}
int main(){
    int n;
    int target;
    cin >> n;
    cin >> target;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    cout << get_min_coins(coins, target) << "\n";
}