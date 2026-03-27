#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    unordered_map <string, int> table;
    int idx = 0;
    
    answer[0] = answer[1] = 0; 
    
    table[words[0]] ++;
    
    for (int i = 1; i < words.size(); ++i)
    {
        if (table[words[i]] ++ || words[i - 1].back() != words[i][0])
            { idx = i; break; }
    }
    
    if (idx)
    { 
        answer[0] = (idx % n) + 1;
        answer[1] = (idx / n) + 1;
    }
    
    return answer;
}