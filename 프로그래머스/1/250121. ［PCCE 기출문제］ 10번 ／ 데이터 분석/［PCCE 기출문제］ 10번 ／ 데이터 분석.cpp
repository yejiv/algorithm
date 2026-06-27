#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    unordered_map<string, int> column_map = {{"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3}};

    int ext_idx = column_map[ext];
    int sort_idx = column_map[sort_by];

    for (const auto& d : data) 
    {
        if (d[ext_idx] < val_ext)
            answer.push_back(d);
    }

    sort(answer.begin(), answer.end(), [&](const vector<int>& a, const vector<int>& b) {
        return a[sort_idx] < b[sort_idx];
    });
        
    return answer;
}