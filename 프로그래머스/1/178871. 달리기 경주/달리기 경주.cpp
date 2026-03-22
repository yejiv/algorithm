#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> table;
    int i = 0;
    
    for(auto& A : players)
    {
        table.insert({A, i++});
        answer.push_back(A);
    }
    
    for(auto& A : callings)
    {
        int idx = table[A] --;
        int idx2 = table[answer[idx- 1]] ++;
        swap(answer[idx], answer[idx2]);
    }
    
    return answer;
}