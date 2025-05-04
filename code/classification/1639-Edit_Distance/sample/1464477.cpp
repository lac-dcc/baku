#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <iomanip>
 
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair
 
using namespace std;
 
typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;
 
class TaskC {
public:
  void solveOne(istream &in, ostream &out) {
    string s1, s2;
    in >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector <vi> dp = vector<vi>(n + 1, vi(m + 1));
    for (int i = 1; i < n + 1; ++i) {
      dp[i][0] = i;
    }
    for (int i = 0; i < m + 1; ++i) {
      dp[0][i] = i;
    }
    for (int i = 1; i < n + 1; ++i) {
      for (int j = 1; j < m + 1; ++j) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }
      }
    }
    out << dp[n][m];
  }
};
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  TaskC solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  solver.solveOne(in, out);
}
 
 
