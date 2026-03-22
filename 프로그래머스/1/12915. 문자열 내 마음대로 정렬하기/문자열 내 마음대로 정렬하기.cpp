#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    multimap<char, string> table;
    
    sort(strings.begin(), strings.end());
    
    for(auto& A : strings)
        table.insert({A[n], A});
        
    for(auto& A : table)
        answer.push_back(A.second);
    
    return answer;
}