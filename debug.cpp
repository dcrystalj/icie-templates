/// Name: debug
/// Description: inserts dd ddv ddvv to print variables
/// Guarantee: #define ddv
#define dd(var) cerr << #var << "=" << (var) << " | "
#define ddv(vec) for(auto &i: vec) { cout << i << " "; } cout << endl
#define ddvv(vec) for(auto& i:vec) { for(auto& j:i) { cout <<  j << " "; }; cout << endl }
