#include <iostream>
#include <queue>
#include <vector>
 
using std::cout;
using std::endl;
using std::vector;
 
int main() {
	int city_num;
	int flight_num;
	std::cin >> city_num >> flight_num;
	vector<vector<std::pair<int, int>>> neighbors(city_num);
	for (int f = 0; f < flight_num; f++) {
		int from;
		int to;
		int cost;
		std::cin >> from >> to >> cost;
		neighbors[--from].push_back({--to, cost});
	}
 
	vector<vector<long long>> min_cost(city_num, {INT64_MAX, INT64_MAX});
	min_cost[0] = {0, 0};
 
	struct Pos {
		int pos;         // the current position
		bool used;       // whether we've used up our discount yet
		long long cost;  // the cost associated with this state
	};
	auto cmp = [&](const Pos &a, const Pos &b) { return a.cost > b.cost; };
	std::priority_queue<Pos, vector<Pos>, decltype(cmp)> frontier(cmp);
	frontier.push({0, false, 0});
 
	while (!frontier.empty()) {
		Pos curr = frontier.top();
		frontier.pop();
		long long curr_cost = min_cost[curr.pos][curr.used];
		if (curr_cost != curr.cost) { continue; }
		if (curr.pos == city_num - 1) { break; }
		for (auto [n, nc] : neighbors[curr.pos]) {
			// if we haven't used the discount yet, try using it now
			if (!curr.used) {
				long long new_cost = curr_cost + nc / 2;
				if (new_cost < min_cost[n][true]) {
					min_cost[n][true] = new_cost;
					frontier.push(Pos{n, true, new_cost});
				}
			}
			// but we can always just try the normal cost route
			if (curr_cost + nc < min_cost[n][curr.used]) {
				min_cost[n][curr.used] = curr_cost + nc;
				frontier.push(Pos{n, curr.used, curr_cost + nc});
			}
		}
	}
	cout << min_cost[city_num - 1][1];
}
