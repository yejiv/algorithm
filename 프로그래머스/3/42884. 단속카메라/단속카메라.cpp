#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    vector<pair<int, int>> table;
    
    sort(routes.begin(), routes.end());
    
    for(const auto & A : routes)
    {
        bool flag = false;
        for(auto & B : table)
        {
            if (B.first <= A[1] && B.second >= A[0])
            {
                B.first = max(A[0], B.first);
                B.second = min(A[1], B.second);
                flag = true;
                break;
            }
        }
        if (!flag)  table.push_back({A[0], A[1]});
    }
    return table.size();
}