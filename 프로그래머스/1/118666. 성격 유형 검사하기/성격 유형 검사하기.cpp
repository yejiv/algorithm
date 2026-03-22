#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> table;
    int size = survey.size();
    
    table  = { {'R', 0}, {'T', 0}, {'C', 0}, {'F', 0}, {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0} };
    
    for(int i = 0; i < size; ++i)
    {
        if (choices[i] < 4)
            table[survey[i][0]] += 4 - choices[i];
        else if (choices[i] > 4)
            table[survey[i][1]] += choices[i] - 4;
    }
    
    (table['R'] >= table['T']) ? answer += "R" : answer += "T";
    (table['C'] >= table['F']) ? answer += "C" : answer += "F";
    (table['J'] >= table['M']) ? answer += "J" : answer += "M";
    (table['A'] >= table['N']) ? answer += "A" : answer += "N";
    
    return answer;
}