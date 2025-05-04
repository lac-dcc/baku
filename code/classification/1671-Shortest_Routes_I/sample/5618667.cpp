#include <array>
#include <ios>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
 
using std::array;
using std::cin;
using std::cout;
using std::ios_base;
using std::pair;
using std::priority_queue;
using std::vector;
 
using Flight = pair<int, long long>;
using Neighbor = array<int, 2>;
 
auto solve() {
 
    auto m = 0;
    auto n = 0;
 
    cin >> n >> m;
 
    auto neighbors = vector<vector<Neighbor>>(n);
 
    for (auto i = 0; i < m; ++i) {
        auto a = 0;
        auto b = 0;
        auto c = 0;
        cin >> a >> b >> c;
        --a;
        --b;
        neighbors[a].push_back(Neighbor({b, c}));
    }
 
    const auto compareFlights = [](const Flight& flight_1, const Flight& flight_2) {
        return flight_1.second > flight_2.second;
    };
    auto distances = vector<long long>(n, -1);
 
    auto process = priority_queue<Flight, vector<Flight>, decltype(compareFlights)>(compareFlights);
 
    process.emplace();
 
    while (!process.empty()) {
        const auto [city, distance] = process.top();
        process.pop();
        if (distances[city] == -1) {
            distances[city] = distance;
            for (const auto& [b, c] : neighbors[city]) {
                if (distances[b] == -1) {
                    process.emplace(b, distances[city] + c);
                }
            }
        }
    }
 
    for (auto i = 0; i < n; ++i) {
        cout << distances[i] << (i < n - 1 ? ' ' : '\n');
    }
 
}
 
int main() {
 
    cin.tie(nullptr);
 
    ios_base::sync_with_stdio(false);
 
    solve();
 
    return 0;
 
}