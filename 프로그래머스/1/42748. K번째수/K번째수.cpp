#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto& A : commands)
    {
        vector<int> v(A[1] - A[0] + 1);
        copy(array.begin() + A[0] - 1, array.begin() + A[1], v.begin());
        sort(v.begin(), v.end());
        answer.push_back(v[A[2] - 1]);
    }
    
    return answer;
}