#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#define int long long
using namespace std;
int numNodes, m, q;
// Floyd-Warshall算法
void FloydWarshall(vector<vector<int>>& graph, int numNodes) {
    vector<vector<int>> distances(graph);  // 存储所有节点对之间的最短距离
    vector<vector<int>> next(numNodes+5, vector<int>(numNodes+5, -1));  // 存储最短路径上每个节点的下一个节点
 
    // 初始化next矩阵
    for (int i = 1; i <= numNodes; ++i) {
        for (int j = 1; j <=numNodes; ++j) {
            if (graph[i][j] != 9223372036854775807 && i != j) {
                next[i][j] = j;
            }
        }
    }
    for(int i = 1 ; i <= numNodes ; i ++){
        distances[i][i] = 0;
    }
    // 进行动态规划计算最短路径和下一个节点
    for (int k = 1; k <= numNodes; ++k) {
        for (int i = 1; i <= numNodes; ++i) {
            for (int j = 1; j <= numNodes; ++j) {
                //distances[i][j] = min(distances[i][k] + distances[k][j], distances[i][j]);
                if (distances[i][k] != 9223372036854775807 && distances[k][j] != 9223372036854775807 &&
                    distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
 
    for(int i = 0 ; i < q ; i++){
        int x, y;
        cin >> x >> y;
        if(distances[x][y]>=1e15){
            cout << -1 << endl;
            continue;
        }
        cout << distances[x][y] << endl;
    }
////    // 回溯最短路径
//    for (int i = 0; i < numNodes; ++i) {
//        for (int j = 0; j < numNodes; ++j) {
//            if (i != j && next[i][j] != -1) {
//                stack<int> path;
//                int currNode = i;
//                while (currNode != j) {
//                    path.push(currNode);
//                    currNode = next[currNode][j];
//                }
//                path.push(currNode);
//
//                 输出最短路径
//                cout << "从节点 " << i << " 到节点 " << j << " 的最短路径：";
//                while (!path.empty()) {
//                    cout << path.top() << " ";
//                    path.pop();
//                }
//                cout << endl;
//            }
//        }
//    }
}
 
signed main() {
    cin >> numNodes >> m >> q;
 
    // 创建一个有向图的邻接矩阵，使用INT_MAX表示两个节点之间无连接
    vector<vector<int>> graph(numNodes+5, vector<int>(numNodes+5, 9223372036854775807));
 
    // 输入图的边权重
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x][y] = min(w,graph[x][y]);
        graph[y][x] = min(w,graph[y][x]);
    }
 
 
    FloydWarshall(graph, numNodes);
 
    return 0;
}
