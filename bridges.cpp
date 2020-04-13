/// Name: bridges
/// Description: find bridges in graph. If bridge is removed you get more connected components. 
/// Guarantee: void dfsBridges(long long node, long long parent) {
vector<vector<long long>> graph;
vector<bool> visited;
vector<long long> low;
vector<long long> in;
// use one_way to get one possible way to visit all nodes if edges are one-directional
// vector<pair<long long,long long>> one_way;
bool hasBridge;
long long counter;

void dfsBridges(long long node, long long parent) {
    visited[node] = 1;
    low[node] = in[node] = counter++;

    for(auto neigh : graph[node]) {
        if (neigh == parent) continue;
        if (visited[neigh]) {
            low[node] = min(low[node], in[neigh]);
            // if (in[node] > in[neigh]) {
            //     one_way.push_back({node, neigh});
            // }
        } else {
            dfsBridges(neigh, node);
            if (low[neigh] > in[node]) {
                hasBridge = true;
                return;
            }
            low[node] = min(low[node], low[neigh]);
            // one_way.push_back({node, neigh});
        }
    }
}
