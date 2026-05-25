#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int>table;
    int num = 0;
    
    for(const auto & A : s)
    {
        if (A >= '0' && A <= '9')
            num = num * 10 + (A - '0');
        else if (num)
        {
            table[num] ++;
            num = 0;
        }
    }
    
    for(const auto & A : table)
        answer.push_back(A.first);
    
    sort(answer.begin(), answer.end(), [&table](int a, int b){
       return table[a] > table[b]; //내림차순 정렬
    });
         
    return answer;
}