/// Name: conversion
/// Description: Conversion bin2int, int2bin, removeLeadingZeros, reverse string, lowbit, split string
/// Guarantee: #define bin2int(bin)
void reverseStr(string& str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) swap(str[i], str[n - i - 1]);
}
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x; example: x=12;  1100 => 100 => 4
string removeLeadingZeros(string str) { return str.erase(0, min(str.find_first_not_of('0'), str.size()-1)); }
#define bin2int(bin) (bitset< 1001 >(bin).to_ulong())
#define int2bin(i) removeZeros(bitset< 1001 >( i ).to_string())

// use cin.ignore(); before reading with getline(cin, s)
// then call SPLIT_STRINGS(vs, s) to get array of splitted string s
#define SPLIT_STRINGS(vec, str) istringstream iss(str); vector<string> vec((istream_iterator<string>(iss)), istream_iterator<string>());