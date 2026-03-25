#include <string>
#include <vector>
#include <sstream>

using namespace std;


string solution(string s) {
    string answer = "";
    int max(0), min(0);    
    string buffer;
    stringstream ss(s);
    
    getline(ss, buffer, ' ');
    max = min = stoi(buffer);
    
    while(getline(ss, buffer, ' '))
    {
        int num = stoi(buffer);
        if (num > max) max = num;
        if (num < min) min = num;
    }
    
    answer += to_string(min) + ' ' + to_string(max);
    
    return answer;
}