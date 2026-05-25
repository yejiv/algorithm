#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    vector<int> S;
    
    sort(data.begin(), data.end(), [col](const vector<int> & v1, const vector<int> & v2)
    {
        if (v1[col - 1] != v2[col - 1]) return v1[col - 1] < v2[col - 1];
        return v1[0] > v2[0];
    });
    
    for(int i = row_begin - 1; i < row_end; ++i)
    {
        int sum = 0;
        for(const auto & A : data[i])
            sum += A % (i + 1);
        S.push_back(sum);
    }
    
    for(const auto & A : S)
        answer ^= A;
        
    return answer;
}