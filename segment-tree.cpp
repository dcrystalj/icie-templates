/// Name: segment tree
/// Description: build segment tree for sum https://codeforces.com/blog/entry/18051
/// Guarantee: long long queryIntervalSegTree(long long l, long long r) {

long long N;
vector<long long> seg;
void buildSegTree(vector<long long> &v) {  // build the tree
    N = v.size(); seg.assign(2*N, 0);
    for (long long i = N; i < 2*N; i++) seg[i] = v[i-N];
    for (long long i = N - 1; i > 0; --i) seg[i] = seg[i*2] + seg[(i*2)|1];
}

void modifySegTree(long long p, long long value) {  // set value at position p
  for (seg[p += N] = value; p > 1; p /= 2) seg[p/2] = seg[p] + seg[p^1];
}

long long queryIntervalSegTree(long long l, long long r) {  // sum on interval [l, r)
  int res = 0;
  for (l += N, r += N; l < r; l /= 2, r /= 2) {
    if (l&1) res += seg[l++];
    if (r&1) res += seg[--r];
  }
  return res;
}