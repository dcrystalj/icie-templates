/// Name: LCA
/// Description: binary lifting
/// Guarantee: long long lca(long long u,long long v){

// sources:
// https://pastebin.com/XMPmkb6W https://codeforces.com/blog/entry/22325 https://www.youtube.com/watch?v=ctZ7fjMbPWE
// usage example:
// cin >> n;
// neighbors.assign(n, vector<pair<long long, long long>>());
// for (LL i = 0; i < n-1; i++) {
//     cin >> a >> b; a--; b--;
//     neighbors[a].push_back({b, 1});
//     neighbors[b].push_back({a, 1});
// }
// init(n);

long long N; // number of nodes
long long LOGN;
vector<vector<pair<long long, long long>>> neighbors; // graph [u][{v, weight}]
vector<vector<long long>> parent; // [log(N)][N]
vector<long long> depth;
vector<long long> weight;
vector<bool> visited;

long long uplift(long long u, long long k){ // get k-th parent of u
    for(long long i=0; i < LOGN; i++){
        if(k&1) u = parent[i][u];
        k>>=1;
    }
    return u;
}
 
void dfs(long long u) {
    visited[u] = 1;
    for (const auto & [v, w]: neighbors[u]) {
        if (visited[v]) continue;
        parent[0][v] = u;
        weight[v] = weight[u] + w;
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}
 
void init(long long n) {
    N = n;
    LOGN = (long long)ceil(log(N)) + 1;
    weight.assign(N, 0);
    visited.assign(N, false);
    depth.assign(N, 0);
    parent.assign(LOGN, vector<long long>(N, -1));
    dfs(0);
    for(long long i = 1; i < LOGN; i++){
        for(long long j = 0; j < N; j++){
            if(parent[i-1][j] != -1){
                parent[i][j] = parent[i-1][parent[i-1][j]];
            }
        }
    }
}

long long lca(long long u,long long v){
    long long diff = abs(depth[u] - depth[v]);
    
    if(depth[u] > depth[v]) swap(u, v);
    
    v = uplift(v, diff);
    
    if(u == v) return u;
    
    for(long long i = LOGN-1; i >= 0; i--){
        if(parent[i][u] != parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }
 
    return parent[0][u];
}
 