#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> scores(3);
    int A[5] = { 1, 2, 3, 4, 5};
    int B[8] = { 2, 1, 2, 3, 2, 4, 2, 5};
    int C[5] = {3, 1, 2, 4, 5};
    int size = answers.size();
    
    for(int i = 0; i < size; ++i)
    {
        if (answers[i] == A[i % 5]) ++scores[0];
        if (answers[i] == B[i % 8]) ++scores[1];
        if (answers[i] == C[(i % 10) /  2]) ++scores[2];
    }
    
    int maxScore = max(scores[0], max(scores[1], scores[2]));
    for(int i = 0; i < 3; ++i)
        if (maxScore == scores[i])
            answer.push_back(i + 1);
    
    return answer;
}