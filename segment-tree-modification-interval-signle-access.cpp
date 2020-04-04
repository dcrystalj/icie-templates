/// Name: segment tree
/// Description: interval modification query single element https://codeforces.com/blog/entry/18051
/// Guarantee: long long querySingleSegTree(long long p) {
/// Dependencies: segment-tree
void modifyIntervalSegTree(long long l, long long r, long long value) {
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l&1) seg[l++] += value;
    if (r&1) seg[--r] += value;
  }
}

long long querySingleSegTree(long long p) {
  long long res = 0;
  for (p += N; p > 0; p >>= 1) res += seg[p];
  return res;
}

void pushSegTree() { // use this before you print all elements
  for (long long i = 1; i < N; ++i) {
    seg[i<<1] += seg[i];
    seg[i<<1|1] += seg[i];
    seg[i] = 0;
  }
}