#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> table;
    
    for(auto& A : clothes)
        ++ table[A[1]];
    
    for(auto& A : table)
    {
        if (0 == answer) answer = A.second + 1;
        else answer *= (A.second + 1); 
    }

    return answer - 1;
}