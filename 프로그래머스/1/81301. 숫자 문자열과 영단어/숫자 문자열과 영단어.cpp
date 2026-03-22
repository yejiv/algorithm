#include <string>
#include <vector>
#include<cctype>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    string strAnswer; 
    map<string, string>  table;
   
    table.insert({"one", "1"});
    table.insert({"two", "2"});
    table.insert({"three", "3"});
    table.insert({"four", "4"});
    table.insert({"five", "5"});
    table.insert({"six", "6"});
    table.insert({"seven", "7"});
    table.insert({"eight", "8"});
    table.insert({"nine", "9"});
    table.insert({"zero", "0"});
    
    for(int i = 0; i < s.size(); )
    {
        if (isdigit(s[i]))
            strAnswer += s[i++];
        else
        {
            string keyword;
            while(table.find(keyword) == table.end())
                keyword += s[i++];
            strAnswer += table[keyword];
        }
    }
   
    answer = stoi(strAnswer);
    
    return answer;
}