#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int size = new_id.size();
    
    for (char c : new_id)
    {
        c = tolower(c);

        if (islower(c) || isdigit(c) || c == '-' || c == '_' || c == '.')
        {
            if (c == '.' && answer.empty())
                continue;
            if (c == '.' && !answer.empty() && answer.back() == '.')
                continue;
            answer += c;
        }
    }

    while (!answer.empty() && answer.back() == '.')
        answer.pop_back();
    
    if (answer.size() == 0)
        answer += 'a';
    
    while (answer.size() <=  2)
        answer += answer.back();
    
    if (answer.size() >= 16)
    {
        answer.erase(answer.begin() + 15, answer.end());
        if (answer[14] == '.')
            answer.pop_back();
    }
    
    return answer;
}