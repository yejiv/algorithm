#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);
    int score(0), zero(0);
    
    for(int i = 0 ; i < 6; ++ i) 
    {
        if (lottos[i])
        {
            for(int j = 0; j < 6; ++ j)
                if (lottos[i] == win_nums[j])
                    ++ score;
        }
        else
            ++zero;
    }     
    
    answer[0] = (score + zero >= 2) ? 7 - (score + zero) : 6;
    answer[1] = (score >= 2) ? 7 - score : 6;
    
    return answer;
}