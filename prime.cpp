/// Name: is_prime
/// Description: check if is prime number
/// Guarantee: bool is_prime(long long x) {
bool is_prime(long long x) {
	for (long long i=2; i * i <= x; i++) if (x % i == 0) return false;
	return true;
}