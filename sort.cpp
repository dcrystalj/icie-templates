/// Name: multi-dimensional sort
/// Description: sort vector of vectors
/// Guarantee: bool sortm(vector<LL>& a, vector<LL>& b) {
// usage: sort(ALL(m), sortm);
bool sortm(vector<LL>& a, vector<LL>& b) {
    return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
}