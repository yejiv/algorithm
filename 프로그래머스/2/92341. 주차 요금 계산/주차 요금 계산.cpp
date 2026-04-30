#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, vector<pair<int, int>>> table;
    
    for(const auto& A : records)
    {
        int number = stoi(A.substr(6, 4));
        string cmd = A.substr(11);
        int min = stoi(A.substr(0, 2)) * 60 + stoi(A.substr(3, 2));
        
        if (cmd == "IN") table[number].push_back({min, 1439});
        else table[number].back().second = min;
    }
    
    for(const auto& A : table)
    {
        int sum = 0;
        
        for(const auto& B : A.second)
            sum += B.second - B.first;

        if (sum <= fees[0]) answer.push_back(fees[1]);
        else answer.push_back(fees[1] + ((sum - fees[0] + fees[2] - 1) / fees[2]) * fees[3]);
    }
    
    return answer;
}