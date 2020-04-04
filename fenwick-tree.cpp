/// Name: Fenwick tree
/// Description: fenwick tree - calc sum even if you have updates between queries
/// Guarantee: void initialize(long long node, long long L, long long R) {

vector<long long> fen (n, 0);
void updateFenwick(long long p, long long val){
	for(long long i = p; i <= fen.size(); i += i & -i)
		fen[i] += val;
}

long long sumFenwick(long long p) { // sum from 0 to p
	long long ans = 0;
	for(long long i = p; i; i -= i & -i)
		ans += fen[i];
	return ans;
}