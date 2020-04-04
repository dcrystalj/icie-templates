/// Name: segment tree - lazy min
/// Description: Update interval and query minimum interval
/// Guarantee: long long querySegTree(long long l, long long r) {

long long N;
long long H;
vector<long long> seg;
vector<long long> lazy;
void buildSegTree(vector<long long> &v) {
    N = v.size(); 
    H = 64 - __builtin_clzll(N);
    seg.assign(2*N, 0);
    lazy.assign(N, 0);
    for (long long i = N; i < 2*N; i++) seg[i] = v[i-N];
    for (long long i = N - 1; i > 0; --i) seg[i] = min(seg[i*2], seg[(i*2)|1]);
}

void apply(long long p, long long value) {
  seg[p] += value;
  if (p < N) lazy[p] += value;
}

void build(long long p) {
  while (p > 1) p /= 2, seg[p] = min(seg[p*2], seg[(p*2)|1]) + lazy[p];
}

void push(long long p) {
  for (long long s = H; s > 0; --s) {
    long long i = p >> s;
    if (lazy[i] != 0) {
      apply(i*2, lazy[i]);
      apply((i*2)|1, lazy[i]);
      lazy[i] = 0;
    }
  }
}

void inc(long long l, long long r, long long value) {
  l += N, r += N;
  long long l0 = l, r0 = r;
  for (; l < r; l /= 2, r /= 2) {
    if (l&1) apply(l++, value);
    if (r&1) apply(--r, value);
  }
  build(l0);
  build(r0 - 1);
}

long long querySegTree(long long l, long long r) {
  l += N, r += N;
  push(l);
  push(r - 1);
  long long res = 2e9;
  for (; l < r; l /= 2, r /= 2) {
    if (l&1) res = min(res, seg[l++]);
    if (r&1) res = min(seg[--r], res);
  }
  return res;
}