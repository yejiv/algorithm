#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, -1);
    
    int start = 0;
    int end = 0;
    int sum = sequence[0];
    
    while(end < sequence.size())
    {
        if (sum == k)
        {
            if(answer[0] < 0 || answer[1] - answer[0] > end - start)
            {
                answer[0] = start;
                answer[1] = end;
            }
        }
        if (sum <= k)
        {
            if (end + 1 < sequence.size())
                sum += sequence[end + 1];
            ++ end;
        }
        else
        {
            sum -= sequence[start];
            ++ start;
        }
    }
    
    return answer;
}