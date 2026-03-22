#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> table;
    int i = 0;
    
    for(auto& A : name)
        table.insert({A, yearning[i++]});

    for(auto& A : photo)
    {
        int sum = 0;
        for(auto& B : A) 
            sum += table[B];
        answer.push_back(sum);
    }
    
    return answer;
}