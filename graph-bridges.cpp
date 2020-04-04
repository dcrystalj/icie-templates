/// Name: graph - bridges
/// Description: Find bridge between connected components, if bridge (edge) is removed, grap is split into more pieces https://www.youtube.com/watch?v=aZXi1unBdJA
/// Guarantee: void findBridges() {

long long id = 0;
long long N; // edges.size();
vector<long long> low;  // Low link values;
vector<long long> ids; // Nodes ids;
vector<bool> visited; // filled after dfs
vector<vector<long long>> edges; // graf
vector<pair<long long, long long>> bridges; // result


void dfsBridges(long long at, long long parent) {
    visited[at] = true;
    low[at] = ids[at] = ++id;
    for (auto & to : edges[at]) {
      if (to == parent) continue;
      if (!visited[to]) {
        dfsBridges(to, at);
        low[at] = min(low[at], low[to]);
        if (ids[at] < low[to]) {
          bridges.push_back({at, to});
        }
      } else {
        low[at] = min(low[at], ids[to]);
      }
    }
}

void findBridges() {
    low.assign(N, 0);
    ids.assign(N, 0);
    visited.assign(N, false);
    // Finds all bridges in the graph across various connected components.
    for (long long i = 0; i < N; i++) {
        if (!visited[i]) {
            dfsBridges(i, -1);
        }
    }
}