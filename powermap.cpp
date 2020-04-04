/// Name: powermap
/// Description: HAS, COUNTER
/// Guarantee: #define HAS(umap, key) 
#define HAS(umap, key) (umap.find(key) != umap.end())
#define COUNTER(m, j) if (HAS(m, j)) { m[j]++; } else { m[j] = 1; }