/// Name: default-dict
/// Description: create map with get / set
/// Guarantee: struct DD {
struct DD {
    unordered_map<LL, LL> m;
    void set(LL i, LL val) { m[i] = val; }
    auto get(LL i, LL _default) {
        if (!HAS(m, i)) m[i] = _default;
        return m[i];
    }
    auto get(LL i) { return get(i, 0); }
    auto size() { return m.size(); }
};