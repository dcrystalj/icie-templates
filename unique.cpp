/// Name: unique
/// Description: make array unique
/// Guarantee: #define uniq(ans)
#define uniq(ans) ans.resize(unique(ALL(ans)) - ans.begin())