#include <bits/stdc++.h>
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    int m_el = int(2e9)*-1;
    bool is_less_than_zero = true;
    vector<int> A(N);
    for(int &i: A){
        cin >> i;
        m_el = max(m_el, i);
        is_less_than_zero = is_less_than_zero && i < 0;
    }
 
    int64_t max_sum = 0;
    int64_t curr_sum = 0;
 
    for(int i = 0;i<N; ++i){
        curr_sum += A[i];
        if(curr_sum > max_sum)
            max_sum = curr_sum;
        if(curr_sum < 0)
            curr_sum = 0;
    }
    if(is_less_than_zero)max_sum = m_el;
    cout << max_sum << '\n';
    return 0;
}
