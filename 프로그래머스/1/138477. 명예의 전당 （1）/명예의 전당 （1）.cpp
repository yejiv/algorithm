#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> winner(k + 1);
    
    for(int i = 0; i < score.size(); ++i)
    {
        winner[(i < k) ? i : k] = score[i];
        sort(winner.begin(), winner.end(), greater<int>());
        answer.push_back(winner[(i < k) ? i : k - 1]);
    }
    return answer;
}