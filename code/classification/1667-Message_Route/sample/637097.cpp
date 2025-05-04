#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
 
#define MOD 1000000007
 
using namespace std;
 
 
 
int main() {
    int n, m;
    int a,b;
    vector<vector<int>> roads;
    vector<int> first;
    
    cin >> n >> m;
    
    first.push_back(-1);
    for(int i=0; i<n; ++i) {
        roads.push_back(first);
    }
    
    for(int i=0; i<m; ++i) {
        cin >> a >> b;
        roads[a-1].push_back(b-1);
        roads[b-1].push_back(a-1);
    }
    
    
    
    queue<int> toVisit;
    bool visited[100000];
    for(int i=0; i<n; ++i) {
        visited[i] = false;
    }
    int distance[100000];
    int comeFrom [100000];
    
    distance[0] = 0;
    for(int i=1; i<n; ++i) {
        distance[i] = -1;
    }
    
    toVisit.push(0);
    int compNow;
    while(toVisit.size()!= 0) {
        compNow = toVisit.front();
        toVisit.pop();
        visited[compNow] = true;
        
        for(int connection : roads[compNow]) {
            if(connection != -1) {
                if(distance[connection] == -1) {
                    toVisit.push(connection);
                    distance[connection] = distance[compNow] + 1;
                    comeFrom[connection] = compNow;
                }
            }
        }
    }
    
    if(distance[n-1] == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << distance[n-1]+1 << "\n";
        stack<int> answer;
        int i=n-1;
        answer.push(i);
        while(i != 0) {
            answer.push(comeFrom[i]);
            i=comeFrom[i];
        }
        
        while(answer.size()!=0) {
            cout << answer.top()+1 << " ";
            answer.pop();
        }
        cout << "\n";
    }
}
