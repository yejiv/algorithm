#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    vector<int> num;
    
    while(storey)
    {
        num.push_back(storey % 10);
        storey /= 10;
    }
    
    num.push_back(0);
    
    for(int i = 0; i < num.size(); ++i)
    {
        if (num[i] > 5 || (num[i] == 5 && num[i + 1] >= 5))
        {
            answer += 10 - num[i];
            ++ num[i + 1];
        }
        else
            answer += num[i];
    }
    
    return answer;
}