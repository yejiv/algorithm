#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int LH = 10, RH = 12;
    bool isRightHand = ("right" == hand) ? true : false;
    
    for(auto & num : numbers)
    {
        if (num == 2 || num == 5 || num == 8 || num == 0)
        {
            int target = (num == 0) ? 11 : num;
            int LD = (abs(LH - target) / 3) + (abs(LH - target) % 3);
            int RD = (abs(RH - target) / 3) + (abs(RH - target) % 3);
            if (LD > RD || (LD == RD && isRightHand))
            {
                answer += 'R'; RH = target;
            }
            else if (LD < RD || (LD == RD && !isRightHand))
            {
                answer += 'L'; LH = target;
            }   
        }
        else if (num == 1 || num == 4 || num == 7)
        {
            answer += 'L'; LH = num;
        }
        else
        {
            answer += 'R'; RH = num; 
        }
    }
    
    return answer;
}