#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dictionary;
    int index = 26;
    
    for (char c = 'A'; c <= 'Z'; ++c)
        dictionary[string(1, c)] = c - 'A' + 1;
    
    for(int i = 0; i < msg.size(); )
    {
        for(int length = msg.size() - i; length > 0; --length)
        {
            if (dictionary.find(msg.substr(i, length)) != dictionary.end())
            {
                answer.push_back(dictionary[msg.substr(i, length)]);
                if (i + length + 1 < msg.size())
                    dictionary[msg.substr(i, length + 1)] = ++ index;
                i += length;
                break;
            }
        }
    }
    
    return answer;
}