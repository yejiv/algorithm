#include <string>
#include <unordered_map>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, int> map1;
    unordered_map<string, int> map2;
    int total1 = 0, total2 = 0;
    int A = 0, B = 0;
    
    for(int i = 0; i < str1.size() - 1; ++i)
    {
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1])) continue;
        map1[{ (char)toupper(str1[i]), (char)toupper(str1[i+1]) }] ++;
        ++ total1;
    }
    for(int i = 0; i < str2.size() - 1; ++i)
    {
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1])) continue;
        map2[{ (char)toupper(str2[i]), (char)toupper(str2[i+1]) }] ++;
        ++ total2;
    }
    
    for(const auto & K : map1)
        if (map2.count(K.first))
            A += min(K.second, map2[K.first]);
    
    B = total1 + total2 - A;
    
    if (B == 0) return 65536;
    return (A * 65536) / B;
}