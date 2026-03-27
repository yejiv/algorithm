#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_map <string, int> table;
        
    table[words[0]] ++;
    
    for (int i = 1; i < words.size(); ++i) 
        if (table[words[i]] ++ || words[i - 1].back() != words[i][0]) 
            return {(i % n) + 1, (i / n) + 1} ;
    
    return {0, 0};
}