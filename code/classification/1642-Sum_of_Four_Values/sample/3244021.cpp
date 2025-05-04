#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main() {
    int N, target;
    cin >> N >> target;
    pair<int, int> nums[N];
    for(int i = 0; i < N; i++) {
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }
    sort(nums, nums+N);
 
    for(int i = 0; i < N; i++) {
        int left = i;
        for(int j = i+1; j < N; j++) {
            int m1 = j, m2 = j+1, r = N-1;
            int curr = 0;
            while (m2 < r) {
                curr = nums[left].first + nums[m1].first + nums[m2].first + nums[r].first;
                if (curr > target) {
                    r--;
                } else if(curr < target) {
                    m2++;
                } else {
 //                   cout << nums[left].first << " " << nums[m1].first << " " << nums[m2].first<< " " <<nums[r].first << endl;
                    cout << nums[left].second << " " << nums[m1].second << " " << nums[m2].second << " " <<nums[r].second << endl;
                return 0;
                }
        }
        }
    }
    cout << "IMPOSSIBLE" << endl;
} 
