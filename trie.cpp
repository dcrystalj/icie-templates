/// Name: TRIE
/// Description: builder for trie matrix, value is next row
/// Guarantee: void buildTrie(string s){
vector<vector<long long>> trie (MAX_NUMBER_OF_NODES, vector<long long>(30)); // 30 or MAX_ASCII_CODE
long long nextTrieRow = 1; //initially all numbers in x are -1
void buildTrie(string s){
	int i = 0, v = 0;
	while(i < s.size()){
		if(trie[v][s[i]] == -1)
			v = trie[v][s[i++]] = nextTrieRow++;
		else
			v = trie[v][s[i++]];
	}
}