#include <iostream>
#include <algorithm>
using namespace std;
 
int n;
int nums[1001];
struct two_sum {
    long long v;
    int a;
    int b;
}two_sums [1000000];
int m;
long long target;
int cnt[1001];
int cnt_both[1001][1001];
 
bool cmp(struct two_sum p1, struct two_sum p2) {
    return p1.v < p2.v;
}
 
int check(int part1, int part2) {
    int cnt_part2 = 0;
    for (int i = part2; i >= 0 && two_sums[i].v == two_sums[part2].v; i--) {
        cnt[two_sums[i].a]++;
        cnt[two_sums[i].b]++;
        cnt_both[two_sums[i].a][two_sums[i].b]++;
        cnt_part2++;
    }
    for (int i = part1; i < m && two_sums[i].v == two_sums[part1].v; i++) {
        if (two_sums[i].v == two_sums[part2].v) {
            cnt[two_sums[i].a]--;
            cnt[two_sums[i].b]--;
            cnt_both[two_sums[i].a][two_sums[i].b]--;
        }
        int a = two_sums[i].a;
        int b = two_sums[i].b;
        int c = cnt[a] + cnt[b] - cnt_both[a][b];
        if (c != cnt_part2) {
            return i;
        }
        if (two_sums[i].v == two_sums[part2].v) {
            cnt[two_sums[i].a]++;
            cnt[two_sums[i].b]++;
            cnt_both[two_sums[i].a][two_sums[i].b]++;
        }
    }
 
    for (int i = part2; i >= 0 && two_sums[i].v == two_sums[part2].v; i--) {
        cnt[two_sums[i].a] = 0;
        cnt[two_sums[i].b] = 0;
        cnt_both[two_sums[i].a][two_sums[i].b] = 0;
    }
 
    return -1;
}
 
int main() {
    cin >> n >> target;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            two_sums[m].v = nums[i] + nums[j];
            two_sums[m].a = i;
            two_sums[m].b = j;
            m++;
        }
    }
    sort(two_sums, two_sums + m, cmp);
    int lo = 0, hi = m - 1;
    bool solvable = false;
    while (lo < hi) {
        long long t = two_sums[lo].v + two_sums[hi].v;
        if (t > target) {
            hi--;
        } else if (t < target) {
            lo++;
        } else {
            int pos = check(lo, hi);
            if (pos != -1) {
                solvable = true;
                cout << two_sums[pos].a << " " << two_sums[pos].b << " ";
                while (hi >= 0) {
                    if (pos != hi and two_sums[hi].a != two_sums[pos].a and two_sums[hi].a != two_sums[pos].b
                       and two_sums[hi].b != two_sums[pos].a and two_sums[hi].b != two_sums[pos].b) {
                        cout << two_sums[hi].a << " " << two_sums[hi].b << "\n";
                        break;
                    }
                    hi--;
                }
                break;
            } else {
                while (lo + 1 < m && two_sums[lo + 1].v == two_sums[lo].v) {
                    lo++;
                }
                lo++;
                while (hi > 0 && two_sums[hi - 1].v == two_sums[hi].v) {
                    hi--;
                }
                hi--;
            }
        }
    }
    if (!solvable) {
        cout << "IMPOSSIBLE\n";
    }
 
    return 0;
}
