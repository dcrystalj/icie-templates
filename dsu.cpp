/// Name: DSU - union find
/// Description: Find & Union for disjoint set
/// Guarantee: long long dsuRoot {
vector<long long> parent;  // (n, -1)
vector<long long> weight; // (n, 0);
long long dsuRoot(long long i) { return parent[i] == -1 ? i : (parent[i] = dsuRoot(parent[i])); }
bool dsuUnion(long long a, long long b) {
   a = dsuRoot(a), b = dsuRoot(b);
   if (a == b) return false;
   if (weight[a] < weight[b]) swap(a, b);
   if (weight[a] == weight[b]) ++weight[a];
   parent[b] = a;
   return true;
}