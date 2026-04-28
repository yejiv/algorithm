#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 0;
    int count = 0;

    while(idx < number.size())
    {
        while(count < k && answer.size() && answer.back() < number[idx])
        {
            answer.pop_back();
            ++ count;
        }
        answer.push_back(number[idx++]);
    }
    
    while(answer.size() > number.size() - k) answer.pop_back();
        
    return answer;
}
