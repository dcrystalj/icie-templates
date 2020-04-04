/// Name: RMQ - range minum query
/// Description: build sparse table and query function for minum; https://www.topcoder.com/community/competitive-programming/tutorials/range-minimum-query-and-lowest-common-ancestor/
/// Guarantee: vector<vector<LL>> rmq(vector<LL> & v) {
vector<vector<LL>> rmq(vector<LL> & v) {
{
    long long i, j, n, left, right;
    n = v.size();
    // M == sparse table
    vector<vector<LL>> M (n, vector<LL>((long long)log2(n))); // int M[MAXN][LOGMAXN], int A[MAXN]

    for (i = 0; i < n; i++) M[i][0] = i; //initialize M for the intervals with length 1
    for (j = 1; 1 << j <= n; j++) { // (1 << j) == interval size (2^j)
        for (i = 0; i + (1 << j) - 1 < n; i++) { // iterate over interval
            left = M[i][j - 1];
            right = M[i + (1 << (j - 1))][j - 1]; 
            M[i][j] = v[left] < v[right] ? left : right;
        }
    }
    return M;
}

// Returns minimum of arr[L..R] 
long long query(vector<LL> & v, vector<vector<LL>> M, long long L, long long R) { 
    // For [2,10], j = 3 
    long long j = (long long)log2(R-L+1); 
  
    // For [2,10], we compare v[M[0][3]] and 
    // v[M[3][3]],  
    if (v[M[L][j]] <= v[M[R - (1<<j) + 1][j]]) 
        return v[M[L][j]]; 
  
   else return v[M[R - (1<<j) + 1][j]]; 
} 