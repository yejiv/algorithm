#include <string>
#include <vector>
#include<algorithm>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    map<string, int> idx_table;
    vector<int> report_table[id_list.size()];
    
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    for(int i = 0; i < id_list.size(); ++i)
        idx_table.insert({id_list[i], i});
    
    for(auto& A : report)
    {
        stringstream S(A);
        string id = "", target = "";
        
        getline(S, id, ' ');
        getline(S, target, ' ');
        
        report_table[idx_table[target]].push_back(idx_table[id]);
    }
    
    for(int i = 0; i < id_list.size(); ++i)
        if (report_table[i].size() >= k)
            for(auto& idx : report_table[i])
                ++answer[idx];
    
    return answer;
}