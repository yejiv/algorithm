#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> table;
    vector<pair<string, int>> print;
    string info[2] = {"님이 들어왔습니다.", "님이 나갔습니다."};

    answer.reserve(record.size());
    print.reserve(record.size());
    
    for(auto& s : record)
    {
        string split[3] = {"", "", ""};
        int i = 0;
        
        for(auto& c : s)
        {
            if (c == ' ') { ++i; continue; } 
            split[i] += c;
        }
        
        if (split[0] != "Leave") table[split[1]] = split[2];
        if (split[0] == "Enter") print.push_back({split[1], 0});
        else if (split[0] == "Leave") print.push_back({split[1], 1});
    }
    
    for(auto& s : print)  answer.push_back(table[s.first] + info[s.second]); 
    
    return answer;
}