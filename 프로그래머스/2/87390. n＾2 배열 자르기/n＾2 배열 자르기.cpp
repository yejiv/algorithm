#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int start = left / n;
    int start_idx = left % n;
    int end = right / n;
    int end_idx = right % n;
    
    for(int i = start; i <= end; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int num = (i >= j) ? i + 1 : j + 1;
            if (i == start && j < left % n) continue;
            answer.push_back(num);
            if (i == end && j >= right % n) return answer;
        }
    }
    
    return answer;
}
