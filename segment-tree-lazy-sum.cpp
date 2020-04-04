/// Name: segment tree - lazy sum
/// Description: Update interval and query sum interval https://codeforces.com/blog/entry/18051
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

void calc(long long  p, long long  k) {
  if (lazy[p] == 0) seg[p] = seg[p<<1] + seg[p<<1|1];
  else seg[p] = lazy[p] * k;
}

void apply(long long  p, long long  value, long long  k) {
  seg[p] = value * k;
  if (p < N) lazy[p] = value;
}

void build(long long  l, long long  r) {
  long long  k = 2;
  for (l += N, r += N-1; l > 1; k <<= 1) {
    l >>= 1, r >>= 1;
    for (long long  i = r; i >= l; --i) calc(i, k);
  }
}

void push(long long  l, long long  r) {
  long long  s = H, k = 1 << (H-1);
  for (l += N, r += N-1; s > 0; --s, k >>= 1)
    for (long long  i = l >> s; i <= r >> s; ++i) if (lazy[i] != 0) {
      apply(i<<1, lazy[i], k);
      apply(i<<1|1, lazy[i], k);
      lazy[i] = 0;
    }
}

void modify(long long  l, long long  r, long long  value) {
  if (value == 0) return;
  push(l, l + 1);
  push(r - 1, r);
  long long  l0 = l, r0 = r, k = 1;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (l&1) apply(l++, value, k);
    if (r&1) apply(--r, value, k);
  }
  build(l0, l0 + 1);
  build(r0 - 1, r0);
}

long long  query(long long  l, long long  r) {
  push(l, l + 1);
  push(r - 1, r);
  long long  res = 0;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += seg[l++];
    if (r&1) res += seg[--r];
  }
  return res;
}