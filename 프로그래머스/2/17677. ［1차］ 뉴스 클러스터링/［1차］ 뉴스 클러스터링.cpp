#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, int> map1;
    unordered_map<string, int> map2;
    unordered_map<string, int> U;
    int A = 0;
    int B = 0;
    
    for(int i = 0; i < str1.size() - 1; ++i)
    {
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1])) continue;
        map1[{ (char)toupper(str1[i]), (char)toupper(str1[i+1]) }] ++;
    }
    for(int i = 0; i < str2.size() - 1; ++i)
    {
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1])) continue;
        map2[{ (char)toupper(str2[i]), (char)toupper(str2[i+1]) }] ++;
    }
    
    for(const auto & K : map1)
        U[K.first] = max(K.second, map2[K.first]);
    for(const auto & K : map2)
        U[K.first] = max(K.second, map1[K.first]);
    for(const auto & K : U)
        B += K.second;
    
    unordered_map<string, int> & s = (map1.size() > map2.size()) ? map2 : map1;
    unordered_map<string, int> & d = (map1.size() > map2.size()) ? map1 : map2;
    
    for(const auto & K : s)
        if (d[K.first] > 0)
            A += min(K.second, d[K.first]);
    
    if (A == 0 && B == 0) return 65536;
    return (A * 65536) / B;
}